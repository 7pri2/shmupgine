#ifndef __GRAPHICRENDERER_H__
#define __GRAPHICRENDERER_H__	

#include "attribute.h"
#include "gmanager.h"
#include "entity.h"
#include "systems.h"

/* Attribut de rendu graphique; permet également de fournir des options de 
 * collisions à l'attribut "destructor"		*/

class graphicrenderer : public attribute {
public:
	graphicrenderer(entity* parent);
	virtual ~graphicrenderer();

/* Sprite assoscié au rendu graphique de l'entité parente */
	sf::Sprite	sprite;

private:
	virtual void 				run();
	virtual graphicrenderer*	make_copy(entity* newparent);
};

#endif
