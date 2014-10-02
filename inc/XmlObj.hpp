//
// XmlObj.hpp for XmlObj in /home/jaccar_a/Documents/ADC
// 
// Made by Quentin Jaccarino
// Login   <jaccar_a@localhost.localdomain>
// 
// Started on  Wed Oct  1 20:29:56 2014 Quentin Jaccarino
// Last update Thu Oct  2 01:55:30 2014 Quentin Jaccarino
//

#ifndef XMLOBJ_HPP_
# define XMLOBJ_HPP_

class	XmlObj {
public:
  XmlObj(const string &filename);
  ~XmlObj();

  Initialize();

private:
  string filename;
  std::vector<XmlObj*> need;
  TestObj tests;
  LessonObj lesson;
};

#endif /* !XMLOBJ_HPP_ */
