#ifndef __MOVEMENT_H_
#define __MOVEMENT_H__

#include <functional>
#include <SFML/Graphics.hpp>
#include "attribute.h"

class movement : public attribute {
public:
	movement(entity* parent);
	~movement();

	void	set_curve(std::function<float(float)> x, std::function<float(float)> y);
	float	speed_factor;

private:
	virtual void				run();
	virtual movement*			make_copy(entity* newparent);

	std::function<float(float)>	m_x;
	std::function<float(float)>	m_y;
	sf::Clock					m_clock;
};

#endif
