/**
 * \file	controls.h
 * \brief	Contains the definition of the class `controls' which inherits from 
 * `attribute'. It manages user input
 */

#ifndef __controls_H__
#define __controls_H__	

#include "attribute.h"

/**
 * \class	controls
 * \brief	This attribute manages user input and allow its parent entity to 
 * move and to trigger the spawner attribute if the parent entity has one
 */

class controls : public attribute {
public:
	/**
	 * \brief	Constructor of the attribute
	 * \param	parent	Parent entity on which the attribute is attached to
	 */

	controls(entity* parent);

	/// Destructor for this attribute
	
	~controls();

	/// Speed of which the parent entity moves

	float	move_speed;

private:
	virtual void 		run();
	virtual	controls*	make_copy(entity* newparent);
};

#endif
