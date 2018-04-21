#include <iostream>
#include <cmath>
#include "shmupgine.h"

#define PLAYER_BULLETS_CD 100

using namespace std;

int main() {
	shmupgine::init();
	gmanager::instance().new_texture("heros", "./res/graphics/ship.png", 64, 64);
	gmanager::instance().new_texture("bullet", "./res/graphics/bullet_fire.png", 32, 32);
	gmanager::instance().new_texture("enemy", "./res/graphics/enemy_ship.png", 64, 112);
	soundmanager::instance().new_sound("explode", "./res/audio/explode.ogg");
	soundmanager::instance().new_sound("pop", "./res/audio/piou.ogg");

	scene sc1;
	
	entity *heros = new entity(208, 800);
	entity *bullet = new entity;
	entity *bullet2 = new entity;
	entity *bullet3 = new entity;
	entity *alt_bullet = new entity;
	entity *enemy_bullet = new entity;
	entity *op1	= new entity(50, 100);

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

	script rotate_bullets = [&]() -> void {
		static sf::Clock c;
		int rot_speed = 10;
		if(c.getElapsedTime().asMilliseconds() >= 1) {
			enemy_bullet->get_attribute<physics>()->rotate_force(rot_speed);
			//bullet2->get_attribute<physics>()->rotate_force(rot_speed);
			//bullet3->get_attribute<physics>()->rotate_force(rot_speed);
			c.restart();
		}
	};

	op1->allocate_attribute<movement>();
	op1->allocate_attribute<graphicrenderer>();
	op1->allocate_attribute<spawner>();
	op1->allocate_attribute<destructor>();
	op1->allocate_attribute<physics>();
	//op1->get_attribute<physics>()->set_velocity(90);
	op1->get_attribute<movement>()->set_curve(
		[](float t) -> float {
			return 240+sin(t)*240;
			//return 240+cos(t)*100;
		},
		[](float t) -> float {
			return t*0+100;//t*10;
		});
	//op1->get_attribute<movement>()->speed_factor = 100;
	op1->get_attribute<graphicrenderer>()->set_texture("enemy");
	op1->get_attribute<spawner>()->add_slot("enemy");
	op1->get_attribute<spawner>()->set_profile("enemy", enemy_bullet);
	op1->get_attribute<spawner>()->set_auto_spawn("enemy", true);
	op1->get_attribute<spawner>()->set_cooldown("enemy", 50);
	op1->get_attribute<spawner>()->add_group_to_join("enemy", "enemy_bullets");

	enemy_bullet->allocate_attribute<graphicrenderer>();
	enemy_bullet->allocate_attribute<physics>();
	enemy_bullet->allocate_attribute<destructor>();
	enemy_bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	enemy_bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	enemy_bullet->get_attribute<graphicrenderer>()->colorify(RGBA(200, 50, 50));
	enemy_bullet->get_attribute<physics>()->set_force_angle(90);
	enemy_bullet->get_attribute<physics>()->set_velocity(90);
	enemy_bullet->get_attribute<destructor>()->add_collision_entity(heros);

	heros->allocate_attribute<graphicrenderer>();
	heros->allocate_attribute<controls>();
	heros->allocate_attribute<spawner>();
	heros->allocate_attribute<destructor>();
	heros->get_attribute<graphicrenderer>()->set_texture("heros");
	heros->get_attribute<controls>()->move_speed = 200;
	heros->get_attribute<spawner>()->add_slot("bullet");
	heros->get_attribute<spawner>()->set_song_to_play("bullet", "pop");
	heros->get_attribute<spawner>()->set_profile("bullet", bullet);
	heros->get_attribute<spawner>()->set_cooldown("bullet", PLAYER_BULLETS_CD);
	heros->get_attribute<spawner>()->add_group_to_join("bullet", "heros_bullets");
	heros->get_attribute<spawner>()->add_slot("bullet2");
	heros->get_attribute<spawner>()->set_profile("bullet2", bullet2);
	heros->get_attribute<spawner>()->set_cooldown("bullet2", PLAYER_BULLETS_CD);
	heros->get_attribute<spawner>()->add_group_to_join("bullet2", "heros_bullets");
	heros->get_attribute<spawner>()->add_slot("bullet3");
	heros->get_attribute<spawner>()->set_profile("bullet3", bullet3);
	heros->get_attribute<spawner>()->set_cooldown("bullet3", PLAYER_BULLETS_CD);
	heros->get_attribute<spawner>()->add_group_to_join("bullet3", "heros_bullets");

	bullet->allocate_attribute<graphicrenderer>();
	bullet->allocate_attribute<physics>();
	bullet->allocate_attribute<destructor>();
	bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	bullet->get_attribute<physics>()->set_force_angle(270);
	bullet->get_attribute<physics>()->set_velocity(550);
	bullet->get_attribute<destructor>()->add_collision_entity(op1);

	bullet2->allocate_attribute<graphicrenderer>();
	bullet2->allocate_attribute<physics>();
	bullet2->allocate_attribute<destructor>();
	bullet2->get_attribute<destructor>()->f_when_out_of_bounds = true;
	bullet2->get_attribute<graphicrenderer>()->set_texture("bullet");
	bullet2->get_attribute<graphicrenderer>()->rotate(50);
	bullet2->get_attribute<physics>()->set_force_angle(290);
	bullet2->get_attribute<physics>()->set_velocity(550);
	bullet2->get_attribute<destructor>()->add_collision_entity(op1);

	bullet3->allocate_attribute<graphicrenderer>();
	bullet3->allocate_attribute<physics>();
	bullet3->allocate_attribute<destructor>();
	bullet3->get_attribute<destructor>()->f_when_out_of_bounds = true;
	bullet3->get_attribute<graphicrenderer>()->set_texture("bullet");
	bullet3->get_attribute<physics>()->set_force_angle(250);
	bullet2->get_attribute<graphicrenderer>()->rotate(-50);
	bullet3->get_attribute<physics>()->set_velocity(550);
	bullet3->get_attribute<destructor>()->add_collision_entity(op1);

	alt_bullet->allocate_attribute<movement>();
	alt_bullet->allocate_attribute<graphicrenderer>();
	alt_bullet->allocate_attribute<destructor>();
	alt_bullet->get_attribute<destructor>()->f_when_out_of_bounds = true;
	alt_bullet->get_attribute<graphicrenderer>()->set_texture("bullet");
	alt_bullet->get_attribute<graphicrenderer>()->colorify(RGBA(200, 50, 50));
	alt_bullet->get_attribute<destructor>()->add_collision_entity(heros);
	alt_bullet->get_attribute<movement>()->set_curve(
		[](float t) -> float {
			return sin(t)/2;
		},
		[](float t) -> float {
			return t/8;
		});
	alt_bullet->get_attribute<movement>()->speed_factor = 1;

	sc1.add_script(sc_heros_hp);
	sc1.add_script(sc_op1_hp);
	sc1.add_script(rotate_bullets);
	//sc1.add_script(sc_movements);

	sc1.add_entity(heros);
	sc1.add_entity(op1);
	sc1.run();

	delete bullet;
	delete alt_bullet;
	delete enemy_bullet;

	return 0;
}
