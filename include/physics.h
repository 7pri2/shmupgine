/**
 * \file	physics.h
 * \brief	Contains the definition of the attribute `physics' used to set an 
 * 			uniform rectilinear motion
 */

#ifndef __PHYSICS_H__
#define __PHYSICS_H__	

#include <SFML/Graphics.hpp>
#include <cmath>
#include "attribute.h"

/// Defines the constant pi in order to calculate vectors and angles
#define PI 3.14159265

/**
 * \class 	physics
 * \brief	Attribute that allows the parent entity to have a uniform 
 * 			rectilinear motion by tweaking the angle of the movement and its 
 * 			velocity
 */
class physics : public attribute {
public:
	/**
	 * \brief Constructor that attaches the attribute to the given entity
	 * \param	parent	Parent entity to attach the attribute
	 */
	physics(entity* parent);

	/**
	 * \brief Constructor that attaches the attribute to the given entity
	 * \param	parent	Parent entity to attach the attribute
	 * \param	angle	Initial angle for the movement of the entity
	 * \param	velovity	Speed at which the entity will move in the scene
	 */
	physics(entity* parent, int angle, float velocity);
	virtual ~physics();

	/**
	 * \brief Sets the angle of the entity's movement
	 * \param	angle	The new angle for the movement
	 */
	void	set_force_angle(int angle);

	/** 
	 * \brief Sets the new velocity in order to change the speed of its movement
	 * \param	velocity	New speed for the entity
	 */
	void	set_velocity(float velocity);

	/**
	 * \brief Rotate the force of the entity
	 * \param	degrees	Angle in degrees to add to the current angle of the 
	 * 			force
	 *
	 * Use it when you want to change a bit the angle relatively to the current 
	 * angle of the force, to avoid getting the angle and calculate the new one
	 */
	void	rotate_force(int degrees);

	/**
	 * \brief Converts an angle to a vector
	 * \param	angle	The angle to be converted
	 * \return	A vector of length 1 corresponding to the given angle
	 */
	static sf::Vector2f force(float angle); 

private:
	/// Typical attribute function run
	virtual void 		run();

	/// Typical attribute function make_copy
	virtual physics*	make_copy(entity* newparent);

	/// The force angle in degrees
	int		    m_force_angle;

	/// The velocity in pixels per second
	float	    m_velocity;

    /// Internal clock used to calculate the movement
    sf::Clock   m_clock;
};

#endif

