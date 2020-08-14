#include"Parameter.hpp"

void Parameter::Write(std::ostream& out)
{
    out << mType << " " << mId;
}
// vim:set sw=4 ts=4 et:
