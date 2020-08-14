#include"Comment.hpp"

/**
 * Writes comment to out stream
 * \param out output stream
 * \param spaces for indentation
 */
void Comment::Write(std::ostream& out, const std::string& spaces)
{
    out << spaces << "// " << mMessage;
}
// vim:set sw=4 ts=4 et:
