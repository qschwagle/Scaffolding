cmake_minimum_required(VERSION 3.10)

project(SCAFFOLD)


add_executable(scaffold 
	src/main.cpp 
	src/Function.cpp 
	src/Element.cpp 
	src/CppFile.cpp 
	src/Parameter.cpp 
	src/FunctionDefinition.cpp 
	src/Comment.cpp 
	src/IncludeMacro.cpp 
	src/CppClass.cpp
	src/PragmaOnce.cpp
	src/Constructor.cpp
	src/DefaultConstructor.cpp
	src/DelCopyConstructor.cpp
	src/DelAssignOp.cpp
	)
set_property(TARGET scaffold PROPERTY CXX_STANDARD 17)
