#include"Function.hpp"

#include "Parameter.hpp"
#include "FunctionDefinition.hpp"

void Function::AddParameter(std::shared_ptr<Parameter> param)
{
    mParameters.push_back(param);
}


void Function::Write(std::ostream& out, const std::string& spaces)
{
    out << spaces << mRetType << " " << mId << "(";
    for(auto p = mParameters.cbegin(); p != mParameters.cend(); p++)
    {
        (*p)->Write(out);
        if(p+1 != mParameters.cend())
        {
            out << ", ";
        }
    }
    out << ")\n";
    GetDefinition()->Write(out);
}

// vim:set sw=4 ts=4 et:
