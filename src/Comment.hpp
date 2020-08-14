#pragma once

#include "Element.hpp"

/**
 * \brief Single line C++ Comment
 */
class Comment : public Element {
public:
    /** Constructor with comment message */
    Comment(std::string message) : mMessage{message} {}

    /** Elements are unique. Copy Constructor Deleted */
    Comment(const Comment&)=delete;

    /** Elements are unique. Assignment Operator Deleted */
    Comment& operator=(const Comment&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;
private:
    /// comment message
    std::string mMessage;
};
// vim:set sw=4 ts=4 et:
