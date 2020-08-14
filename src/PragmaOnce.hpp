#pragma once

#include "Element.hpp"

class PragmaOnce : public Element {
public:
    PragmaOnce()=default;
    PragmaOnce(const PragmaOnce&)=delete;
    PragmaOnce& operator=(const PragmaOnce&)=delete;


    void Write(std::ostream& out, const std::string& spaces) override;
private:
};
// vim:set sw=4 ts=4 et:
