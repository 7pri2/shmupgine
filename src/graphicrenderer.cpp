#include "graphicrenderer.h"

graphicrenderer::graphicrenderer(entity* parent) : attribute(parent) {
	m_sprite.setPosition(parent->get_position());
}

graphicrenderer::~graphicrenderer() {

}

void graphicrenderer::run() {
#ifdef DEBUG
	std::cout << "\tgraphicrenderer... ";
#endif
	shmupgine::window.draw(m_sprite);
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

void graphicrenderer::set_texture(std::string texture_name) {
	m_sprite.setTexture(*gmanager::textures[texture_name]);
	m_sprite.setOrigin(m_sprite.getTextureRect().width/2, m_sprite.getTextureRect().height/2);
}

graphicrenderer* graphicrenderer::make_copy(entity* newparent) {
	graphicrenderer* ptr = new graphicrenderer(*this);
	ptr->parent = newparent;
	return ptr;
}
