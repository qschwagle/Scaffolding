#pragma once

#include "Constructor.hpp"

class CppClass;

class DefaultConstructor : public Constructor {
public:
    DefaultConstructor(std::weak_ptr<CppClass> owner) : Constructor(owner) {}
    DefaultConstructor(const DefaultConstructor&)=delete;
    DefaultConstructor& operator=(const DefaultConstructor&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;
private:
};
// vim:set sw=4 ts=4 et:
