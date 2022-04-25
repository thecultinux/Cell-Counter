# Options de compilation
# (infos debug, tous warnings, standard C99, dossier include)
CFLAGS=-g -Wall -Wextra -std=c99 -Iinclude

# Options d'édition des liens (pour utiliser math.h)
LDLIBS=-lm

# List source files
SRC=$(wildcard src/*.c)
OBJ=$(subst src/, obj/, $(SRC:.c=.o))

# Règle par défaut : générer tous les exécutables
all: $(OBJ) bin/test_pgm_read bin/test_pgm_write bin/test_pgm_threshold bin/test_bool bin/test_morphology bin/test_image_processing bin/test_counter bin/main bin/test_label

# Règle générique pour générer les fichiers objets pour les sources (.c -> .o)
obj/%.o: src/%.c
	gcc $(CFLAGS) -c $^ -o $@

# Règle générique pour générer les fichiers objets pour les tests (.c -> .o)
obj/test_%.o: test/test_%.c
	gcc $(CFLAGS) -c $^ -o $@

# Règle générique pour générer les exécutables de test (.o -> executable)
bin/test_%: obj/%.o obj/test_%.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_pgm_write
bin/test_pgm_write : obj/test_pgm_write.o obj/pgm_read.o obj/pgm_write.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_threshold
bin/test_pgm_threshold : obj/test_pgm_threshold.o obj/threshold.o obj/pgm_read.o obj/pgm_write.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_bool
bin/test_bool : obj/test_bool.o obj/bool.o obj/pgm_read.o obj/pgm_write.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_morphology
bin/test_morphology : obj/test_morphology.o obj/morphology.o obj/pgm_read.o obj/pgm_write.o obj/bool.o obj/image_processing.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_image_processing
bin/test_image_processing : obj/test_image_processing.o obj/morphology.o obj/pgm_read.o obj/pgm_write.o obj/bool.o obj/image_processing.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_counter
bin/test_counter : obj/test_counter.o obj/pgm_read.o obj/counter.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour main
bin/main : obj/main.o obj/morphology.o obj/pgm_read.o obj/pgm_write.o obj/bool.o obj/image_processing.o obj/counter.o obj/threshold.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour test_label
bin/test_label : obj/test_label.o obj/morphology.o obj/pgm_read.o obj/pgm_write.o obj/bool.o obj/image_processing.o obj/counter.o obj/threshold.o obj/label.o
	gcc $^ $(LDLIBS) -o $@

# Règle de nettoyage
clean:
	rm -rf bin obj
	mkdir bin obj
