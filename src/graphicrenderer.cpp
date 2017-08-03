#include "graphicrenderer.h"

graphicrenderer::graphicrenderer(entity* parent) : attribute(parent) {
	m_sprite.setPosition(parent->get_position());
	f_blinking = false;
	m_ms_blinks = BLINK_DURATION;
}

graphicrenderer::~graphicrenderer() {

}

void graphicrenderer::run() {
#ifdef DEBUG
	std::cout << "\tgraphicrenderer... ";
#endif
	if(f_blinking) {
		if(m_clock.getElapsedTime().asMilliseconds() >= m_ms_blinks) {
			f_blinking = false;
			m_clock.restart();
			m_sprite.setColor(RGBA(255, 255, 255));
		} else
			if(m_clock.getElapsedTime().asMilliseconds() / 100 % 2)
				m_sprite.setColor(RGBA(255, 255, 255, 95));
			else
				m_sprite.setColor(RGBA(255, 255, 255));
	}
	shmupgine::window.draw(m_sprite);
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

void graphicrenderer::set_texture(std::string texture_name) {
	m_sprite.setTexture(*gmanager::instance().m_textures[texture_name]);
	m_sprite.setOrigin(m_sprite.getTextureRect().width/2, m_sprite.getTextureRect().height/2);
}

graphicrenderer* graphicrenderer::make_copy(entity* newparent) {
	graphicrenderer* ptr = new graphicrenderer(*this);
	ptr->parent = newparent;
	return ptr;
}

void graphicrenderer::colorify(sf::Color color) {
	m_sprite.setColor(color);
}

sf::Color RGBA(int r, int g, int b, int a) {
	return sf::Color(r, g, b, a);
}

void graphicrenderer::blink(int ms) {
	m_clock.restart();
	f_blinking = true;
	m_ms_blinks = ms;
}

bool graphicrenderer::blink_finished() {
	return !f_blinking;
}
