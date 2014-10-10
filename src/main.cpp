//
// main.cpp for main in /home/jaccar_a/Documents/ProjEpitech/adc
//
// Made by Quentin Jaccarino
// Login   <jaccar_a@localhost.localdomain>
//
// Started on  Sun Sep 28 16:16:17 2014 Quentin Jaccarino
// Last update Thu Oct  2 02:20:24 2014 Quentin Jaccarino
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "epur.hpp"
#include "rapidxml.hpp"

int	main() {
    rapidxml::xml_document<> doc;
    std::ifstream file("script/pointeurs.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    rapidxml::xml_node<> *pRoot = doc.first_node("adc");
    std::cout << "File Name [" << pRoot->first_attribute("name")->value()
        << "]" << std::endl;

    std::cout << std::endl << "NEED PART" << std::endl;
    rapidxml::xml_node<> *pNeed = pRoot->first_node("need");
    for (rapidxml::xml_node<> *pFile=pNeed->first_node("file");
            pFile; pFile=pFile->next_sibling("file")) {
        std::cout << "File [" << pFile->first_attribute("name")->value()
            << "]" << std::endl;
    }

    std::cout << std::endl << "TEST PART" << std::endl;
    rapidxml::xml_node<> *pTest = pRoot->first_node("test");
    std::cout << "Min [" << pTest->first_node("min")->value()
        << "]" << std::endl;
    for (rapidxml::xml_node<> *pQuestion=pTest->first_node("question");
            pQuestion; pQuestion=pQuestion->next_sibling("question")) {
        std::string qText = pQuestion->first_node("text")->value();
        epur(qText);
        std::cout << "Question Text [" << qText << "]" << std::endl;
        for (rapidxml::xml_node<> *pAnswer=pQuestion->first_node("answer");
                pAnswer; pAnswer=pAnswer->next_sibling("answer")) {
            std::cout << "Answer text [" << pAnswer->value()
                << "]" << std::endl;
            std::cout << "Answer value [" << pAnswer->first_attribute("value")->value()
                << "]" << std::endl;
        }
    }

    std::cout << std::endl << "LESSON PART" << std::endl;
    rapidxml::xml_node<> *pLesson = pRoot->first_node("lesson");
    std::cout << "Lesson text [" << pLesson->first_node("text")->value()
        << "]" << std::endl;
    rapidxml::xml_node<> *pExample = pLesson->first_node("example");
    std::cout << "Example text [" << pExample->first_node("text")->value()
        << "]" << std::endl;
    std::cout << "Example explain [" << pExample->first_node("explain")->value()
        << "]" << std::endl;

    return (0);
}
