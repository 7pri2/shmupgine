#include "gmanager.h"

gmanager::gmanager() {
}

gmanager::~gmanager() {
	for(std::map<std::string, sf::Texture*>::iterator it = m_textures.begin(); it != m_textures.end(); ++it)
		delete it->second;
}

void gmanager::new_texture(std::string name, std::string path, int width, int height) {
	sf::Texture *tex = new sf::Texture;
	tex->loadFromFile(path, sf::IntRect(0, 0, width, height));
	m_textures[name] = tex;
}
