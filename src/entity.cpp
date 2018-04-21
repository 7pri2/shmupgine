#include "entity.h" 
#include "scene.h"
#include "graphicrenderer.h"

entity::entity() {
	position = sf::Vector2f(0, 0);
	parent = NULL;
}

entity::entity(entity* en) {
	parent = en->parent;
	position = en->position;
	for(attr_table::iterator it = en->attributes.begin(); it != en->attributes.end(); ++it)
		allocate_attribute(*it);
}

entity::entity(scene* parent) : entity() {
	this->parent = parent;
}
	
entity::entity(scene* parent, sf::Vector2f initial_position) : entity(parent) {
	position = initial_position;
}

entity::entity(scene* parent, float ix, float iy) : entity(parent, sf::Vector2f(ix, iy)) {
}

entity::entity(sf::Vector2f initial_position) : entity() {
	position = initial_position;
}

entity::entity(float ix, float iy) : entity(sf::Vector2f(ix, iy)) {
}

entity::~entity() {
	for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it) {
		fprintf(stderr, "\tEntity %p deletes attribute %p.\n", (void*)this, (void*)(*it));
		delete *it;
	}
}

void entity::run_attributes() {
	for(attr_table::iterator it = attributes.begin(); it != attributes.end(); ++it)
		if((*it)->enabled)
			(*it)->run();
}
	
void entity::move(sf::Vector2f offset) {
	position += offset;
	if(get_attribute<graphicrenderer>() != NULL)
		get_attribute<graphicrenderer>()->m_sprite.setPosition(position);
}

void entity::move(float x, float y) {
	this->move(sf::Vector2f(x,y));
}

void entity::set_position(sf::Vector2f pos) {
	position = pos;
	if(get_attribute<graphicrenderer>() != NULL)
		get_attribute<graphicrenderer>()->m_sprite.setPosition(position);
}

void entity::set_position(float x, float y) {
	this->set_position(sf::Vector2f(x, y));
}

sf::Vector2f entity::get_position() const {
	return position;
}
