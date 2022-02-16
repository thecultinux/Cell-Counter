#include <stdio.h>
#include <stdlib.h>

#include "hello_world.h"


int main(int argc, char** argv)
{
  unsigned nb_repetitions;
  
  if (argc != 2) {
    fprintf(stderr, "Erreur\nUsage: ./bin/affiche NB_REPETITIONS\n");
    exit(EXIT_FAILURE);
  }
  nb_repetitions = atoi(argv[1]);

  for (unsigned rep = 0; rep < nb_repetitions; rep++) {
    affiche_hello_world();
  }
  exit(EXIT_SUCCESS);
}
