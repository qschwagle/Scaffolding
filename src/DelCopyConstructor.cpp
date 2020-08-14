#include"DelCopyConstructor.hpp"

#include "CppClass.hpp"

void DelCopyConstructor::Write(std::ostream& out, const std::string& spaces)
{
    std::shared_ptr<CppClass> owner = GetOwner().lock();
    out << spaces << owner->GetClassName() << "(const " << owner->GetClassName() << "&)=delete;";
}
// vim:set sw=4 ts=4 et:
