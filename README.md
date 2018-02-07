![shmupgine-logo](https://github.com/7pri2/shmupgine/blob/master/doc/shmupgine-logo.png)

# shmupgine

Shmupgine est un moteur de jeux conçu pour créer des jeux de type « *Shoot'em'up* ». Il s'agit d'un ensemble de bibliothèques basées sur SFML. Cependant, avec de l'imagination, il est tout à fait possible d'en faire quelque-chose d'autre.

Shmupgine est un moteur de jeux et une bibliotheque basée sur SFML, conçue pour créer des jeux de type « *Shoot'em'up* ». Cependant, avec de l’imagination, il est tout à fait possible d’en faire quelque-chose d’autre.

# Apercu

## UI
https://www.youtube.com/watch?v=TvWAI9mQlp8

## Jeu
https://www.youtube.com/watch?v=Gd4MN1LYHV0

# Installation

## GNU/Linux
Pour commencer, clonez ce dépot:

		git clone https://github.com/7pri2/shmupgine.git

Ensuite, il vous faut compiler la bibliotheque. Si vous n'avez pas de quoi la compiler (*g++*, *make*, *...*), commencez par les installer (ignorez cette étape si vous avez déjà le nécessaire):

		sudo apt-get install build-essential

Installez maintenant la bibliothèque [SFML](https://www.sfml-dev.org/) sur laquelle est basée shmupgine:

		sudo apt-get install libsfml-dev

Finalement, construisez la bibliothèque grace à la commande `make` et au *Makefile* présent à la racine du dépôt:

		make libs

À partir de là, la bibliothèque est compilée. Pour créer un projet l'utilisant, vous devrez copier le fichier `shmupgine.h` ainsi que le fichier `libshmupgine.a` dans votre répertoire de projet. Vous pourrez compiler votre projet grâce à la commande:

		g++ -c projet.cpp
		g++ -o projet projet.o -std=c++11 -lshmupgine -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Windows

*Coming soon...*
