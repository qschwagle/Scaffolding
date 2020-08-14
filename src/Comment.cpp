#include"Comment.hpp"

void Comment::Write(std::ostream& out, const std::string& spaces)
{
    out << spaces << "// " << mMessage;
}
// vim:set sw=4 ts=4 et:
