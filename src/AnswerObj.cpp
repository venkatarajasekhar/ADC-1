#include <iostream>
#include <cstdlib>
#include "AnswerObj.hpp"

AnswerObj::AnswerObj(rapidxml::xml_node<> *pAnswer) {
  value = atoi(pAnswer->first_attribute("value")->value());
  text = pAnswer->value();
}

AnswerObj::~AnswerObj() {
}

void	AnswerObj::printInfo() {
  std::cout << "Answer value : " << value << std::endl;
  std::cout << "Answer text : " << text << std::endl;
}
