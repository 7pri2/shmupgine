#ifndef __controls_H__
#define __controls_H__	

#include "attribute.h"
#include <map>

/* "controls" est un attribut qui permet de gérer les appuis sur les touches 
 * directionnelles pour déplacer l'entité parente	*/

class controls : public attribute {
public:
	controls(entity* parent);
	~controls();

/* move_speed gère la vitesse à laquelle l'entité parente de cet attribut se
 * déplace lors qu'elle est déplacée au clavier */
	float	move_speed;

private:
	virtual void 		run();
	virtual	controls*	make_copy(entity* newparent);
};

#endif
