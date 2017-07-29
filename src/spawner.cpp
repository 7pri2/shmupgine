#include "spawner.h"
#include "entity.h"
#include "scene.h"

spawner::spawner(entity* parent) : attribute(parent) {
	to_spawn = NULL;
	f_spawn_at_parent = true;
	f_spawn_requested = false;
	f_auto_spawn = false;
	ms_cooldown = 250;
	clock.restart();
}

spawner::~spawner() {

}

void spawner::set_profile(entity* en) {
	to_spawn = en;
	to_spawn->parent = parent->parent;
}

void spawner::spawn() {
	f_spawn_requested = true;
}

void spawner::run() {
#ifdef DEBUG
	std::cout << "\tspawner... ";
#endif
	if((f_auto_spawn || f_spawn_requested) && clock.getElapsedTime().asMilliseconds() >= ms_cooldown) {
#ifdef DEBUG
		std::cout << debug::pattr("Spawn requested");
#endif
		if(f_spawn_at_parent)
			to_spawn->set_position(parent->get_position());
		parent->parent->add_entity(new entity(to_spawn));
		f_spawn_requested = false;
		clock.restart();
	}
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

spawner* spawner::make_copy(entity* newparent) {
	spawner* ptr = new spawner(*this);
	ptr->parent = newparent;
	return ptr;
}
