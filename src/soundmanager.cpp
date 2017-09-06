#include "soundmanager.h"

soundmanager::soundmanager() {

}

soundmanager::~soundmanager() {

}

void soundmanager::new_sound(std::string sname, std::string path) {
	m_soundbank[sname] = path;
}

void soundmanager::play_sound(std::string sname) {
	for(int i = 0; i < 256; ++i)
		if(m_sound_channels[i].m_sound.getStatus() != sf::SoundSource::Status::Playing)
			if(m_sound_channels[i].m_buffer.loadFromFile(m_soundbank[sname])) {
				m_sound_channels[i].m_sound.setBuffer(m_sound_channels[i].m_buffer);
				m_sound_channels[i].m_sound.play();
				break;
			}
}
