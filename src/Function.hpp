#pragma once

#include "Element.hpp"

#include <vector>
#include <memory>
#include <string>
#include <ostream>

class Parameter;

class FunctionDefinition;

class Function : public Element {
public:
    Function(const std::string id) : mId { id } {}
    Function(const Function&)=delete;
    Function& operator=(const Function&)=delete;

    void AddParameter(std::shared_ptr<Parameter> param);

    std::string GetIdentifier(void) const 
    {
        return mId;
    }

    void SetIdentifier(std::string id)
    {
        mId = id;
    }

    void SetDefinition(std::shared_ptr<FunctionDefinition> def)
    {
        mDefinition = def;
    }

    void SetReturnType(std::string retType)
    {
        mRetType = retType;
    }

    std::string GetReturnType(void) const
    {
        return mRetType;
    }

    std::shared_ptr<FunctionDefinition> GetDefinition(void)
    {
        return mDefinition;
    }

    void Write(std::ostream& out, const std::string& spaces) override;
private:

    std::string mId;

    std::string mRetType;

    std::shared_ptr<FunctionDefinition> mDefinition;

    std::vector<std::shared_ptr<Parameter>> mParameters;
};
// vim:set sw=4 ts=4 et:
