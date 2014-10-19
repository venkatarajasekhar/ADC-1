#ifndef TESTOBJ_HPP
#define TESTOBJ_HPP

#include "QuestionObj.hpp"

class	TestObj {
public:
  TestObj();
  ~TestObj();

  void	parse(rapidxml::xml_node<> *pRoot);
  void	printInfo();

private:
  std::vector<QuestionObj *> questions;
  int min;
};

#endif
