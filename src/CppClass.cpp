#include"CppClass.hpp"

void CppClass::Write(std::ostream& out, const std::string& spaces)
{
    out << spaces << "class " << mName << " {\n";
    const std::string tabbed = spaces + "    ";

    out << spaces << "public:\n";
    if(mPublicElements.size() != 0)
    {
        for(const auto& e: mPublicElements)
        {
            e->Write(out, tabbed);
            out << "\n";
        }
    }

    out << spaces << "private:\n";
    if(mPrivateElements.size() != 0)
    {
        for(const auto& e: mPrivateElements)
        {
            e->Write(out, tabbed);
            out << "\n";
        }
    }

    out << spaces << "protected:\n";
    if(mProtectedElements.size() != 0)
    {
        for(const auto& e: mProtectedElements)
        {
            e->Write(out, tabbed);
            out << "\n";
        }
    }
    out << spaces << "};";
}

void CppClass::AddPublicElement(std::shared_ptr<Element> e)
{
    mPublicElements.push_back(e);
}

void CppClass::AddPrivateElement(std::shared_ptr<Element> e)
{
    mPrivateElements.push_back(e);
}

void CppClass::AddProtectedElement(std::shared_ptr<Element> e)
{
    mProtectedElements.push_back(e);
}

// vim:set sw=4 ts=4 et:
