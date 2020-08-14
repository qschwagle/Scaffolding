/**
 * \file CppFile.hpp
 * \author Quinton Schwagle
 * \brief CppFile represents a C++ document consisting of a list of elements
 */

#pragma once

#include<memory>
#include<vector>
#include<string>

class Element;

/**
 * \brief Represents a CPP File
 *
 * CppFile represents any cpp file whether header or compilation unit
 */
class CppFile {
public:

    /** Constructor using a fileName for the given file
     *  \param fileName name of the file being created
     */
    CppFile(const std::string fileName) : mFileName{fileName} {}

    /** Files should exist uniquely. Copy Constructor deleted  */
    CppFile(const CppFile&)=delete;

    /** Files should exist uniquely. Assignment Operator deleted */
    CppFile& operator=(const CppFile&)=delete;

    void AddElement(std::shared_ptr<Element> element);

    /**
     * Set the filename 
     * \param fileName file name
     */
    void SetFileName(std::string fileName)
    {
        mFileName = fileName;
    }

    /**
     * Get the filename 
     * \returns current file name
     */
    std::string GetFileName(void) const
    {
        return mFileName;
    }

    void Write(void);
private:
    /// file name of CppFile
    std::string mFileName;

    /// elements linked to file
    std::vector<std::shared_ptr<Element>> mElements;
};
// vim:set sw=4 ts=4 et:
