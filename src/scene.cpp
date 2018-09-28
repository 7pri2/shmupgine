#include "scene.h"
#include "systems.h"
#include "entity.h"
#include "destructor.h"

scene::scene() {
	m_alive = false;
}

scene::~scene() {}

void scene::update() {
	shmupgine::window.clear();
	run_attributes();
	run_scripts();
	shmupgine::window.display();
	remove_entities();
}

void scene::run_attributes() {
	for(std::list<entity*>::iterator it = scene::m_entities.begin(); it != scene::m_entities.end(); ++it)
		(*it)->run_attributes();
}

void scene::run() {
	this->m_alive = true;
	while(m_alive && shmupgine::window.isOpen()) {
		sf::Event event;
		while (shmupgine::window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				shmupgine::window.close();
		}
		scene::update();
		shmupgine::clock.restart();
	}
}

void scene::terminate() {
	m_alive = false;
}

void scene::add_entity(entity* en) {
	en->parent = this;
	scene::m_entities.push_back(en);
}

void scene::remove_entity(entity* en) {
	if(m_alive) { // We put the entity on top of the remove list
		//fprintf(stderr, "Scene puts entity%p to the remove list\n", (void*)en);
		if(std::find(m_to_be_removed.begin(), m_to_be_removed.end(), en) == m_to_be_removed.end())
			m_to_be_removed.push_back(en);
	} else { // We can remove it now
		m_entities.remove(en);
		remove_from_all_groups(en);
	}
}

void scene::remove_entities() {
	while(!m_to_be_removed.empty()) {
		m_entities.remove(m_to_be_removed.back());
		remove_from_all_groups(m_to_be_removed.back());
		//fprintf(stderr, "Scene deletes entity %p\n", (void*)m_to_be_removed.back());
		//delete m_to_be_removed.back(); // We may not want to free the entity
		m_to_be_removed.pop_back();
	}
}

bool scene::entity_exists(entity* en) {
	for(std::list<entity*>::iterator it = scene::m_entities.begin(); it != scene::m_entities.end(); ++it)
		if(*it == en)
			return true;
	return false;
}

void scene::add_to_group(std::string groupname, entity* en) {
	if(!belongs_to_group(groupname, en))
		m_groups[groupname].push_back(en);
}

void scene::remove_from_group(std::string groupname, entity* en) {
	for(group::iterator it = m_groups[groupname].begin(); it != m_groups[groupname].end(); ++it)
		if(*it == en) {
			m_groups[groupname].erase(it);
			break;
		}
}

bool scene::belongs_to_group(std::string groupname, entity* en) {
	for(group::iterator it = m_groups[groupname].begin(); it != m_groups[groupname].end(); ++it)
		if(*it == en)
			return true;
	return false;
}

bool scene::group_collides(std::string groupname, entity* en) {
	for(group::iterator it = m_groups[groupname].begin(); it != m_groups[groupname].end(); ++it)
		if((*it)->get_attribute<destructor>() && (*it)->get_attribute<destructor>()->collides(en))
			return true;
	return false;
}

void scene::add_script(std::function<void()> script) {
	m_scripts.push_back(script);
}

void scene::run_scripts() {
	for(std::list<std::function<void()>>::iterator it = m_scripts.begin(); it != m_scripts.end(); ++it)
		(*it)();
}
	
void scene::remove_from_all_groups(entity* en) {
	for(std::map<std::string, group>::iterator it = m_groups.begin(); it != m_groups.end(); ++it)
		remove_from_group(it->first, en);
}
