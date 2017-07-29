#include "scene.h"
#include "systems.h"
#include "entity.h"
#include "destructor.h"

scene::scene() {}

scene::~scene() {}

void scene::update() {
	shmupgine::window.clear();
	run_attributes();
	shmupgine::window.display();
	remove_entities();
}

void scene::run_attributes() {
#ifdef DEBUG
	std::cout << debug::ptitle("===== Loop =====\n");
#endif
	for(std::list<entity*>::iterator it = scene::m_entities.begin(); it != scene::m_entities.end(); ++it)
		(*it)->run_attributes();
}

void scene::run() {
#ifdef DEBUG
	sf::Clock	fps_clock;
	int 		fps = 0, last_fps = fps;
	fps_clock.restart();
#endif
	while(shmupgine::window.isOpen()) {
		sf::Event event;
		while (shmupgine::window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				shmupgine::window.close();
		}
#ifdef DEBUG
		fps++;
		std::cout << debug::scene << "\nFPS : " << last_fps << "\n" << debug::reset;
		if(fps_clock.getElapsedTime().asMilliseconds() >= 1000) {
			last_fps = fps;
			fps = 0;
			fps_clock.restart();
		}
#endif
		scene::update();
		shmupgine::clock.restart();
	}
}

void scene::add_entity(entity* en) {
#ifdef DEBUG
	std::cout << debug::scene << en << " added to the scene\n" << debug::reset;
#endif
	en->parent = this;
	scene::m_entities.push_back(en);
}

void scene::remove_entity(entity* en) {
#ifdef DEBUG
	std::cout << "\n" << debug::scene << en << " added to suppression list." << debug::reset;
#endif
	m_to_be_removed.push_back(en);
}

void scene::remove_entities() {
	while(!m_to_be_removed.empty()) {
#ifdef DEBUG
		std::cout << debug::scene << m_to_be_removed.back() << " removed from the scene.\n" << debug::reset;
#endif
		scene::m_entities.remove(m_to_be_removed.back());
		delete m_to_be_removed.back();
		m_to_be_removed.pop_back();
	}
}

bool	scene::entity_exists(entity* en) {
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
