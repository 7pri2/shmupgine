#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__	

class entity;
class scene;

/* Un attribut est une propriété apportée à une entité; */
class attribute {
	friend class entity;
public:
	attribute();
	attribute(entity* parent);
	virtual ~attribute() {};

/* Interrupteur pour savoir s'il faut ou non executer le comportement de
 * l'attribut */
	bool				enabled;

protected:
	virtual attribute*	make_copy(entity* newparent) = 0;
/* Fonction virtuelle qui produit le comportement de l'attribut */
	virtual void		run();

/* Pointeur sur l'entité parente de l'attribut, afin de permettre
 * l'intéropérabilité entre différents attributs */
	entity*				parent;
};

#endif
