#include"FunctionDefinition.hpp"

void FunctionDefinition::Write(std::ostream& out)
{
    out << "{\n";
    if(mBody.size() != 0) {
        out << mBody << "\n";
    }
    out << "}";
}
// vim:set sw=4 ts=4 et:
