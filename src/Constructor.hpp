#pragma once

#include <memory>

#include "Element.hpp"

class CppClass;

class Constructor : public Element {
public:
    Constructor(std::weak_ptr<CppClass> owner) : mOwner{owner} {}
    Constructor(const Constructor&)=delete;
    Constructor& operator=(const Constructor&)=delete;

    std::weak_ptr<CppClass> GetOwner(void) const
    {
        return mOwner;
    }

    void Write(std::ostream& out, const std::string& spaces) override;
private:
    std::weak_ptr<CppClass> mOwner;
};
// vim:set sw=4 ts=4 et:
