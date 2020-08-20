#include"IncludeMacro.hpp"

void IncludeMacro::Write(std::ostream& out, const std::string& spaces)
{
    out << "#include \"" << mPath << "\"";
}
// vim:set sw=4 ts=4 et:
