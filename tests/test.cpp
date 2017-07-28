#include <iostream>
#include "shmupgine.h"

using namespace std;

int main() {
	shmupgine::init();
	gmanager::new_texture("btl", "bullet.png", 16, 16);
	
	scene sc1;
	
	entity *e2 = new entity(sf::Vector2f(100, 100));
	entity *e1 = new entity(sf::Vector2f(50, 50));
	entity *e3 = new entity(sf::Vector2f(0,0));;

	std::cout << e3;

	e3->allocate_attribute<physics>();
	e3->allocate_attribute<graphicrenderer>();
	e3->allocate_attribute<destructor>();
	e3->get_attribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["btl"]);
	e3->get_attribute<destructor>()->f_when_out_of_bounds = true;
	e3->get_attribute<physics>()->set_force(sf::Vector2f(0, -1));
	e3->get_attribute<physics>()->set_velocity(30);
	e3->get_attribute<destructor>()->add_collision_entity(e2);
	
	e1->allocate_attribute<controls>();
	e1->allocate_attribute<graphicrenderer>();
	e1->allocate_attribute<destructor>();
	e1->allocate_attribute<spawner>();
	e1->get_attribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["btl"]);
	e1->get_attribute<spawner>()->set_profile(e3);
	e1->get_attribute<spawner>()->spawn();

	e2->allocate_attribute<destructor>();
	e2->allocate_attribute<graphicrenderer>();
	e2->get_attribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["btl"]);

	sc1.add_entity(e1);
	sc1.add_entity(e2);
	sc1.run();
	shmupgine::close();
	return 0;
}
