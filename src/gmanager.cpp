#include "gmanager.h"

gmanager::gmanager() {
	m_tex_bullet = new sf::Texture;
	m_tex_bullet->loadFromFile(BULLETPATH, sf::IntRect(0, 0, DEF_BULLET_SIZE, DEF_BULLET_SIZE));
}

gmanager::~gmanager() {
	delete m_tex_bullet;
	for(std::map<std::string, sf::Texture*>::iterator it = m_textures.begin(); it != m_textures.end(); ++it)
		delete it->second;
}

void gmanager::new_texture(std::string name, std::string path, int width, int height) {
	sf::Texture *tex = new sf::Texture;
	tex->loadFromFile(path, sf::IntRect(0, 0, width, height));
	m_textures[name] = tex;
}
