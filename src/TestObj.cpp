#include <iostream>
#include <cstdlib>
#include "TestObj.hpp"

TestObj::TestObj() {
}

TestObj::~TestObj() {
}

void	TestObj::parse(rapidxml::xml_node<> *pRoot) {
  rapidxml::xml_node<> *pTest = pRoot->first_node("test");
  min = atoi(pTest->first_node("min")->value());
  for (rapidxml::xml_node<> *pQuestion=pTest->first_node("question");
       pQuestion; pQuestion=pQuestion->next_sibling("question")) {
    questions.push_back(new QuestionObj(pQuestion));
  }
}

void	TestObj::printInfo() {
  std::cout << "Min question : " << min << std::endl;
  for (std::vector<QuestionObj *>::iterator it = questions.begin();
       it != questions.end(); it++) {
    (*it)->printInfo();
  }
}
