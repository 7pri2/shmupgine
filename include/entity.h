/**
 * \file	entity.h
 * \brief	File where the class `entity' is defined. It is one of the three 
 * 			main classes of the engine
 */

#ifndef __ENTITY_H__
#define __ENTITY_H__	

#include <list>
#include <SFML/Graphics.hpp>

class scene;
class attribute;
class destructor;
class spawner;

/// Type attr_table is a list containing all the attributes of the entity
typedef std::list<attribute*> attr_table;

/**
 * \class	entity
 * \brief	An entity is the smallest part of a scene. It is basically composed 
 * 			of a position from the window and a list of its attached attributes.
 * 			These attributes define what the entity is, for example, a bullet is
 * 			a sprite which translates towards a direction an is able to explode,
 * 			so it is not more than an entity equiped with the attributes physics
 * 			(for the movement), graphicrenderer (for the graphical rendering), 
 * 			and destructor (for the ability to explode). The combination of some
 * 			attributes brings life to the parent entity as explained previously
 *
 * To use an entity properly, you need to proceed in 3 steps. First, attach the 
 * attributes you need, typically a graphicrenderer, but you can add any number
 * of different attributes to one entity. To do so, you must use built in method
 * `allocate_attribute'. Once you allocated all the attributes you want, you 
 * have to edit these attributes with the method `get_attribute'. It returns a 
 * pointer on the attribute you request so you can read the documentation of the
 * concerned attribute to personnalize it. Keep in mind that an entity can have
 * one attribute of the same type at the time. Finally, you can add this entity 
 * to a scene (see documentation for class scene for further details). Note that
 * you can add it to a scene before dealing with its attributes, but it is 
 * advised to add it just before running the scene for better readability
 */
class entity {
	friend class spawnslot;
	friend class spawner;
	friend class destructor;
	friend class scene;
public:
	/// Default constructor, here the entity doesn't join any scene
	entity();

	/**
	 * \brief Constructor that makes the entity join the given scene directly
	 * \param	parent	Adress of the scene the entity is going to join
	 */
	entity(scene* parent);

	/**
	 * \brief Constructor that makes the entity join the given scene directly 
	 * and sets its initial position
	 * \param	parent	Adress of the scene the entity is going to join
	 * \param	intial_position	Initial position of the entity in the scene. Its
	 * 			type is sf::Vector2f because of the underlaying library shmugine
	 * 			uses.
	 */
	entity(scene* parent, sf::Vector2f initial_position);

	/**
	 * \brief Constructor that makes the entity join the given scene directly 
	 * and sets its initial position. This version avoids sf::Vector2f
	 * \param	parent	Adress of the scene the entity is going to join
	 * \param	ix	Initial position relative to x-axis
	 * \param	iy	Initial position relative to y-axis
	 */
	entity(scene* parent, float ix, float iy);

	/**
	 * \brief Constructor that sets the initial position of the entity.
	 * \param	intial_position	Initial position of the entity in the scene. Its
	 * 			type is sf::Vector2f because of the underlaying library shmugine
	 * 			uses.
	 */
	entity(sf::Vector2f initial_position);

	/**
	 * \brief Constructor that sets the initial position of the entity. This 
	 * version avoids sf::Vector2f
	 * \param	ix	Initial position relative to x-axis
	 * \param	iy	Initial position relative to y-axis
	 */
	entity(float ix, float iy);

	/// Destructor
	~entity();

	/**
	 * \brief Allocates a new attribute to the entity
	 *
	 * Template method which allocates an attribute of the given type. It 
	 * checks if the attribute is already attached to the entity and attaches it
	 * if not
	 */
	template<typename T> void allocate_attribute() {
		for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it)
			if(dynamic_cast<T*>(*it) != NULL)
				return;
		attributes.push_back(new T(this));
	}

	/**
	 * \brief	Get a pointer on an attribute attached to the entity
	 * \return	A pointer on the requested attribute if it exists, NULL 
	 * otherwise
	 *
	 * Template method which allows to have a pointer on the given attribute 
	 * attached to the entity. It is useful when you want to tweak this 
	 * attribute
	 */
	template<typename T> T* get_attribute() {
		for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it)
			if(dynamic_cast<T*>(*it) != NULL)
				return (T*)*it;
		return NULL;
	}

	/**
	 * \brief Get current position of the entity
	 * \return	A sf::Vector2f which contains the position of the entity
	 */
	sf::Vector2f	get_position() const;

	/**
	 * \brief Moves the entity
	 * \param	offset	Vector to add to the current position of the entity. 
	 * 					Also a sf::Vector2f
	 */
	void 			move(sf::Vector2f offset);
	
	/**
	 * \brief Moves the entity
	 * \param	x	Offset to add to the current x-axis position of the entity. 
	 * 				This version avoid type sf::Vector2f
	 * \param	y	Offset to add to the current y-axis position of the entity. 
	 * 				This version avoid type sf::Vector2f
	 */
	void 			move(float x, float y);
	
	/**
	 * \brief Sets the entity's position
	 * \param	pos	Vector of the new position of the entity. Also a 
	 * 				sf::Vector2f
	 */
	void 			set_position(sf::Vector2f pos);
	
	/**
	 * \brief Sets the entity's position
	 * \param	x	Value of the new  x-axis position of the entity. 
	 * 				This version avoid type sf::Vector2f
	 * \param	y	Value of the new  y-axis position of the entity. 
	 * 				This version avoid type sf::Vector2f
	 */
	void 			set_position(float x, float y);


protected:
	/**
	 * \brief Copy constructor.
	 * \param	en	Pointer on the entity to be copied
	 *
	 * Useful for the attribute `spawner'
	 */
	entity(entity* en);

	/// Processes all enabled attributes attached to the entity
	void 			run_attributes();

	/// List of attributes attached to the entity
	attr_table		attributes;

	/// Position of the entity
	sf::Vector2f	position;

	/**
	 * \brief Parent scene 
	 *
	 * The parent scene is a pointer on a scene in which the entity appear or 
	 * will appear depending on if the scene is running or not yet running. At 
	 * some point, every non-model entity is going to be part of a scene.
	 */
	scene*			parent;

	/**
	 * Allocate an attribute for the entity which is a copy of the attribute in 
	 * parameters
	 * \param	ptr	Pointer on the attribute we want to copy
	 */
	template<typename T> void allocate_attribute(T* ptr) {
		attributes.push_back(ptr->make_copy(this));
	}
};

#endif
