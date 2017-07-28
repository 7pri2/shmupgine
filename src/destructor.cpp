#include "destructor.h"
#include "entity.h"
#include "scene.h"
#include "graphicrenderer.h"

destructor::destructor() : attribute() {
	f_when_out_of_bounds = false;
	m_destruction_requested = false;
}

destructor::destructor(entity* parent) : attribute(parent) {
	f_when_out_of_bounds = false;
	m_destruction_requested = false;
}

destructor::~destructor() {
}

void destructor::run() {
	scene* parent_scene = parent->parent;
#ifdef DEBUG
	std::cout << "\tdestructor...";
#endif
	if(!m_destruction_requested) {	// Optimisation
		if(f_when_out_of_bounds)
			if(	parent->get_position().x > shmupgine::w_width  || parent->get_position().x < 0
			||	parent->get_position().y > shmupgine::w_height || parent->get_position().y < 0 ) {
#ifdef DEBUG
				std::cout << debug::pattr("\n\tout of bounds, destruction will be requested. ");
#endif
				parent_scene->remove_entity(parent);
			}
		for(std::list<entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it) {
			if(	parent_scene->get_entity(*it) != NULL
				&& parent->get_attribute<graphicrenderer>() != NULL 
				&& (*it)->get_attribute<graphicrenderer>() != NULL 
				&& parent->get_attribute<graphicrenderer>()->sprite.getGlobalBounds().intersects((*it)->get_attribute<graphicrenderer>()->sprite.getGlobalBounds())) {
#ifdef DEBUG
				std::cout << debug::attr << "\n\tcollision with" << *it << ", destruction will be requested." << debug::reset << " ";
#endif
				destroy();
			}
		}
		for(std::list<std::string>::iterator g_it = m_groups.begin(); g_it != m_groups.end(); ++g_it) {
			std::list<entity*> current_group = parent_scene->get_group(*g_it);
			for(std::list<entity*>::iterator it = current_group.begin(); it != current_group.end(); ++it) {
				if(	parent_scene->get_entity(*it) != NULL
					&& parent->get_attribute<graphicrenderer>() != NULL 
					&& (*it)->get_attribute<graphicrenderer>() != NULL 
					&& parent->get_attribute<graphicrenderer>()->sprite.getGlobalBounds().intersects((*it)->get_attribute<graphicrenderer>()->sprite.getGlobalBounds())) {
#ifdef DEBUG
					std::cout << debug::attr << "\n\tcollision with" << *it << ", destruction will be requested." << debug::reset << " ";
#endif
					destroy();
				}
			}
		}
	}
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

void destructor::add_collision_entity(entity* en) {
	m_entities.push_back(en);
}

void destructor::add_collision_group(std::string group) {
	m_groups.push_back(group);
}

bool destructor::is_out_of_bounds() {
	return parent->get_position().x > shmupgine::w_width || parent->get_position().x < 0
		||	parent->get_position().y > shmupgine::w_height || parent->get_position().y < 0;
}

bool destructor::collides(entity* en) {
	if(	!m_destruction_requested
		&& parent->get_attribute<graphicrenderer>() != NULL 
		&& en->get_attribute<graphicrenderer>() != NULL 
		&& parent->get_attribute<graphicrenderer>()->sprite.getGlobalBounds().intersects(en->get_attribute<graphicrenderer>()->sprite.getGlobalBounds())) {
		return true;
	} 	else return false;
}

bool destructor::collides_something() {
	if(!m_destruction_requested)
		for(std::list<entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			if(parent->parent->get_entity(*it) != NULL
				&& parent->get_attribute<graphicrenderer>() != NULL 
				&& (*it)->get_attribute<graphicrenderer>() != NULL 
				&& parent->get_attribute<graphicrenderer>()->sprite.getGlobalBounds().intersects((*it)->get_attribute<graphicrenderer>()->sprite.getGlobalBounds()))
				return true;
	return false;
}

void destructor::destroy() {
	if(!m_destruction_requested) {
		m_destruction_requested = true;
		parent->parent->remove_entity(parent);
	}
}

destructor* destructor::make_copy(entity* newparent) {
	destructor* ptr = new destructor(*this);
	ptr->parent = newparent;
	return ptr;
}
