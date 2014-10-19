//
// epur.cpp for epur in /home/jaccar_a/Documents/ADC
//
// Made by Quentin Jaccarino
// Login   <jaccar_a@localhost.localdomain>
//
// Started on  Mon Sep 29 00:17:36 2014 Quentin Jaccarino
// Last update Sun Oct 19 04:34:34 2014 Quentin Jaccarino
//

#include <cstdlib>

void	epur(char *chaine) {
  int blanc = 1;
  char *lire = chaine;
  char *ecrire = chaine;

  while (*lire != '\0') {
    if (*lire != ' ' || !blanc)
      *ecrire++ = *lire;
    blanc = *lire++ == ' ';
  }
  if (blanc && ecrire != chaine)
    --ecrire;
  *ecrire = '\0';
}
