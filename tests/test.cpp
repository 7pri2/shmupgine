#include <iostream>
#include "shmupgine.h"

using namespace std;

int main() {
	shmupgine::init();
	gmanager::instance().new_texture("heros", "res/ship.png", 64, 64);
	gmanager::instance().new_texture("bullet", "res/bullet_fire.png", 32, 32);
	gmanager::instance().new_texture("enemy", "res/enemy_ship.png", 64, 112);

	scene sc1;
	
	entity *heros = new entity(sf::Vector2f(208, 800));
	entity *bullet = new entity;
	entity *enemy_bullet = new entity;
	entity *op1	= new entity(sf::Vector2f(208, 100));
	entity *_script = new entity;

	_script->allocate_attribute<script>();
	_script->get_attribute<script>()->set_loop_function(
		[&]() -> void {
			static int enemy_hp = 100;
			static int heros_hp = 100;

			if(sc1.entity_exists(heros)) {
				if(heros->get_attribute<destructor>()->collides(enemy_bullet))
					heros_hp -= 10;
				if(heros_hp <= 0)
					heros->get_attribute<destructor>()->destroy();
			}
			if(sc1.entity_exists(op1)) {
				if(op1->get_attribute<destructor>()->collides(bullet))
					enemy_hp -= 10;
				if(enemy_hp <= 0)
					op1->get_attribute<destructor>()->destroy();
			}
		});

	op1->allocate_attribute<graphicrenderer>();
	op1->allocate_attribute<spawner>();
	op1->allocate_attribute<destructor>();
	op1->get_attribute<graphicrenderer>()->set_texture("enemy");
	op1->get_attribute<spawner>()->set_profile(enemy_bullet);
	op1->get_attribute<spawner>()->f_auto_spawn = true;
	op1->get_attribute<spawner>()->ms_cooldown = 800;

	enemy_bullet->allocate_attribute<graphicrenderer>();
	enemy_bullet->allocate_attribute<physics>();
	enemy_bullet->allocate_attribute<destructor>();
	enemy_bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	enemy_bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	enemy_bullet->get_attribute<graphicrenderer>()->colorify(RGBA(200, 50, 50));
	enemy_bullet->get_attribute<physics>()->set_force(sf::Vector2f(0, 1));
	enemy_bullet->get_attribute<physics>()->set_velocity(120);
	enemy_bullet->get_attribute<destructor>()->add_collision_entity(heros);

	heros->allocate_attribute<graphicrenderer>();
	heros->allocate_attribute<controls>();
	heros->allocate_attribute<spawner>();
	heros->allocate_attribute<destructor>();
	heros->get_attribute<graphicrenderer>()->set_texture("heros");
	heros->get_attribute<spawner>()->set_profile(bullet);
	heros->get_attribute<spawner>()->ms_cooldown = 150;
	heros->get_attribute<controls>()->move_speed = 200;

	bullet->allocate_attribute<destructor>();
	bullet->allocate_attribute<graphicrenderer>();
	bullet->allocate_attribute<physics>();
	bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	bullet->get_attribute<physics>()->set_force(sf::Vector2f(0, -1));
	bullet->get_attribute<physics>()->set_velocity(160);
	bullet->get_attribute<destructor>()->add_collision_entity(op1);

	sc1.add_entity(heros);
	sc1.add_entity(op1);
	sc1.add_entity(_script);
	sc1.run();

	delete heros;
	delete bullet;
	delete enemy_bullet;

	return 0;
}
