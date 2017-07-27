#ifndef __BULLET_H__
#define __BULLET_H__	

#include "entity.h"

/* Classe héritant de entity, équipée de telle façon à se comporter comme une
 * balle de shoot'em'up */

class bullet : public entity {
public:
	bullet();
	bullet(scene* parent);
	bullet(scene* parent, sf::Vector2f initial_position);
	bullet(sf::Vector2f initial_position);
	virtual ~bullet();
};

#endif
