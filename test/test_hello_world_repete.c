#include <stdio.h>
#include <stdlib.h>

#include "hello_world_repete.h"

int main(int argc, char** argv)
{
  unsigned nb_repetitions;
  if (argc != 2) {
    fprintf(stderr, "Erreur\nUsage: ./bin/affiche NB_REPETITIONS\n");
    exit(EXIT_FAILURE);
  }
  nb_repetitions = atoi(argv[1]);
  affichage_repete(nb_repetitions);
  exit(EXIT_SUCCESS);
}
