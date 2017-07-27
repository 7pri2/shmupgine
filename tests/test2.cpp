#include <iostream>
#include "shmupgine.h"

using namespace std;

int main() {
	shmupgine::init();
	gmanager::new_texture("heros", "res/ship.png", 64, 64);
	gmanager::new_texture("bullet", "res/bullet.png", 48, 48);

	scene sc1;
	
	entity *heros = new entity(sf::Vector2f(208, 800));
	entity *bullet = new entity;

	heros->allocateAttribute<graphicrenderer>();
	heros->allocateAttribute<controls>();
	heros->allocateAttribute<spawner>();
	heros->getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["heros"]);
	heros->getAttribute<spawner>()->set_profile(bullet);
	heros->getAttribute<controls>()->move_speed = 200;

	bullet->allocateAttribute<destructor>();
	bullet->allocateAttribute<graphicrenderer>();
	bullet->allocateAttribute<physics>();
	bullet->getAttribute<destructor>()->whenOutOfBounds = true;
	bullet->getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["bullet"]);
	bullet->getAttribute<physics>()->setForce(sf::Vector2f(0, -1));
	bullet->getAttribute<physics>()->setVelocity(160);

	sc1.add_entity(heros);
	sc1.run();
	shmupgine::close();
	return 0;
}
