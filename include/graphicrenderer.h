#ifndef __GRAPHICRENDERER_H__
#define __GRAPHICRENDERER_H__	

#include "attribute.h"
#include "gmanager.h"
#include "entity.h"
#include "systems.h"

class destructor;

/* Attribut de rendu graphique; permet également de fournir des options de 
 * collisions à l'attribut "destructor"		*/

class graphicrenderer : public attribute {
	friend class entity;
	friend class destructor;
public:
	graphicrenderer(entity* parent);
	virtual ~graphicrenderer();

	void	set_texture(std::string texture_name);

private:
	virtual void 				run();
	virtual graphicrenderer*	make_copy(entity* newparent);

/* sprite assoscié au rendu graphique de l'entité parente */
	sf::Sprite					m_sprite;
};

#endif
