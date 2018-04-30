/**
 * \file	graphicrenderer.h
 * \brief	Contains the definition of the attribute graphicrenderer which 
 * 			allows the entity to have a sprite
 */

#ifndef __GRAPHICRENDERER_H__
#define __GRAPHICRENDERER_H__	

#include "attribute.h"
#include "gmanager.h"
#include "entity.h"
#include "systems.h"

/// Defines the default blink duration
#define BLINK_DURATION 650

class destructor;

/**
 * \brief	Returns an object of type sf::Color which corresponds to the color
 * 			described by the parameters of the function
 * \param	r	Amount of **red** in the composition of the color. Value between
 * 				0 and 255
 * \param	g	Amount of **green** in the composition of the color. Value 
 * 				between 0 and 255
 * \param	b	Amount of **blue** in the composition of the color. Value 
 * 				between 0 and 255
 * \param	a 	Degree of transparency (alpha channel) of the color. Value 
 * 				between 0 and 255; if not specified, 255
 * \return	An object of type sf::Colors corresponding to the color descibed in 
 * 			parameters
 */
sf::Color RGBA(int r, int g, int b, int a = 255);

/* Attribut de rendu graphique; permet également de fournir des options de 
 * collisions à l'attribut "destructor"		*/

/**
 * \class	graphicrenderer
 * \brief	Attribute used to let the entities have a sprite and collisions
 *
 */

class graphicrenderer : public attribute {
	friend class entity;
	friend class destructor;
public:
	/// Typical attribute-derived constructor
	graphicrenderer(entity* parent);

	/// Destructor
	virtual ~graphicrenderer();

	/**
	 * \brief	Change the texture of the sprite
	 * \param	texture_name	The name of the texture that we want to set
	 */
	void	set_texture(std::string texture_name);
	void	colorify(sf::Color color);
	void	blink(int ms = BLINK_DURATION);
	void	rotate(int degrees);
	bool	blink_finished();

private:
	virtual void 				run();
	virtual graphicrenderer*	make_copy(entity* newparent);

	/// Sprite of type sf::Sprite
	sf::Sprite	m_sprite;

	/// Clock used to measure the time for the blink duration
	sf::Clock	m_clock;

	/// Integer of how many ms lasts the blink effect
	int			m_ms_blinks;
	
	/// Flag used to know if the parent entity is blinking right now
	bool		f_blinking;
};

#endif
