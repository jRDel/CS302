#include <stdexcept>
#include <string>

#include "PrecondViolatedExcept.h"
using namespace std;

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
: std::logic_error("Precondition Violated Exception: " + message)
{
}