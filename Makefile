# Options de compilation
CFLAGS=-g -Wall -Wextra -std=c99

# Options d'édition des liens
LDLIBS=-lm

# Liste des exécutables à générer : un par fichier test .c
BIN_FILES=$(patsubst test/%.c, bin/%, $(wildcard test/*.c))

# Règle pour générer tous les exécutables de la liste
all: $(BIN_FILES)

# Règle générique pour générer les exécutables de test
bin/test_%: obj/%.o obj/test_%.o
	gcc $^ $(LDLIBS) -o $@

# Règle générique pour générer les fichiers objets pour les tests
obj/test_%.o: test/test_%.c
	gcc $(CFLAGS) -g -Iinclude -c $^ -o $@

# Règle générique pour générer les fichiers objets pour les sources
obj/%.o: src/%.c
	gcc $(CFLAGS) -g -Iinclude -c $^ -o $@

# Règle de nettoyage
clean:
	rm -rf bin
	rm -rf obj
	mkdir bin
	mkdir obj
