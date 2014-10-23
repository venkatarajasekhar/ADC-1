#include <iostream>
#include "XmlManager.hpp"
#include "Error.hpp"

int	main() {
  try {
    XmlManager xmlManager("./script/");

    xmlManager.initAll();
    xmlManager.printAllInfo();
  }
  catch (Error &e) {
    std::cerr << e.what() << " in " << e.where() << std::endl;
  }
  return (0);
}
