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
#ifdef DEBUG
	std::cout << "\tcontrols... ";
#endif
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		parent->move(-0.001f * move_speed * shmupgine::clock.getElapsedTime().asMilliseconds(), 0);
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		parent->move(0.001f * move_speed * shmupgine::clock.getElapsedTime().asMilliseconds(), 0);
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		parent->move(0, -0.001f * move_speed * shmupgine::clock.getElapsedTime().asMilliseconds());
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		parent->move(0, 0.001f * move_speed * shmupgine::clock.getElapsedTime().asMilliseconds());
	} if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		parent->get_attribute<spawner>()->spawn();
	}
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

controls* controls::make_copy(entity* newparent) {
	controls* ptr = new controls(*this);
	ptr->parent = newparent;
	return ptr;
}
