#pragma once

#include "Element.hpp"

class Comment : public Element {
public:
    Comment(std::string message) : mMessage{message} {}
    Comment(const Comment&)=delete;
    Comment& operator=(const Comment&)=delete;
    void Write(std::ostream& out, const std::string& spaces) override;

private:

    std::string mMessage;
};
// vim:set sw=4 ts=4 et:
