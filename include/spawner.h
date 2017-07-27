#ifndef __SPAWNER_H__
#define __SPAWNER_H__	

#include "attribute.h"
#include <SFML/Graphics.hpp>

class entity;
class scene;

class spawner : public attribute {
public:
	spawner(entity* parent);
	~spawner();

	void	set_profile(entity* en);
	void	spawn();

	bool	f_spawn_at_parent;

private:
	virtual void 		run();	
	virtual spawner*	make_copy(entity* newparent);

	int			ms_cooldown;
	sf::Clock	clock;
	entity*		to_spawn;
	bool		f_spawn_requested;
};

#endif

