#ifndef __gmanager_H__
#define __gmanager_H__	

#include <SFML/Graphics.hpp>
#include <map>

#define DEF_BULLET_SIZE	16
#define BULLETPATH    	"res/bullet.png"

namespace gmanager {
/* Texture par défaut de la classe "bullet" et bibliothèque de textures pour le 
 * jeu entier, indexées par une chaine de caractères	*/
	extern sf::Texture* tex_bullet;
	extern std::map<std::string, sf::Texture*>	textures;

/* Initialisation des textures du jeu et libération de la mémoire utilisée; 
 * new_texture est à utiliser avant la création des entités dans la fonction
 * principale */
	void init();
	void free();
	void new_texture(std::string name, std::string path, int width, int height);
} /* namespace gmanager */

#endif
