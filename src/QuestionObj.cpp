#include <iostream>
#include "QuestionObj.hpp"
#include "epur.hpp"

QuestionObj::QuestionObj(rapidxml::xml_node<> *pQuestion) {
    text = pQuestion->first_node("text")->value();
    epur(text);
    for (rapidxml::xml_node<> *pAnswer=pQuestion->first_node("answer");
	 pAnswer; pAnswer=pAnswer->next_sibling("answer")) {
      answers.push_back(new AnswerObj(pAnswer));
    }
}

QuestionObj::~QuestionObj() {
  for (std::vector<AnswerObj *>::iterator it = answers.begin();
       it != answers.end(); it++)
    if (*it) delete *it;
}

void	QuestionObj::printInfo() {
  std::cout << "Question text : " << std::endl
	    << text << std::endl;
  for (std::vector<AnswerObj *>::iterator it = answers.begin();
       it != answers.end(); it++) {
    (*it)->printInfo();
  }
}
