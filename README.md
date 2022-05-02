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
##### 1. Test de lecture des fichier PGM.
Il affiche sur le terminal la matrice des pixels de l'image en représentation avec des entiers.

  `./bin/test_pgm_read INPUT_PGM`

  - `INPUT_PGM` : l'adresse du fichier pgm entrant.

            $./bin/test_pgm_read images/test_seed.pgm
            longueur:7 ||  largeur:7 ||  profondeur:255
            0 0 0 0 0 0 0
            0 0 0 0 0 0 0
            0 0 0 0 0 0 0
            0 0 0 0 0 0 0
            0 0 0 255 0 0 0
            0 0 0 0 0 0 0
            0 0 0 0 0 0 0

##### 2. Test d'écriture des fichier PGM.
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

##### 3. Test de seuillage des fichiers PGM.
Ce test produit deux images en sortie. `manual_threshold.pgm` et `auto_threshold.pgm`. Il produit une image en noir et blanc à partir d'une source en niveaux de gris. Le seuil de discrimination entre les deux niveaux est déterminé par l'utilisateur pour `manual_threshold.pgm` et automatiquement par la méthode d'otsu pour le `auto_threshold.pgm`.

  `./bin/test_pgm_threshold INPUT_PGM THRESHOLD`

  - `INPUT_PGM` : l'adresse du fichier pgm à seuiller.
  - `THRESHOLD` : Seuil manuel entre 0 et 255.

            $./bin/test_pgm_threshold images/cells.pgm 120
            Calculated threshold = 155

##### 4. Test des fonctions booléennes.
Ce test fait des opérations booléennes sur 2 images de mêmes dimensions : l'intersection , l'union et le OU exclusif et produit une image contenant le résultat de l'opération.

  `./bin/test_bool MODE INPUT1 INPUT2`

  - `INPUT1` : l'adresse du 1er fichier pgm.
  - `INPUT2` : l'adresse du 2eme fichier pgm.
  - `MODE` : "i": intersection || "u": union || "xor": OU exclusif.

            $ ./bin/test_bool i images/zones.pgm images/zones.pgm
            Mode intersection
            successful intersection

##### 5. Test des fonctions morphologiques.
Ce test fait des opérations morphologiques sur une image : l'érosion , la dilatation, la reconstruction et l'érosion ultime et produit une image contenant le résultat de l'opération.

  `./bin/test_morphology MODE INPUT <SEED>`

  - `INPUT` : l'adresse du fichier pgm d'entrée.
  - `SEED` : (Uniquement pour la reconstruction) c'est l'adresse du fichier pgm graine.
  - `MODE` : "er": erosion || "ex": dilatation || "re": reconstruction || "uer": érosion ultime.

            $ ./bin/test_morphology re images/reconstruct_test.pgm images/test_seed.pgm
            Reconstruction done

##### 6. Test des fonctions de traitement d'image.
Ce test fait des opérations de traitement d'image : la suppression des cellules de bords , le bouchage des trous, la génération d'une image graine (pour les 2 fonctions précédentes) et l'érosion manuelle et produit une image contenant le résultat de l'opération.

  `./bin/test_image_processing MODE INPUT <N>`

  - `INPUT` : l'adresse du fichier pgm d'entrée.
  - `N` : (Uniquement pour l'érosion manuelle) c'est le nombre de fois à éroder.
  - `MODE` : "b": suppression des cellules de bords || "h": remplissage" de trous || "genseed": génération d'un cadre blanc (graine) || "mer": érosion manuelle .

            $ ./bin/test_image_processing mer images/cells.pgm 5
            Manual erosion done

##### 7. Test du comptage de cellules.
Ce test permet de compter les cellules existantes dans une image pgm (déjà traitée par les fonction de traitement d'image).

  `./bin/test_counter MODE INPUT`

  - `INPUT` : l'adresse du fichier pgm d'entrée.
  - `MODE` : "s": comptage simple

            $ ./bin/test_counter s border_cells_removed.pgm
            Mode Comptage simple
            Counter result : 12 cells

##### 8. Test de l'étiquettage.
Ce test permet de générer des images "numéro" et de les coller sur une image source.

  `./bin/test_label MODE N <INPUT>`

  - `N` : c'est le numéro de l'étiquette.
  - `MODE` : "gen_num": génère une image "numéro" à partir d'un numéro (entre 0 et 9) || "l": ajoute l'image "numéro" au centre de l'image input.
  - `INPUT` :(uniquement pour le mode "l") l'adresse du fichier pgm d'entrée à numéroter.

            $ ./bin/test_label l 85 images/cells.pgm
            Label printed
