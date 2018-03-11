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
	spawnslot*	get_slot(std::string name);
	void 		spawn(std::string slot);

private:
	virtual void		run();
	virtual spawner*	make_copy(entity* newparent);

	std::map<std::string, spawnslot*> m_spawnslots;
};

#endif

