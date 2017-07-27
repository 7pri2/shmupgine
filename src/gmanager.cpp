#include "gmanager.h"

sf::Texture* gmanager::tex_bullet;
std::map<std::string, sf::Texture*>	gmanager::textures;

void gmanager::init() {
	tex_bullet = new sf::Texture;
	tex_bullet->loadFromFile(BULLETPATH, sf::IntRect(0, 0, DEF_BULLET_SIZE, DEF_BULLET_SIZE));
}

void gmanager::free() {
	delete tex_bullet;
	for(std::map<std::string, sf::Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
		delete it->second;
}

void gmanager::new_texture(std::string name, std::string path, int width, int height) {
	sf::Texture *tex = new sf::Texture;
	tex->loadFromFile(path, sf::IntRect(0, 0, width, height));
	textures[name] = tex;
}
