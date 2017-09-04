#include "soundmanager.h"

soundmanager::soundmanager() {

}

soundmanager::~soundmanager() {

}

void soundmanager::new_sound(std::string sname, std::string path) {
	sf::Sound* s;
	s.loadFromFile(path);
	m_sounds[sname] = s;
}
