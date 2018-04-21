#ifndef __SPAWNER_H__
#define __SPAWNER_H__	

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "attribute.h"
#include "spawnslot.h"

class entity;
class scene;

class spawner : public attribute {
	friend class spawnslot;
public:
	spawner(entity* parent);
	~spawner();

	void 		add_slot(std::string name);
	void		spawn_all();

	void		set_profile(std::string slotname, entity* en);
	void		set_spawn_at_parent(std::string slotname, bool state);
	void		set_auto_spawn(std::string slotname, bool state);
	void		add_group_to_join(std::string slotname, std::string groupname);
	void		set_cooldown(std::string slotname, int ms);
	void		enable_slot(std::string slotname);
	void		disable_slot(std::string slotname);
	void		set_song_to_play(std::string slotname, std::string songname);
	void 		spawn(std::string slot);

private:
	virtual void		run();
	virtual spawner*	make_copy(entity* newparent);

	std::map<std::string, spawnslot*> m_spawnslots;
};

#endif

