#ifndef XMLMANAGER_HPP
#define XMLMANAGER_HPP

#include <dirent.h>
#include <string.h>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "XmlObj.hpp"

class	XmlManager {
public:
  XmlManager(const std::string &folder);
  ~XmlManager();

  void initAll();
  void printAllInfo();

private:
  std::vector<XmlObj *> xmlObjs;
  fileType files;
  DIR *dir;
};

#endif
