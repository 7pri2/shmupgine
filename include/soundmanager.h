#ifndef __SOUNDMANAGER_H__
#define __SOUNDMANAGER_H__

#include <SFML/Audio.hpp>
#include <map>
#include "singleton.h"

/* Solution non optimisee temporaire */
typedef struct {
	sf::SoundBuffer m_buffer;
	sf::Sound		m_sound;
} sound;


/* On utilise un tableau de 'canaux' sonores pour jouer des sons simultanement; 
 * tant qu'un son est en cours de lecture, on passe au canal suivant jusqu'a en
 * trouver un libre et on le joue */
class soundmanager : public singleton<soundmanager> {
	friend class singleton<soundmanager>;
public:
	void	new_sound(std::string sname, std::string path);
	void	play_sound(std::string sname);

private:
	soundmanager(const soundmanager&) {};
	soundmanager();
	~soundmanager();

	std::map<std::string, std::string>	m_soundbank;
	sound	m_sound_channels[256];
};

#endif
