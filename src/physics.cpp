#include "physics.h"
#include "systems.h"
#include "entity.h"

physics::physics(entity* parent) : attribute(parent) {
	this->force = sf::Vector2f(0, 0);
	this->velocity = 0;
}

physics::physics(entity* parent, sf::Vector2f force, float velocity) : attribute(parent) {
	this->force = force;
	this->velocity = velocity;
}

physics::~physics() {

}

void physics::run() {
#ifdef DEBUG
	std::cout << "\tphysics... ";
#endif
	parent->move(0.001f * force * velocity * (float)shmupgine::clock.getElapsedTime().asMilliseconds());
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

void physics::setForce(sf::Vector2f force) {
	this->force = force;
}

void physics::setVelocity(float velocity) {
	this->velocity = velocity;
}

physics* physics::make_copy(entity* newparent) {
	physics* ptr = new physics(*this);
	ptr->parent = newparent;
	return ptr;
}
