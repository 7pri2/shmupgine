#ifndef __ENTITY_H__
#define __ENTITY_H__	

#include <list>
#include <SFML/Graphics.hpp>

class scene;
class attribute;
class destructor;
class spawner;

/* Le type attr_table est un vecteur contenant la liste des attributs de 
 * l'entité */
typedef std::list<attribute*> attr_table;

/* La classe entity décrit les éléments d'une scene. 
 * Une entité est composée de:
 * 		- Une position relative à la fenêtre
 * 		- Une liste d'attributs	
 **/
class entity {
	friend class spawner;
	friend class destructor;
	friend class scene;
public:
	entity();
	entity(scene* parent);
	entity(scene* parent, sf::Vector2f initial_position);
	entity(sf::Vector2f initial_position);
	~entity();
	
/* Tres dangereux, pour la copie uniquement, et a virer ensuite 
 * A REMPLACER DES QUE POSSIBLE PAR LA FONCTION SUIVANTE */
	// + WIP, car en fait faut recreer les objets !
	template<typename T> void allocate_attribute(T* ptr) {
		attributes.push_back(ptr->make_copy(this));
	}


/* Permet d'allouer en mémoire un attribut dans la liste d'attributs de
 * l'entité 
	template<typename T> void allocate_attribute(T* newptr) {
		for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it)
			if(dynamic_cast<T*>(*it) != NULL)
				return;
		attributes.push_back(newptr);
		attributes.back()->parent = this;		
	}
	*/

	template<typename T> void allocate_attribute() {
		for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it)
			if(dynamic_cast<T*>(*it) != NULL)
				return;
		attributes.push_back(new T(this));
	}

/* Permet de récupérer un attribut en particulier de l'entité */
	template<typename T> T* get_attribute() {
		for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it)
			if(dynamic_cast<T*>(*it) != NULL)
				return (T*)*it;
		return NULL;
	}

/* Fonctions relatives à la position de l'entité sur la scene */
	sf::Vector2f	get_position() const;
	void 			move(sf::Vector2f offset);
	void 			move(float x, float y);
	void 			set_position(sf::Vector2f pos);
	void 			set_position(float x, float y);


protected:
/* Utile pour l'attribut spawner */
	entity(entity* en);

/* Permet de déclencher tous les effets des attributs activés */
	void 			run_attributes();

	attr_table		attributes;
	sf::Vector2f	position;
	scene*			parent;
};

#endif
