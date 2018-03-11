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

spawnslot* spawner::get_slot(std::string name) {
	return m_spawnslots[name];
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
