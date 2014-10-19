#include <iostream>
#include "LessonObj.hpp"

LessonObj::LessonObj() {
}

LessonObj::~LessonObj() {
}

void	LessonObj::parse(rapidxml::xml_node<> *pRoot) {
  rapidxml::xml_node<> *pLesson = pRoot->first_node("lesson");
  lessonText = pLesson->first_node("text")->value();
  rapidxml::xml_node<> *pExample = pLesson->first_node("example");
  exampleText = pExample->first_node("text")->value();
  exampleExplain = pExample->first_node("explain")->value();
}

void	LessonObj::printInfo() {
  std::cout << "Lesson text : " << lessonText << std::endl;
  std::cout << "Example text : " << exampleText << std::endl;
  std::cout << "Expample explain : " << exampleExplain << std::endl;
}
