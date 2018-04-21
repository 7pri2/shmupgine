#ifndef __SPAWNSLOT_H__
#define __SPAWNSLOT_H__	

#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include "attribute.h"

class entity;
class scene;
class spawner;

class spawnslot {
	friend class spawner;
public:
	spawnslot(spawner* parent);
	~spawnslot();

	bool	enabled;

	void	set_profile(entity* en);
	void	spawn();

	bool	f_spawn_at_parent;
	bool	f_auto_spawn;

	void	add_group_to_join(std::string groupname);
	void	add_song_to_play(std::string songname);

	int		ms_cooldown;

private:
	virtual void 			run();	
	virtual spawnslot*		make_copy(spawner* newparent);

	sf::Clock				clock;
	entity*					to_spawn;
	bool					f_spawn_requested;
	std::list<std::string>	m_groups_to_join_on_spawn;
	spawner*				parent;
	std::string				song_to_play;
};

#endif
