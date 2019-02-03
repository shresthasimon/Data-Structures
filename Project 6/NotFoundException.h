

#ifndef NOTFOUND_EXCEP_
#define NOTFOUND_EXCEP_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
    NotFoundException(const std::string& message = "")
            : std::logic_error("Not Found Exception: " + message)
    {
    }
}; // end NotFoundException
#endif
