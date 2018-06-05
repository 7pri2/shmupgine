#include "controls.h"
#include "entity.h"
#include "systems.h"

#include "spawner.h"

controls::controls(entity* parent) : attribute(parent) {
    m_clock.restart();
	move_speed = 100;
}

controls::~controls() {

}

void controls::run() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		parent->move(m_clock.getElapsedTime().asMicroseconds() * -0.000001f * move_speed, 0);
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		parent->move(0.000001f * move_speed * m_clock.getElapsedTime().asMicroseconds(), 0);
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		parent->move(0, -0.000001f * move_speed * m_clock.getElapsedTime().asMicroseconds());
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		parent->move(0, 0.000001f * move_speed * m_clock.getElapsedTime().asMicroseconds());
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if(parent->get_attribute<spawner>() != NULL) {
			parent->get_attribute<spawner>()->spawn_all();
		}
	}
    m_clock.restart();
}

controls* controls::make_copy(entity* newparent) {
    m_clock.restart();
	controls* ptr = new controls(*this);
	ptr->parent = newparent;
	return ptr;
}
