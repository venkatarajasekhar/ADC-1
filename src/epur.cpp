//
// epur.cpp for epur in /home/jaccar_a/Documents/ADC
//
// Made by Quentin Jaccarino
// Login   <jaccar_a@localhost.localdomain>
//
// Started on  Mon Sep 29 00:17:36 2014 Quentin Jaccarino
// Last update Mon Sep 29 00:43:43 2014 Quentin Jaccarino
//

#include <cstdlib>
#include <iostream>
#include <string>

void	epur(std::string &s) {
  bool space = false, start = false;

  std::string::iterator p = s.begin();
  for (std::string::size_type i = 0; i < s.size(); ++i) {
    char ch = s[i];
    if (std::isspace(ch)) {
      space = p != s.begin();
      if (ch == 10) {
	*p++ = ch;
	start = true;
      }
    }
    else {
      if (space && !start)
	*p++ = ' ';
      *p++ = ch;
      space = false;
      start = false;
    }
  }
  s.erase(p, s.end());
}
