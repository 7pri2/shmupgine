#include "movement.h"
#include "entity.h"
#include <iostream>

movement::movement(entity* parent) : attribute(parent) {
	speed_factor = 1;
	m_x = [](float x)	->	float { return x*0; };
	m_y = [](float y)	->	float { return y*0; };
	m_clock.restart();
}

movement::~movement() {}

void movement::set_curve(std::function<float(float)> x, std::function<float(float)> y) {
	m_x = x;
	m_y = y;
}

void movement::run() {
	float sec = m_clock.getElapsedTime().asMilliseconds() / 1000.f;
	parent->set_position(sf::Vector2f(m_x(sec), m_y(sec)) * speed_factor);
}

movement* movement::make_copy(entity* newparent) {
	movement* ptr = new movement(*this);
	ptr->parent = newparent;
	ptr->m_clock.restart();
	return ptr;
}
