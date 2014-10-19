#ifndef ANSWEROBJ_HPP
#define ANSWEROBJ_HPP

#include "rapidxml.hpp"

class	AnswerObj {
public:
  AnswerObj(rapidxml::xml_node<> *pAnswer);
  ~AnswerObj();

  void	printInfo();

private:
  int value;
  char *text;
};

#endif
