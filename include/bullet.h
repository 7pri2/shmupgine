/**
 * \file	bullet.h
 * \brief	Definition of class bullet which inherits from entity and embeds 
 * 			minimal composition of attributes to act as a bullet in a 
 * 			shoot'em'up
 */

#ifndef __BULLET_H__
#define __BULLET_H__	

#include "entity.h"

/* Classe héritant de entity, équipée de telle façon à se comporter comme une
 * balle de shoot'em'up */

/**
 * \class	bullet
 * \brief	Entity embedding the minimal composition of attributes to be a 
 * 			bullet usable in a shoot'em'up. You can use it as it is, but also 
 * 			tweak it like other entities, but the minimal amount of code is 
 * 			already done.
 */

class bullet : public entity {
public:
	/// Defaut constructor
	bullet();

	/**
	 * \brief 	Contructor that allows the bullet to join a scene instantly
	 * \param	parent	Scene in which the bullet will be added
	 */
	bullet(scene* parent);

	/**
	 * \brief 	Contructor that allows the bullet to join a scene instantly
	 * \param	parent	Scene in which the bullet will be added
	 * \param	initial_position	Position where the bullet is set in the 
	 * 								scene. It is of type sf::Vector2f because of
	 * 								underlaying library SFML.
	 */
	bullet(scene* parent, sf::Vector2f initial_position);

	/**
	 * \brief 	Contructor that allows the bullet to join a scene instantly
	 * \param	parent	Scene in which the bullet will be added
	 * \param	ix	The position on the x-axis where the bullet is set in the 
	 * 				scene
	 * \param	iy	The position on the y-axis where the bullet is set in the 
	 * 				scene
	 *
	 * This version avoids type sf::Vector2f
	 */
	bullet(scene* parent, float ix, float iy);

	/// Same constructor but without parent scene
	bullet(sf::Vector2f initial_position);

	/// Same constructor but it avoids type sf::Vector2f
	bullet(float ix, float iy);

	/// Destructor
	virtual ~bullet();
};

#endif
