#include "route.h"
#include "entity.h"
#include <iostream>

route::route(entity* parent) : attribute(parent) {
	speed_factor = 1;
	m_x = [](float x)	->	float { return x*0; };
	m_y = [](float y)	->	float { return y*0; };
	m_clock.restart();
}

route::~route() {}

void route::set_curve(std::function<float(float)> x, std::function<float(float)> y) {
	m_x = x;
	m_y = y;
}

void route::run() {
	float sec = m_clock.getElapsedTime().asMilliseconds() / 1000.f;
	parent->move(sf::Vector2f(m_x(sec), m_y(sec)) * speed_factor);
}

route* route::make_copy(entity* newparent) {
	route* ptr = new route(*this);
	ptr->parent = newparent;
	ptr->m_clock.restart();
	return ptr;
}
