#ifndef __ROUTE_H__
#define __ROUTE_H__

#include <functional>
#include <SFML/Graphics.hpp>
#include "attribute.h"

class route : public attribute {
public:
	route(entity* parent);
	~route();

	void			set_curve(std::function<float(float)> x, std::function<float(float)> y);
	float			speed_factor;

private:
	virtual void	run();
	virtual route*	make_copy(entity* newparent);

	std::function<float(float)>	m_x;
	std::function<float(float)>	m_y;
	sf::Clock					m_clock;
};

#endif
