#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <iostream>

/* C++ error handeling class for passing simple strings. */
class Exception : public std::exception {
private:
  std::string mes;

public:
  Exception(const char *s) : mes(s) {}

  virtual ~Exception() throw() {}

  virtual const char *what() const throw() { return (mes.c_str()); }
};

#endif // _EXCEPTION_H_
