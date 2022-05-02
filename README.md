# Compteur de cellules à partir d'une photographie en format PGM binaire

Auteur : Youwan Mahé et Aziz Yahmadi

Ce programme effectue un traitement d'image afin de compter le nombres de cellules présentent sur la photographie

## Compilation

Pour compiler le programme
`make`
Pour nettoyer le répertoire avant de compiler
`make clean`
## Utilisation

`./bin/main INPUT_PGM`

- `INPUT_PGM` : l'adresse du fichier pgm entrant.

    $ ./bin/main images/cells.pgm
      99%
      Counter result : 18 cells
## Test
1. Test de lecture des fichier PGM.
Il affiche sur le terminal la matrice des pixels de l'image en représentation avec des entiers.

  `./bin/test_pgm_read INPUT_PGM`

  - `INPUT_PGM` : l'adresse du fichier pgm entrant.

    $ ./bin/test_pgm_read images/test_seed.pgm
      longueur:7 ||  largeur:7 ||  profondeur:255
      0 0 0 0 0 0 0
      0 0 0 0 0 0 0
      0 0 0 0 0 0 0
      0 0 0 0 0 0 0
      0 0 0 255 0 0 0
      0 0 0 0 0 0 0
      0 0 0 0 0 0 0

2. Test d'écriture des fichier PGM.
Il lit un fichier PGM puis créer une copie afin de tester l'écriture des fichiers PGM.

  `./bin/test_pgm_write INPUT_PGM OUTPUT_PGM`

  - `INPUT_PGM` : l'adresse du fichier pgm entrant.
  - `OUTPUT_PGM` : le nom du fichier pgm sortant.
    $ ./bin/test_pgm_write images/morphotest1.pgm copie
    copie
    longueur:7 ||  largeur:7 ||  profondeur:255
    0 0 0 0 0 0 0
    0 255 255 255 255 255 0
    0 255 255 255 255 255 0
    0 255 255 255 255 255 0
    0 255 255 255 255 255 0
    0 255 255 255 255 255 0
    0 0 0 0 0 0 0
    Succesfully copied file to copie

3. Test de seuillage des fichiers PGM.
Ce test produit deux images en sortie. `manual_threshold.pgm` et `auto_threshold.pgm`. Il produit une image en noir et blanc à partir d'une source en niveaux de gris. Le seuil de discrimination entre les deux niveaux est déterminé par l'utilisateur pour `manual_threshold.pgm` et automatiquement par la méthode d'otsu pour le `auto_threshold.pgm`.

  `./bin/test_pgm_threshold INPUT_PGM THRESHOLD`

  - `INPUT_PGM` : l'adresse du fichier pgm à seuiller.
  - `THRESHOLD` : Seuil manuel entre 0 et 255.

    $./bin/test_pgm_threshold images/cells.pgm 120
      Calculated threshold = 155
