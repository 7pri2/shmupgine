#ifndef __PHYSICS_H__
#define __PHYSICS_H__	

#include <SFML/Graphics.hpp>
#include "attribute.h"

/* Attribut qui permet de faire se mouvoir dans la scène une entité selon une 
 * force et une vélocité */

/* À venir: appliquer une liste de force à l'entité au lieu d'une seule */

class physics : public attribute {
public:
	physics(entity* parent);
	physics(entity* parent, sf::Vector2f force, float velocity);
	virtual ~physics();

/* Applique une force à l'entité parente ainsi qu'une vélocité en pixels par 
 * seconde.	*/
	void	setForce(sf::Vector2f force);
	void	setVelocity(float velocity);

private:
	virtual void 		run();
	virtual physics*	make_copy(entity* newparent);

	sf::Vector2f	force;
	float			velocity;
};

#endif

