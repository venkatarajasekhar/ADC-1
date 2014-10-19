#include "Error.hpp"

Error::Error(char *what, char *where) {
  _what = what;
  _where = where;
}

const char *Error::where() const throw() {
  return _where;
}

const char *Error::what() const throw() {
  return _what;
}

