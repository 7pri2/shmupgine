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
		entity* en = new entity(to_spawn);
		parent->parent->add_entity(en);
		for(std::list<std::string>::iterator it = m_groups_to_join_on_spawn.begin(); it != m_groups_to_join_on_spawn.end(); ++it)
			parent->parent->add_to_group(*it, en);
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

void spawner::add_group_to_join(std::string groupname) {
	for(std::list<std::string>::iterator it = m_groups_to_join_on_spawn.begin(); it != m_groups_to_join_on_spawn.end(); ++it)
		if(*it == groupname)
			return;
	m_groups_to_join_on_spawn.push_back(groupname);
}
