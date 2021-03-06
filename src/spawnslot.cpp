#include "spawnslot.h"
#include "entity.h"
#include "scene.h"
#include "soundmanager.h"
#include "spawner.h"

spawnslot::spawnslot(spawner* parent) {
	to_spawn = NULL;
	f_spawn_at_parent = true;
	f_spawn_requested = false;
	f_auto_spawn = false;
	ms_cooldown = 250;
	clock.restart();
	enabled = true;
	this->parent = parent;
}

spawnslot::~spawnslot() {

}

void spawnslot::set_profile(entity* en) {
	to_spawn = en;
	to_spawn->parent = parent->parent->parent;
}

void spawnslot::spawn() {
	f_spawn_requested = true;
}

void spawnslot::run() {
	if(enabled && (f_auto_spawn || f_spawn_requested) && clock.getElapsedTime().asMilliseconds() >= ms_cooldown) {
		if(!song_to_play.empty())
			soundmanager::instance().play_sound(song_to_play);
		if(f_spawn_at_parent)
			to_spawn->set_position(parent->parent->get_position());
		entity* en = new entity(to_spawn);
		parent->parent->parent->add_entity(en);
		for(std::list<std::string>::iterator it = m_groups_to_join_on_spawn.begin(); it != m_groups_to_join_on_spawn.end(); ++it)
			parent->parent->parent->add_to_group(*it, en);
		f_spawn_requested = false;
		clock.restart();
	}
}

spawnslot* spawnslot::make_copy(spawner* newparent) {
	spawnslot* ptr = new spawnslot(*this);
	ptr->parent = newparent;
	return ptr;
}

void spawnslot::add_group_to_join(std::string groupname) {
	for(std::list<std::string>::iterator it = m_groups_to_join_on_spawn.begin(); it != m_groups_to_join_on_spawn.end(); ++it)
		if(*it == groupname)
			return;
	m_groups_to_join_on_spawn.push_back(groupname);
}
