#ifndef QUESTIONOBJ_HPP
#define QUESTIONOBJ_HPP

#include <vector>
#include "AnswerObj.hpp"

class	QuestionObj {
public:
  QuestionObj(rapidxml::xml_node<> *pQuestion);
  ~QuestionObj();

  void	printInfo();

private:
  std::vector<AnswerObj *> answers;
  char *text;
};

#endif
