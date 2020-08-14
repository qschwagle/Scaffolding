#pragma once

#include "Element.hpp"

class IncludeMacro : public Element {
public:
    IncludeMacro(std::string path) : mPath{path} {}
    IncludeMacro(const IncludeMacro&)=delete;
    IncludeMacro& operator=(const IncludeMacro&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;


private:

    std::string mPath;
};
// vim:set sw=4 ts=4 et:
