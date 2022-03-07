# Options de compilation
# (infos debug, tous warnings, standard C99, dossier include)
CFLAGS=-g -Wall -Wextra -std=c99 -Iinclude

# Options d'édition des liens (pour utiliser math.h)
LDLIBS=-lm

# Règle par défaut : générer tous les exécutables
all: bin/test_hello_world bin/test_hello_world_repete

# Règle générique pour générer les fichiers objets pour les sources (.c -> .o)
obj/%.o: src/%.c
	gcc $(CFLAGS) -c $^ -o $@

# Règle générique pour générer les fichiers objets pour les tests (.c -> .o)
obj/test_%.o: test/test_%.c
	gcc $(CFLAGS) -c $^ -o $@

# Règle générique pour générer les exécutables de test (.o -> executable)
bin/test_%: obj/%.o obj/test_%.o
	gcc $^ $(LDLIBS) -o $@

# Règle spécifique pour générer l'exécutable test_hello_world
bin/test_hello_world: obj/test_hello_world.o obj/hello_world_repete.o
	gcc $^ $(LDLIBS) -o $@

# Règle de nettoyage
clean:
	rm -rf bin obj
	mkdir bin obj
