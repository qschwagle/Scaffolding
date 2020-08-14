#pragma once

#include<memory>
#include<vector>
#include<string>

class Element;

class CppFile {
public:

    CppFile(const std::string fileName) : mFileName{fileName} {}
    CppFile(const CppFile&)=delete;
    CppFile& operator=(const CppFile&)=delete;

    void AddElement(std::shared_ptr<Element> element);

    void SetFileName(std::string fileName)
    {
        mFileName = fileName;
    }

    std::string GetFileName(void) const
    {
        return mFileName;
    }

    void Write(void);
private:
    std::string mFileName;
    std::vector<std::shared_ptr<Element>> mElements;
};
// vim:set sw=4 ts=4 et:
