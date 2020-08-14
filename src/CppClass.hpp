#pragma once

#include <memory>
#include <vector>
#include <ostream>
#include <string>

#include "Element.hpp"

class CppClass : public Element {
public:
    CppClass(std::string className): mName{className} {}
    CppClass(const CppClass&)=delete;
    CppClass& operator=(const CppClass&)=delete;

    void AddPublicElement(std::shared_ptr<Element> e);
    void AddPrivateElement(std::shared_ptr<Element> e);
    void AddProtectedElement(std::shared_ptr<Element> e);

    void Write(std::ostream& out, const std::string& spaces) override;

    std::string GetClassName(void) const
    {
        return mName;
    }
    
private:

    std::string mName;

    std::vector<std::shared_ptr<Element>> mPublicElements;
    std::vector<std::shared_ptr<Element>> mPrivateElements;
    std::vector<std::shared_ptr<Element>> mProtectedElements;

};
// vim:set sw=4 ts=4 et:
