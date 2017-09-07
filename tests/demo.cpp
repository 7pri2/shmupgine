#include <iostream>
#include <cmath>
#include "shmupgine.h"

using namespace std;

int main() {
	shmupgine::init();
	gmanager::instance().new_texture("heros", "./res/graphics/ship.png", 64, 64);
	gmanager::instance().new_texture("bullet", "./res/graphics/bullet_fire.png", 32, 32);
	gmanager::instance().new_texture("enemy", "./res/graphics/enemy_ship.png", 64, 112);
	soundmanager::instance().new_sound("explode", "./res/audio/explode.ogg");

	scene sc1;
	
	entity *heros = new entity(sf::Vector2f(208, 800));
	entity *bullet = new entity;
	entity *alt_bullet = new entity;
	entity *enemy_bullet = new entity;
	entity *op1	= new entity(sf::Vector2f(50, 100));

	script sc_heros_hp = [&]() -> void {
		static int heros_hp = 100;
		if(sc1.entity_exists(heros) && heros->get_attribute<graphicrenderer>()->blink_finished()) {
			if(heros_hp <= 0)
				heros->get_attribute<destructor>()->destroy();
			if(sc1.group_collides("enemy_bullets", heros)) {
				soundmanager::instance().play_sound("explode");
				heros_hp -= 10;
				heros->get_attribute<graphicrenderer>()->blink();
			}
		}
	};

	script sc_op1_hp = [&]() -> void {
		static int op1_hp = 100;
		if(sc1.entity_exists(op1) && op1->get_attribute<graphicrenderer>()->blink_finished()) {
			if(op1_hp <= 0)
				op1->get_attribute<destructor>()->destroy();
			if(sc1.group_collides("heros_bullets", op1)) {
				soundmanager::instance().play_sound("explode");
				op1_hp -= 10;
				op1->get_attribute<graphicrenderer>()->blink();
			}
		}
	};

	op1->allocate_attribute<route>();
	op1->allocate_attribute<graphicrenderer>();
	op1->allocate_attribute<spawner>();
	op1->allocate_attribute<destructor>();
	op1->allocate_attribute<physics>();
	//op1->get_attribute<physics>()->set_velocity(90);
	op1->get_attribute<route>()->set_curve(
		[](float t) -> float {
			//return 240+sin(t)*240;
			return 240+cos(tan(t))*100;
		},
		[](float t) -> float {
			return t*10;
		});
	//op1->get_attribute<route>()->speed_factor = 100;
	op1->get_attribute<graphicrenderer>()->set_texture("enemy");
	op1->get_attribute<spawner>()->set_profile(enemy_bullet);
	op1->get_attribute<spawner>()->f_auto_spawn = true;
	op1->get_attribute<spawner>()->ms_cooldown = 400;
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

	alt_bullet->allocate_attribute<route>();
	alt_bullet->allocate_attribute<graphicrenderer>();
	alt_bullet->allocate_attribute<destructor>();
	alt_bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	alt_bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	alt_bullet->get_attribute<graphicrenderer>()->colorify(RGBA(200, 50, 50));
	alt_bullet->get_attribute<destructor>()->add_collision_entity(heros);
	alt_bullet->get_attribute<route>()->set_curve(
		[](float t) -> float {
			return sin(t)/2;
		},
		[](float t) -> float {
			return t/8;
		});
	alt_bullet->get_attribute<route>()->speed_factor = 1;

	sc1.add_script(sc_heros_hp);
	sc1.add_script(sc_op1_hp);
	//sc1.add_script(sc_movements);

	sc1.add_entity(heros);
	sc1.add_entity(op1);
	sc1.run();

	delete bullet;
	delete alt_bullet;
	delete enemy_bullet;

	return 0;
}
