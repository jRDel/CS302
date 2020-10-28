#ifndef PRECOND_VIOLATED_EXCEPT_
#define PRECOND_VIOLATED_EXCEPT_

#include <stdexcept>
#include <string>

/** PrecondViolatedExcept PrecondViolatedExcept.h "PrecondViolatedExcept.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class PrecondViolatedExcept : public std::logic_error 
{
public:
    PrecondViolatedExcept(const std::string& message = "There is no root.");
};

//#include "PrecondViolatedExcept.cpp"
#endif