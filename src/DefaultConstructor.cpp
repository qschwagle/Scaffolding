#include"DefaultConstructor.hpp"

#include "CppClass.hpp"

void DefaultConstructor::Write(std::ostream& out, const std::string& spaces)
{
    std::shared_ptr<CppClass> owner = GetOwner().lock();
    out << spaces << owner->GetClassName() << "(void)=default;";
}

// vim:set sw=4 ts=4 et:
