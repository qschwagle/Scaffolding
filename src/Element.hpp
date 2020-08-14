#pragma once

#include<ostream>
#include<string>

class Element {
public:
    Element()=default;
    Element(const Element&)=delete;
    Element& operator=(const Element&)=delete;

    virtual void Write(std::ostream& out, const std::string& spaces);
private:
};
// vim:set sw=4 ts=4 et:
