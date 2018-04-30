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

/**
 * \class	destructor
 * \brief	This attribute is used to destruct entities in the scene. If it is 
 * 			attached to an entity, this entity can be destructed by this 
 * 			attribute. It also detects collisions in combination with the 
 * 			attribute **graphicrenderer**.
 *
 * # Collisions
 * Collisions are detected with two lists
 * - The list of entity collisions
 * - The list of groups collisions
 * The first list contains pointers to all the entities that trigger the 
 * destruction of the parent entity when it collides them.
 *
 * The second list contains all the groups of entities (_see **groups**_) that 
 * trigger the destruction of the parent entity when any entity of any group 
 * collides it.
 *
 * > Collisions may work only when all entities involved have the attribute 
 * > **graphicrenderer** attached to them.
 * This attribute also can destruct its parent when it goes out of scene bound 
 * or on demand as well (_see specific documentation for further informations_).
 */

class destructor : public attribute {
public:
	/// Default constructor
	destructor();

	/// Typical attribute-derived constructor
	destructor(entity* parent);

	/// Destructor
	~destructor();

	/**
	 * \brief	Adds an entity to the list of entity collisions
	 * \param	en	Entity pointer to be added to the list
	 */
	void	add_collision_entity(entity* en);

	/**
	 * \brief	Creates a new collision group for the parent entity
	 * \param	group	Name of the new group to be created
	 *
	 * Strings on this list are the names of the groups in which any entity 
	 * triggers the destruction of the parent entity. This functionnality exists
	 * for more dynamic scenes with entities that use the **spawner** attribute.
	 * Instead of spawning an entity and then update all destructors of all 
	 * entities, we put this newly spawner entity to a group (_see **spawner** 
	 * for further information_)and we set by default a collision rule for this 
	 * group for every entity involved.
	 *
	 * For example, we make a group of entities for all the enemies, a group for
	 * all enemies' bullets, a group for the hero's bullets; when an enemy 
	 * spawns a bullet, we add it to the right group, and so on for the hero's 
	 * bullet and only configure a collision rule in the heroe's bullet's 
	 * destructor for the group "enemies" and the oposite for their bullets. For
	 * further documentation, see the [wiki](https://github.com/7pri2/shmupgine/
	 * wiki/attr_destructor).
	 */
	void	add_collision_group(std::string group);

	/**
	 * \brief	Switch which indicates whether the entity is going to be 
	 * 			destructed when out of bounds or not
	 */
	bool 	f_when_out_of_bounds;

	/**
	 * \brief	Allows us to know if the parent entity is out of scene bounds
	 * \return	**true** if the entity is out of bounds, **false** otherwise
	 */
	bool	is_out_of_bounds();

	/**
	 * \brief	Know if the entity in parameter collides with the parent entity
	 * \param	en	Entity we want to check the collision with 
	 * \return	**true** if the entity actually collides with the parent entity,
	 * 			**false** otherwise
	 * \warning	The parent entity must have the attribute **graphicrenderer** 
	 * attached to it in order to work.
	 */
	bool	collides(entity* en);

	/**
	 * \brief	Know if the parent entity collides with any entity in its two 
	 * 			lists
	 * \return	**true** if the entity actually collides anything on its lists,
	 * 			**false** otherwise
	 * \warning	The parent entity must have the attribute **graphicrenderer** 
	 * attached to it in order to work.
	 */
	bool	collides_something();

	/// Commands the destruction of the parent entity
	void 	destroy();

private:
	/// Typical attribute-derived method run
	virtual void 			run();

	/// Typical attribute-derived method make_copy
	virtual destructor*		make_copy(entity* newparent);

	/**
	 * \brief	Flag that tells if the destruction of the parent has already 
	 * 			been registered for destruction
	 */
	bool					m_destruction_requested;

	/// List of entities on which the parent entity is destructed on collision
	std::list<entity*>		m_entities;

	/**
	 * \brief	List of groups on which the parent entity is destructed on 
	 * collision with any entity in one of these groups
	 */
	std::list<std::string>	m_groups;
};

#endif
