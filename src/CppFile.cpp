#include"CppFile.hpp"

#include "Element.hpp"

#include<fstream>
#include<iostream>

void CppFile::AddElement(std::shared_ptr<Element> element)
{
    mElements.push_back(element);
}


void CppFile::Write(void)
{
    std::fstream out;
    out.open(mFileName, std::ios_base::out);
    std::string spaces;
    if(out.is_open())
    {
        for(const auto& e: mElements)
        {
            e->Write(out, spaces);
            out << "\n";
        }
    } 
    else 
    {
        std::cerr << "Error opening file: " << mFileName << std::endl;
    }
}
// vim:set sw=4 ts=4 et:
