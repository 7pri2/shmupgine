/**
 * \file	attribute.h
 * \brief	This file contains the definition of `attribute' class which is one
 * 			the three main classes of the project
 * \author	Cyprien Eymond Laritaz
 */

#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__	

class entity;
class scene;

/**
 * \class	attribute
 * \brief	An attribute is a component for entities. It is derived into other 
 * 			inherited classes that do specialized things (like graphic
 * 			rendering, control management, etc...). It was made to be added do
 * 			a parent entity to characterize it
 *
 * An attribute is an element that we add to an entity. There are some and they 
 * all have a particular purpose. Some of their behaviours rely on other 
 * attributes. 
 * For example, an entity is nothing but the sum of the attributes attached to 
 * it. Without attributes, it is only a position: no movement, no collision, no 
 * sprite, etc... So that an entity with the attribute **control** can be 
 * considered as the "hero" of the scene because it is controlled by the player.
 *
 * ### Guide
 * #### Use an attribute
 * > In this guide, we will use the given entity `en`.
 * To use an attribute, you must know to what entity you want to attach it. Once
 * you have an entity, you must proceed in two steps:
 * 1. you embed it with attributes by calling the method `allocate_attribute<T> 
 * ()`
 * 2. you personnalize the attributes by getting the allocated attributes and 
 * operate on it, with the method `get_attribute<T> ()`
 *
 * > Replace *T* with the type of the attribute you want to add, for example, in
 * > the case of the attribute **physics**, do `en->allocate_attribute<physics>
 * > ();`
 *
 * When you get an attribute with `get_attribute<T> ()`, you can use all its 
 * public methods and public attributes to tweak it, for example with the 
 * attribute **physics**: `en->get_attribute<physics>()->set_velocity(100);`
 *
 * > Go to [wiki](https://github.com/7pri2/shmupgine/wiki/class_attribute) for 
 * > further informations
 *
 * #### Create an attribute
 * In order to create your own attribute, you must create a class that inherits 
 * from the classe **attribute**. It must implement the constructor that takes 
 * the *parent entity* to be attached to as parameter.
 *
 * Then you have to implement two virtual methods
 * - run
 * - make_copy
 *
 * ##### run
 * The main method of an attribute (see after for further documentation). It is 
 * private because it is meant to be called by the parent entity. You do all the
 * behaviour your attribute here. Keep in mind that any blocking behaviour in 
 * there will cause the entire game to wait for the end of this function.
 *
 * ##### make_copy
 * This method is useful for making copies and is mainly used in the attribute 
 * **spawner**.
 *
 * > See the [wiki](https://github.com/7pri2/shmupgine/wiki/class_attribute) to 
 * > get the full documentation on how to implement those two methods properly
 */
class attribute {
	friend class entity;
public:
	/// Default constructor
	attribute();

	/**
	 * \brief	Constructor which allows the attribute to be attached to an 
	 * 			entity directly
	 * \param	parent	Entity the attribute will be attached to
	 */
	attribute(entity* parent);

	/// Destructor
	virtual ~attribute() {};

	/**
	 * \brief	Switch which indicates whether the attribute is processed by the engine 
	 * 			when the parent entity is processed
	 */
	bool				enabled;

protected:
	/// Useful for making copies of the good type because of the templates
	virtual attribute*	make_copy(entity* newparent) = 0;
	
	/**
	 * Main method of the class; it is called by the parent entity in order to 
	 * process the attribute. Every inherited class does almost all the job in 
	 * their implementation of this method. (So this is where to focus when 
	 * creating a custom attribute)
	 */
	virtual void		run();

	/// Pointer to parent entity in order to let attributes interoperate
	entity*				parent;
};

#endif
