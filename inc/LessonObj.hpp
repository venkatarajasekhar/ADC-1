#ifndef LESSONOBJ_HPP
#define LESSONOBJ_HPP

#include "rapidxml.hpp"

class	LessonObj {
public:
  LessonObj();
  ~LessonObj();

  void	parse(rapidxml::xml_node<> *pRoot);
  void	printInfo();

private:
  char *lessonText;
  char *exampleText;
  char *exampleExplain;
};

#endif
