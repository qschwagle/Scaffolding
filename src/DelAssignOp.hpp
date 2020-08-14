#pragma once

#include "Constructor.hpp"

class CppClass;

class DelAssignOp : public Constructor {
public:
    DelAssignOp(std::weak_ptr<CppClass> owner) : Constructor(owner) {}
    DelAssignOp(const DelAssignOp&)=delete;
    DelAssignOp& operator=(const DelAssignOp&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;
private:
};
// vim:set sw=4 ts=4 et:
