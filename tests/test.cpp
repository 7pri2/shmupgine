#include <iostream>
#include "shmupgine.h"

using namespace std;

int main() {
	shmupgine::init();
	gmanager::instance().new_texture("heros", "res/ship.png", 64, 64);
	gmanager::instance().new_texture("bullet", "res/bullet_fire.png", 32, 32);

	scene sc1;
	
	entity *heros = new entity(sf::Vector2f(208, 800));
	entity *bullet = new entity;

	heros->allocate_attribute<graphicrenderer>();
	heros->allocate_attribute<controls>();
	heros->allocate_attribute<spawner>();
	heros->get_attribute<graphicrenderer>()->set_texture("heros");
	heros->get_attribute<spawner>()->set_profile(bullet);
	heros->get_attribute<controls>()->move_speed = 200;

	bullet->allocate_attribute<destructor>();
	bullet->allocate_attribute<graphicrenderer>();
	bullet->allocate_attribute<physics>();
	bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	bullet->get_attribute<physics>()->set_force(sf::Vector2f(0, -1));
	bullet->get_attribute<physics>()->set_velocity(160);

	sc1.add_entity(heros);
	sc1.run();

	delete heros;
	delete bullet;

	return 0;
}
