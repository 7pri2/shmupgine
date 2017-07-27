#ifndef __SYSTEMS_H__
#define __SYSTEMS_H__	

#include <SFML/Graphics.hpp>
#include "gmanager.h"

namespace shmupgine {
/* Le namespace regroupe différentes variables et fonctions essentielles au
 * fonctionnement du moteur.
 * Le vecteur entities contient toutes les entités de la scene. */
	extern int 					w_width;
	extern int 					w_height;
	extern std::string			w_title;
	extern sf::RenderWindow		window;
	extern sf::Clock			clock;
	
/* Les trois fonctions principales du moteur: init pour initialiser les 
 * variables du jeu, start pour démarrer la boucle principale et update, la 
 * boucle principale */
	void init();
	//void update();
	//void start();
	void close();

} /* namespace shmupgine */

#endif
