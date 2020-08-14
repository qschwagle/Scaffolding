#include"DefaultConstructor.hpp"

#include "CppClass.hpp"

/**
 * writes the constructor to class using spaces for indentation
 * \param out output stream
 * \param spaces indentation
 */
void DefaultConstructor::Write(std::ostream& out, const std::string& spaces)
{
    std::shared_ptr<CppClass> owner = GetOwner().lock();
    out << spaces << owner->GetClassName() << "(void)=default;";
}

// vim:set sw=4 ts=4 et:
