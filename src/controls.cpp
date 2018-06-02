#include "controls.h"
#include "entity.h"
#include "systems.h"

#include "spawner.h"

controls::controls(entity* parent) : attribute(parent) {
	move_speed = 100;
}

controls::~controls() {

}

void controls::run() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		parent->move(shmupgine::clock.getElapsedTime().asMicroseconds() * -0.000001f * move_speed, 0);
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		parent->move(0.000001f * move_speed * shmupgine::clock.getElapsedTime().asMicroseconds(), 0);
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		parent->move(0, -0.000001f * move_speed * shmupgine::clock.getElapsedTime().asMicroseconds());
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		parent->move(0, 0.000001f * move_speed * shmupgine::clock.getElapsedTime().asMicroseconds());
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if(parent->get_attribute<spawner>() != NULL) {
			//parent->get_attribute<spawner>()->spawn("bullet");
			parent->get_attribute<spawner>()->spawn_all();
		}
	}
}

controls* controls::make_copy(entity* newparent) {
	controls* ptr = new controls(*this);
	ptr->parent = newparent;
	return ptr;
}
