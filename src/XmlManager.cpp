#include <unistd.h>
#include "XmlManager.hpp"

XmlManager::XmlManager(const std::string &folder) {
  dirent *pdir;
  XmlObj *newXmlObj;
  char *cwd = NULL;

  cwd = getcwd(cwd, 0);
  chdir(folder.c_str());
  dir = opendir(".");
  while ((pdir = readdir(dir))) {
    if (strstr(pdir->d_name, ".xml")) {
      newXmlObj = new XmlObj(pdir->d_name);
      files.push_back(std::make_pair(pdir->d_name, newXmlObj));
      xmlObjs.push_back(newXmlObj);
    }
  }
  chdir(cwd);
  free(cwd);
}

XmlManager::~XmlManager() {
  for (std::vector<XmlObj *>::iterator it = xmlObjs.begin();
       it != xmlObjs.end(); it++) {
    if (*it)
      delete *it;
  }
  closedir(dir);
}

void	XmlManager::initAll() {
  for (std::vector<XmlObj *>::iterator it = xmlObjs.begin();
       it != xmlObjs.end(); it++) {
    (*it)->init(files);
  }
}

void	XmlManager::printAllInfo() {
  for (std::vector<XmlObj *>::iterator it = xmlObjs.begin();
       it != xmlObjs.end(); it++) {
    (*it)->printInfo();
    std::cout << std::endl;
  }
}
