#ifndef __PHYSICS_H__
#define __PHYSICS_H__	

#include <SFML/Graphics.hpp>
#include <cmath>
#include "attribute.h"

#define PI 3.14159265
sf::Vector2f force(float angle); 

/* Attribut qui permet de faire se mouvoir dans la scène une entité selon une 
 * force et une vélocité */

/* À venir: appliquer une liste de force à l'entité au lieu d'une seule */

class physics : public attribute {
public:
	physics(entity* parent);
	physics(entity* parent, int angle, float velocity);
	virtual ~physics();

/* Applique une force à l'entité parente ainsi qu'une vélocité en pixels par 
 * seconde.	*/
	void	set_force_angle(int angle);
	void	set_velocity(float velocity);
	void	rotate_force(int degrees);

private:
	virtual void 		run();
	virtual physics*	make_copy(entity* newparent);

	int		m_force_angle;
	float	m_velocity;
};

#endif

