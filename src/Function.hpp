/**
 * \file Function.hpp
 * \author Quinton Schwagle
 * \brief Function Element corresponding to function and methods
 */
#pragma once

#include "Element.hpp"

#include <vector>
#include <memory>
#include <string>
#include <ostream>

class Parameter;

class FunctionDefinition;

/**
 * \brief Function represents a C++ function or class method
 */
class Function : public Element {
public:
    /** Constructor for function with an identifier */
    Function(const std::string id) : mId { id } {}

    /** Functions should be unique. Copy Constructor Deleted */
    Function(const Function&)=delete;

    /** Functions should be unique. Assignment Operator Deleted */
    Function& operator=(const Function&)=delete;

    void AddParameter(std::shared_ptr<Parameter> param);

    /**
     * retrieves the function identifier
     * \returns copy of identifier
     */
    std::string GetIdentifier(void) const 
    {
        return mId;
    }

    /**
     * Sets the function identifier
     * \param id new identifier for function
     */
    void SetIdentifier(std::string id)
    {
        mId = id;
    }

    /**
     * sets the defintion of the function
     * \param def new definition for the function
     */
    void SetDefinition(std::shared_ptr<FunctionDefinition> def)
    {
        mDefinition = def;
    }

    /**
     * sets the return type of the function
     * \param retType new return type
     */
    void SetReturnType(std::string retType)
    {
        mRetType = retType;
    }

    /**
     * get the current return type of the function
     * \returns the return type
     */
    std::string GetReturnType(void) const
    {
        return mRetType;
    }

    /**
     * get the definition of the function
     * \returns function definition
     */
    std::shared_ptr<FunctionDefinition> GetDefinition(void)
    {
        return mDefinition;
    }

    void Write(std::ostream& out, const std::string& spaces) override;
private:

    /// function c++ identifier
    std::string mId;

    /// function return type
    std::string mRetType;

    /// function definition
    std::shared_ptr<FunctionDefinition> mDefinition;

    /// parameter list for the function
    std::vector<std::shared_ptr<Parameter>> mParameters;
};
// vim:set sw=4 ts=4 et:
