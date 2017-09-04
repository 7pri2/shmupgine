#ifndef __SOUNDMANAGER_H__
#define __SOUNDMANAGER_H__

#include <map>
#include "singleton.h"

class soundmanager : public singleton<soundmanager> {
	friend class singleton<soundmanager>;
public:
	soundmanager();
	~soundmanager();

	void new_sound(std::string sname, std::string path);

private:
	soundmanager(const soundmanager&) {};
	soundmanager();
	~soundmanager();

	std::map<std::string, sf::Sound*> m_sounds;
};

#endif
