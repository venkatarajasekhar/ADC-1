#ifndef XMLOBJ_HPP
#define XMLOBJ_HPP

#include <vector>
#include <utility>
#include <string>
#include "rapidxml.hpp"
#include "LessonObj.hpp"
#include "TestObj.hpp"

class XmlObj;

typedef	std::vector<std::pair<char *, XmlObj*> > fileType;

class	XmlObj {
public:
  XmlObj(char *filename);
  ~XmlObj();

  void	init(const fileType &files);
  void	printInfo();
  
private:
  XmlObj *findXmlObj(const fileType &files, char *filename);

  rapidxml::xml_document<> doc;
  rapidxml::xml_node<> *pRoot;
  std::vector<XmlObj*> need;
  LessonObj lesson;
  TestObj tests;
  char *lessonName;
  std::string content;
};

#endif
