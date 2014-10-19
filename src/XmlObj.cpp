#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "XmlObj.hpp"
#include "Error.hpp"

XmlObj::XmlObj(char *xmlFile) {
  std::ifstream file(xmlFile);
  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();
  content = buffer.str();
  doc.parse<0>(&content[0]);
  if (!(pRoot = doc.first_node("adc")))
    throw Error((char*)"Cannot get first xml node", (char*)"XmlObj.cpp");
  lessonName = pRoot->first_attribute("name")->value();
}

XmlObj::~XmlObj() {
}

void	XmlObj::init(const fileType &files) {
  tests.parse(pRoot);
  lesson.parse(pRoot);

  XmlObj *ptr;
  rapidxml::xml_node<> *pNeed = pRoot->first_node("need");
  for (rapidxml::xml_node<> *pFile=pNeed->first_node("file"); pFile;
       pFile=pFile->next_sibling("file"))
    if ((ptr = findXmlObj(files, pFile->first_attribute("name")->value())))
      need.push_back(ptr);
}

void	XmlObj::printInfo() {
  std::cout << "Lesson name : " << lessonName << std::endl << std::endl;
  tests.printInfo();
  lesson.printInfo();
}

XmlObj	*XmlObj::findXmlObj(const fileType &files, char *filename) {
  for (fileType::const_iterator it = files.begin(); it != files.end(); it++) {
    if (strcmp(filename, it->first) == 0)
      return it->second;
  }
  return NULL;
}
