# shmupgine
Shmupgine est un moteur de jeux et une bibliotheque basée sur SFML, conçue pour créer des jeux de type « Shoot’em’up ». Cependant, avec de l’imagination, il est tout à fait possible d’en faire quelque-chose d’autre.

Le coeur du système consiste en la mise en relation de trois classes:
- entity
- attribute
- scene

Un ensemble d’entités contient un ensemble d’attributs, entites qui sont elles enregistrees dans des scenes. Pour fonctionner convenablement, ces classes-là empruntent des variables et fonctions de l’espace de nom shmupgine qui contient par exemple le chronomètre, la fenêtre du jeu, ainsi que des fonctions d’initialisation.
