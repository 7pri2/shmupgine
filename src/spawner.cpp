#include "spawner.h"
#include "entity.h"
#include "scene.h"

spawner::spawner(entity* parent) : attribute(parent) {
}

spawner::~spawner() {
}

void spawner::add_slot(std::string name) {
	m_spawnslots[name] = new spawnslot(this);
}

void spawner::set_profile(std::string slotname, entity* en) {
	m_spawnslots[slotname]->set_profile(en);
}

void spawner::set_spawn_at_parent(std::string slotname, bool state) {
	m_spawnslots[slotname]->f_spawn_at_parent = state;
}

void spawner::set_auto_spawn(std::string slotname, bool state) {
	m_spawnslots[slotname]->f_auto_spawn = state;
}

void spawner::add_group_to_join(std::string slotname, std::string groupname) {
	m_spawnslots[slotname]->add_group_to_join(groupname);
}

void spawner::set_cooldown(std::string slotname, int ms) {
	m_spawnslots[slotname]->ms_cooldown = ms;
}

void spawner::run() {
	for(std::map<std::string, spawnslot*>::iterator it = m_spawnslots.begin(); it != m_spawnslots.end(); ++it)
		it->second->run();
}

spawner* spawner::make_copy(entity* newparent) {
	spawner* ptr = new spawner(*this);
	ptr->parent = newparent;
	return ptr;
}

void spawner::spawn(std::string slot) {
	if(m_spawnslots[slot] != NULL)
		m_spawnslots[slot]->spawn();
}

void spawner::spawn_all() {
	for(std::map<std::string, spawnslot*>::iterator it = m_spawnslots.begin(); it != m_spawnslots.end(); ++it)
		it->second->spawn();
}

void spawner::enable_slot(std::string slotname) {
	m_spawnslots[slotname]->enabled = true;
}

void spawner::disable_slot(std::string slotname) {
	m_spawnslots[slotname]->enabled = false;
}

void spawner::set_song_to_play(std::string slotname, std::string songname) {
	m_spawnslots[slotname]->song_to_play = songname;
}
