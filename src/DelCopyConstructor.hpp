#pragma once

#include "Constructor.hpp"

class CppClass;

class DelCopyConstructor : public Constructor {
public:
    DelCopyConstructor(std::weak_ptr<CppClass> owner) : Constructor(owner) {}
    DelCopyConstructor(const DelCopyConstructor&)=delete;
    DelCopyConstructor& operator=(const DelCopyConstructor&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;
private:
};
// vim:set sw=4 ts=4 et:
