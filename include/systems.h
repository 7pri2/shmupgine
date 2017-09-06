#ifndef __SYSTEMS_H__
#define __SYSTEMS_H__	

#include <SFML/Graphics.hpp>

namespace shmupgine {
/* Le namespace regroupe différentes variables et fonctions essentielles au
 * fonctionnement du moteur.
 * Le vecteur entities contient toutes les entités de la scene. */
	extern int 					w_width;
	extern int 					w_height;
	extern std::string			w_title;
	extern sf::RenderWindow		window;
	extern sf::Clock			clock;
	
	void init();
} /* namespace shmupgine */

#endif
