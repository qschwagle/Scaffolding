#pragma once

#include<string>
#include<ostream>

class Parameter {
public:

    Parameter(std::string id, std::string type) : mId{id}, mType{type} {}
    Parameter(const Parameter&)=delete;
    Parameter& operator=(const Parameter&)=delete;

    void Write(std::ostream& out);
private:
    std::string mId;
    std::string mType;
};
// vim:set sw=4 ts=4 et:
