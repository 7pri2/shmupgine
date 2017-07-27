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

	e3->allocateAttribute<physics>();
	e3->allocateAttribute<graphicrenderer>();
	e3->allocateAttribute<destructor>();
	e3->getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["btl"]);
	e3->getAttribute<destructor>()->whenOutOfBounds = true;
	e3->getAttribute<physics>()->setForce(sf::Vector2f(0, -1));
	e3->getAttribute<physics>()->setVelocity(30);
	e3->getAttribute<destructor>()->addCollision_entity(e2);
	
	e1->allocateAttribute<controls>();
	e1->allocateAttribute<graphicrenderer>();
	e1->allocateAttribute<destructor>();
	e1->allocateAttribute<spawner>();
	e1->getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["btl"]);
	e1->getAttribute<spawner>()->set_profile(e3);
	e1->getAttribute<spawner>()->spawn();

	e2->allocateAttribute<destructor>();
	e2->allocateAttribute<graphicrenderer>();
	e2->getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures["btl"]);

	sc1.add_entity(e1);
	sc1.add_entity(e2);
	sc1.run();
	shmupgine::close();
	return 0;
}
