/**
 * \file Constructor.hpp
 * \author Quinton Schwagle
 */
#pragma once

#include "Constructor.hpp"

class CppClass;

/**
 * \brief Corresponds to a default constructor of a class
 */
class DefaultConstructor : public Constructor {
public:
    /** initializes with the class which it belongs 
     *  \param owner owner class
     */
    DefaultConstructor(std::weak_ptr<CppClass> owner) : Constructor(owner) {}

    /** copy constructor deleted */
    DefaultConstructor(const DefaultConstructor&)=delete;

    /** assignment operator deleted */
    DefaultConstructor& operator=(const DefaultConstructor&)=delete;

    void Write(std::ostream& out, const std::string& spaces) override;
private:
};
// vim:set sw=4 ts=4 et:
