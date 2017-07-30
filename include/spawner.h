#ifndef __SPAWNER_H__
#define __SPAWNER_H__	

#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include "attribute.h"

class entity;
class scene;

class spawner : public attribute {
public:
	spawner(entity* parent);
	~spawner();

	void	set_profile(entity* en);
	void	spawn();

	bool	f_spawn_at_parent;
	bool	f_auto_spawn;

	void	add_group_to_join(std::string groupname);

	int		ms_cooldown;

private:
	virtual void 			run();	
	virtual spawner*		make_copy(entity* newparent);

	sf::Clock				clock;
	entity*					to_spawn;
	bool					f_spawn_requested;
	std::list<std::string>	m_groups_to_join_on_spawn;
};

#endif

