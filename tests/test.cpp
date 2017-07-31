#include <iostream>
#include "shmupgine.h"

using namespace std;

int main() {
	shmupgine::init();
	gmanager::instance().new_texture("heros", "./res/ship.png", 64, 64);
	gmanager::instance().new_texture("bullet", "./res/bullet_fire.png", 32, 32);
	gmanager::instance().new_texture("enemy", "./res/enemy_ship.png", 64, 112);

	scene sc1;
	
	entity *heros = new entity(sf::Vector2f(208, 800));
	entity *bullet = new entity;
	entity *enemy_bullet = new entity;
	entity *op1	= new entity(sf::Vector2f(0, 100));

	script sc_hp = [&]() -> void {
		static int enemy_hp = 100;
		static int heros_hp = 100;
		
#ifdef DEBUG
		cout << "Enemy = " << enemy_hp << "\nHeros = " << heros_hp << endl;
#endif

		if(sc1.entity_exists(heros)) {
			if(sc1.group_collides("enemy_bullets", heros))
				heros_hp -= 10;
			if(heros_hp <= 0)
				heros->get_attribute<destructor>()->destroy();
		}
		if(sc1.entity_exists(op1)) {
			if(sc1.group_collides("heros_bullets", op1))
				enemy_hp -= 10;
			if(enemy_hp <= 0)
				op1->get_attribute<destructor>()->destroy();
		}
	};

	script sc_movements = [&]() -> void {
		if(sc1.entity_exists(op1)) {
			if(op1->get_attribute<destructor>()->is_out_of_bounds())
				op1->get_attribute<physics>()->rotate_force(180);
		}
	};

	op1->allocate_attribute<graphicrenderer>();
	op1->allocate_attribute<spawner>();
	op1->allocate_attribute<destructor>();
	op1->allocate_attribute<physics>();
	op1->get_attribute<physics>()->set_velocity(90);
	op1->get_attribute<graphicrenderer>()->set_texture("enemy");
	op1->get_attribute<spawner>()->set_profile(enemy_bullet);
	op1->get_attribute<spawner>()->f_auto_spawn = true;
	op1->get_attribute<spawner>()->ms_cooldown = 800;
	op1->get_attribute<spawner>()->add_group_to_join("enemy_bullets");

	enemy_bullet->allocate_attribute<graphicrenderer>();
	enemy_bullet->allocate_attribute<physics>();
	enemy_bullet->allocate_attribute<destructor>();
	enemy_bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	enemy_bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	enemy_bullet->get_attribute<graphicrenderer>()->colorify(RGBA(200, 50, 50));
	enemy_bullet->get_attribute<physics>()->set_force_angle(90);
	enemy_bullet->get_attribute<physics>()->set_velocity(120);
	enemy_bullet->get_attribute<destructor>()->add_collision_entity(heros);

	heros->allocate_attribute<graphicrenderer>();
	heros->allocate_attribute<controls>();
	heros->allocate_attribute<spawner>();
	heros->allocate_attribute<destructor>();
	heros->get_attribute<graphicrenderer>()->set_texture("heros");
	heros->get_attribute<controls>()->move_speed = 200;
	heros->get_attribute<spawner>()->set_profile(bullet);
	heros->get_attribute<spawner>()->ms_cooldown = 150;
	heros->get_attribute<spawner>()->add_group_to_join("heros_bullets");

	bullet->allocate_attribute<graphicrenderer>();
	bullet->allocate_attribute<physics>();
	bullet->allocate_attribute<destructor>();
	bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	bullet->get_attribute<physics>()->set_force_angle(270);
	bullet->get_attribute<physics>()->set_velocity(550);
	bullet->get_attribute<destructor>()->add_collision_entity(op1);

	sc1.add_script(sc_hp);
	sc1.add_script(sc_movements);

	sc1.add_entity(heros);
	sc1.add_entity(op1);
	sc1.run();

	delete bullet;
	delete enemy_bullet;

	return 0;
}
