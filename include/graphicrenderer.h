#ifndef __GRAPHICRENDERER_H__
#define __GRAPHICRENDERER_H__	

#include "attribute.h"
#include "gmanager.h"
#include "entity.h"
#include "systems.h"

#define BLINK_DURATION 650

class destructor;

sf::Color RGBA(int r, int g, int b, int a = 255);

/* Attribut de rendu graphique; permet également de fournir des options de 
 * collisions à l'attribut "destructor"		*/

/**
 * \class	graphicrenderer
 */

class graphicrenderer : public attribute {
	friend class entity;
	friend class destructor;
public:
	graphicrenderer(entity* parent);
	virtual ~graphicrenderer();

	void	set_texture(std::string texture_name);
	void	colorify(sf::Color color);
	void	blink(int ms = BLINK_DURATION);
	void	rotate(int degrees);
	bool	blink_finished();

private:
	virtual void 				run();
	virtual graphicrenderer*	make_copy(entity* newparent);

/* sprite assoscié au rendu graphique de l'entité parente */
	sf::Sprite	m_sprite;

/* Timer pour les blinks */
	sf::Clock	m_clock;
	int			m_ms_blinks;
	
/* Flags */
	bool		f_blinking;
};

#endif
