#include "physics.h"
#include "systems.h"
#include "entity.h"

physics::physics(entity* parent) : attribute(parent) {
	m_force_angle = 0;
	m_velocity = 0;
}

physics::physics(entity* parent, int angle, float velocity) : attribute(parent) {
	m_force_angle = angle;
	m_velocity = velocity;
}

physics::~physics() {

}

void physics::run() {
#ifdef DEBUG
	std::cout << "\tphysics... ";
#endif
	parent->move(0.001f * FORCE * m_velocity * (float)shmupgine::clock.getElapsedTime().asMilliseconds());
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

void physics::set_force_angle(int angle) {
	m_force_angle = angle;
}

void physics::set_velocity(float velocity) {
	m_velocity = velocity;
}

physics* physics::make_copy(entity* newparent) {
	physics* ptr = new physics(*this);
	ptr->parent = newparent;
	return ptr;
}

void physics::rotate_force(int degrees) {
	m_force_angle = (m_force_angle + degrees) % 360;
}
