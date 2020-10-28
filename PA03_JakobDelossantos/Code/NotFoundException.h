#ifndef PRECOND_VIOLATED_EXCEP_
#define PRECOND_VIOLATED_EXCEP_

#include <stdexcept>
#include <string>

/** @class NotFoundException NotFoundException.h "NotFoundException.h"
 *
 *  Specification for an object thrown on violation of not found */
class NotFoundException : public std::logic_error {
public:
    explicit NotFoundException(const std::string& message = "The entry was not found.");
    
    virtual ~NotFoundException() noexcept = default; //throw();
};

//#include "NotFoundException.cpp"
#endif