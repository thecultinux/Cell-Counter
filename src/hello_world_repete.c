#include <stdio.h>

#include "hello_world_repete.h"

void affiche_hello_world(void)
{
  printf("Hello world!\n");
}

void affichage_repete(unsigned nb_repetitions)
{
  for (unsigned rep = 0; rep < nb_repetitions; rep++) {
    affiche_hello_world();
  }
}
