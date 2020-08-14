#pragma once

#include<ostream>

class FunctionDefinition {
public:
    FunctionDefinition()=default;
    FunctionDefinition(const FunctionDefinition&)=delete;
    FunctionDefinition& operator=(const FunctionDefinition&)=delete;

    void SetBody(std::string body)
    {
        mBody = body;
    }

    std::string GetBody(void) const
    {
        return mBody;
    }

    void Write(std::ostream& out);
private:

    std::string mBody;
};
// vim:set sw=4 ts=4 et:
