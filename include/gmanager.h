#ifndef __gmanager_H__
#define __gmanager_H__	

#include <SFML/Graphics.hpp>
#include <map>
#include "singleton.h"

#define DEF_BULLET_SIZE	16
#define BULLETPATH    	"res/bullet.png"

class graphicrenderer;

class gmanager : public singleton<gmanager> {
	friend class singleton<gmanager>;
	friend class graphicrenderer;
public:
/* Creation de la bibliotheque de textures new_texture est à utiliser avant la 
 * création des entités dans la fonction principale */
	void new_texture(std::string name, std::string path, int width, int height);

private:
	gmanager(const gmanager&) {};
	gmanager();
	~gmanager();

	std::map<std::string, sf::Texture*>	m_textures;
	sf::Texture*						m_tex_bullet;
};

#endif
