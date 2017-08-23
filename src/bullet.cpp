#include "bullet.h"
#include "graphicrenderer.h"
#include "physics.h"

bullet::bullet() : entity() {
	allocateAttribute<graphicrenderer>();
	allocateAttribute<physics>();
	getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::tex_bullet);
	getAttribute<graphicrenderer>()->sprite.setOrigin(sf::Vector2f(DEF_BULLET_SIZE/2, DEF_BULLET_SIZE/2));
}

bullet::bullet(scene* parent) : entity(parent), bullet() {
	allocateAttribute<graphicrenderer>();
	allocateAttribute<physics>();
	getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::tex_bullet);
	getAttribute<graphicrenderer>()->sprite.setOrigin(sf::Vector2f(DEF_BULLET_SIZE/2, DEF_BULLET_SIZE/2));
}

bullet::bullet(scene* parent, sf::Vector2f initial_position) : entity(parent, initial_position) {
	allocateAttribute<graphicrenderer>();
	allocateAttribute<physics>();
	getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::tex_bullet);
	getAttribute<graphicrenderer>()->sprite.setPosition(initial_position);
	getAttribute<graphicrenderer>()->sprite.setOrigin(sf::Vector2f(DEF_BULLET_SIZE/2, DEF_BULLET_SIZE/2));
}

bullet::bullet(sf::Vector2f initial_position) : entity(parent, initial_position) {
	allocateAttribute<graphicrenderer>();
	allocateAttribute<physics>();
	getAttribute<graphicrenderer>()->set_texture(*gmanager::tex_bullet);
	getAttribute<graphicrenderer>()->sprite.setPosition(initial_position);
}

bullet::~bullet() {
}
