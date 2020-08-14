#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<functional>
#include<cctype>
#include"CppFile.hpp"
#include"Function.hpp"
#include"Parameter.hpp"
#include"FunctionDefinition.hpp"
#include"Comment.hpp"
#include"IncludeMacro.hpp"
#include"PragmaOnce.hpp"
#include"CppClass.hpp"
#include"Constructor.hpp"
#include"DefaultConstructor.hpp"
#include"DelCopyConstructor.hpp"
#include"DelAssignOp.hpp"

void create_simple(std::string fileName)
{
    auto func = std::make_shared<Function>("main");
    auto argc = std::make_shared<Parameter>("argc", "int");
    auto argv = std::make_shared<Parameter>("argv", "char**");
    func->AddParameter(argc);
    func->AddParameter(argv);
    auto def = std::make_shared<FunctionDefinition>();
    func->SetDefinition(def);
    func->SetReturnType("int");
    CppFile file{fileName};
    auto inc = std::make_shared<IncludeMacro>("iostream");
    file.AddElement(inc);
    file.AddElement(func);
    auto com = std::make_shared<Comment>("vim:set sw=4 ts=4 et:");
    file.AddElement(com);
    file.Write();
}

void create_class(
        std::string className,
        const bool deleteCopyConstructor,
        const bool virtualDecon
        )
{
    const std::string headerFileName = className + ".hpp";
    const std::string bodyFileName = className + ".cpp";


    CppFile header{headerFileName};
    auto prag = std::make_shared<PragmaOnce>();
    auto klass = std::make_shared<CppClass>(className);
    header.AddElement(prag);
    header.AddElement(klass);
    if(deleteCopyConstructor)
    {
        auto defCon = std::make_shared<DefaultConstructor>(klass);
        auto delCC = std::make_shared<DelCopyConstructor>(klass);
        auto delAO = std::make_shared<DelAssignOp>(klass);
        klass->AddPublicElement(defCon);
        klass->AddPublicElement(delCC);
        klass->AddPublicElement(delAO);
    }
    if(virtualDecon)
    {
    }
    auto com = std::make_shared<Comment>("vim:set sw=4 ts=4 et:");
    header.AddElement(com);
    header.Write();


    CppFile body{bodyFileName};
    auto inc = std::make_shared<IncludeMacro>(headerFileName);
    body.AddElement(inc);
    body.AddElement(com);
    body.Write();
}

const std::string vim_line = "// vim:set sw=4 ts=4 et:\n";

std::string header_generator(
        const std::string& class_name, 
        const bool delete_copy_constructor,
        const bool virtual_decon)
{
    std::stringstream oss;
    oss << "#pragma once\n\n";
    oss << "class " << class_name << " {\n";
    oss << "public:\n";
    if(delete_copy_constructor) {
        oss << "    " << class_name << "()=default;\n";
        oss << "    " << class_name << "(const " << class_name << "&)=delete;\n";
        oss << "    " << class_name << "& operator=(const " << class_name << "&)=delete;\n";
    }
    if(virtual_decon) {
        oss << "    ~" << class_name << "(void);\n";
    }
    oss << "private:\n";
    oss << "};\n";
    oss << vim_line;
    return oss.str();
}

std::string definition_generator(
        const std::string& header_file_name, 
        const std::string& class_name,
        const bool virtual_decon)
{
    std::stringstream oss;
    oss << "#include\"" << header_file_name << "\"\n\n";
    if(virtual_decon) {
        oss << class_name << "::~" << class_name << "(void)\n" << "{\n}\n";
    }
    oss << vim_line;
    return oss.str();
}

const std::string message = 
"please provide a filename";

const std::string file_error =
"error generating file";

const std::string version = "0.0.1";

const std::string version_switch{"--version"};
const std::string version_switch_short{"-v"};
const std::string header_switch{"--header"};
const std::string class_switch{"--class"};
const std::string delete_copy_constructor_switch{"--no-copy"};
const std::string virtual_decon_switch{"--decon"};

class State {
public:
    bool show_version{false};
    bool class_gen{false};
    bool header_gen{false};
    bool delete_copy_constructor{false};
    bool virtual_decon{false};

    std::string value;
};

void version_switch_callback(State& state)
{
    state.show_version = true;
}

void header_switch_callback(State& state)
{
    state.header_gen = true;
}

void class_switch_callback(State& state)
{
    state.class_gen = true;
}

void delete_copy_constructor_switch_callback(State& state)
{
    state.delete_copy_constructor = true;
}

void virtual_decon_switch_callback(State& state)
{
    state.virtual_decon = true;
}

bool check_file_name(const std::string& candidate)
{
    if(candidate.size() == 0) {
        return false;
    } else {
        if(!(isalnum(candidate[0]))) {
            return false;
        }
    }
    for(const char& c: candidate)
    {
        if(!(isalnum(c) || c == '.' || c == '-'))
        {
            return false;
        }
    }
    return true;
}


int main(int argc, char** argv)
{
    std::unordered_map<std::string, std::function<void(State&)>> switches;
    switches[version_switch] = version_switch_callback;
    switches[version_switch_short] = version_switch_callback;
    switches[header_switch] = header_switch_callback;
    switches[class_switch] = class_switch_callback;
    switches[delete_copy_constructor_switch] = delete_copy_constructor_switch_callback;
    switches[virtual_decon_switch] = virtual_decon_switch_callback;

    // process arguments
    if(argc < 2) {
        std::cout << message << std::endl;
        exit(EXIT_SUCCESS);
    } 

    State state;

    for(int i = 1; i < argc; ++i) {
        std::string t = argv[i];
        auto f = switches.find(t);
        if(f != switches.end()) {
            f->second(state);
        } else {
            if(i != argc-1) {
                std::cout << "Unknown argument passed: " << argv[i] << std::endl;
                exit(EXIT_SUCCESS);
            } else {
                state.value = argv[i];
            }
        }
    }

    if(state.show_version) {
        std::cout << version << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::string last_arg{state.value};
    std::string header_name = last_arg + ".hpp";
    std::string body_name = last_arg + ".cpp";
    if(state.class_gen) {
    //    std::ofstream head{header_name};
    //    std::ofstream body{body_name};
    //    if(head.good() && body.good()) {
    //        head << header_generator(last_arg, state.delete_copy_constructor, state.virtual_decon);
    //        body << definition_generator(header_name, last_arg, state.virtual_decon);
    //        head.close();
    //        body.close();
    //    } else {
    //        std::cout << "error opening " + last_arg + ".hpp" + " or " + last_arg + ".cpp" << std::endl;
    //    }
        create_class(last_arg, state.delete_copy_constructor, state.virtual_decon);
    } else if(state.header_gen) {
        std::ofstream head{header_name};
        if(head.good()) {
            head << header_generator(last_arg, state.delete_copy_constructor, false);
            head.close();
        } else {
            std::cout << "error opening " + last_arg + ".hpp" << std::endl;
        }
    } else {
        //if(!check_file_name(last_arg)) {
        //    std::cout << "the filename's first character should be alphanumeric and the other characters should be alphanumeric, period, or dash" << std::endl;
        //    exit(EXIT_SUCCESS);
        //}
        create_simple(last_arg);
    }
}
// vim:set sw=4 ts=4 et:
