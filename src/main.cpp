#include <iostream>
#include "XmlObj.hpp"
#include "Error.hpp"

int	main() {
  try {
    fileType files;
    XmlObj pointers((char *)"script/pointeurs.xml");

    pointers.init(files);
    pointers.printInfo();
  }
  catch (Error &e) {
    std::cerr << e.what() << " in " << e.where() << std::endl;
  }
  return (0);
}
