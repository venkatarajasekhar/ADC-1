#include <exception>

class Error: public std::exception {
public:
  Error(char *what, char *where);

  virtual const char *where() const throw();
  virtual const char *what() const throw();

private:
  char *_what;
  char *_where;
};
