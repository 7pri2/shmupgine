/**
 * \file	destructor.h
 * \brief	Contains the definition of the attribute destructor
 */

#ifndef __destructor_H__
#define __destructor_H__	

#include "attribute.h"
#include <string>
#include <list>

class entity;
class scene;

/* Attribut gèrant les évenements de destruction de l'entité parente, que ce
 * soit à cause d'une collision, à la sortie de l'écran, ou tout simplement
 * la destruction sur demande	*/

class destructor : public attribute {
public:
	destructor();
	destructor(entity* parent);
	~destructor();

/* Ajoute une entité ou un groupe à la liste des entités ou des groupes avec 
 * lesquel(le)s la collision détruit l'entité parente */
	void	add_collision_entity(entity* en);
	void	add_collision_group(std::string group);

/* Interrupteur qui indique si l'entité est détruite si elle sort de l'écran */
	bool 	f_when_out_of_bounds;

/* Permet de savoir si l'entite est en dehors de l'ecran */
	bool	is_out_of_bounds();

/* Fonctions permettant de connaître des informations à propos des collisions
 * /!\  Attention: l'utilisation de l'attribut "destructor" pour connaître des 
 * 		informations relatives aux collisions nécessite que l'entité parente
 * 		possède l'attribut "graphicrenderer" pour fonctionner	*/
	bool	collides(entity* en);
	bool	collides_something();

/* Détruit l'entité parente */
	void 	destroy();

private:
	virtual void 			run();
	virtual destructor*		make_copy(entity* newparent);

/* Flag qui permet de savoir si l'entité parente a déjà été soumise à la 
 * destruction */
	bool					m_destruction_requested;
	std::list<entity*>		m_entities;
	std::list<std::string>	m_groups;
};

#endif
