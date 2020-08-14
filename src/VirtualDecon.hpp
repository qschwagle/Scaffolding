#pragma once

#include "Element.hpp"

class CppClass;

class VirtualDecon : public Element {
public:
    VirtualDecon(std::weak_ptr<CppClass> owner) : mOwner{owner} 
    VirtualDecon(const VirtualDecon&)=delete;
    VirtualDecon& operator=(const VirtualDecon&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;
private:
    std::weak_ptr<CppClass> mOwner;
};
// vim:set sw=4 ts=4 et:
