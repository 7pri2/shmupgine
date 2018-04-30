#include "shmupgine.h"
#include "CuTest.h"

int main() {
	shmupgine::init();
	scene sc;
	entity *en = new entity;
	entity *en2 = new entity;
	entity *nen = new entity;

	// add_entity
	sc.add_entity(en);
	sc.add_entity(en2);

	// remove_entity
	sc.remove_entity(en);	// Entite presente
	sc.remove_entity(en2);	// Entite presente
	sc.add_entity(en2);		// On la rajoute apres
	sc.remove_entity(NULL);	// Entite nulle
	sc.remove_entity(nen);	// Entite non presente

	// entity_exists
	assert(sc.entity_exists(en) == false);
	assert(sc.entity_exists(en2) == true);
	assert(sc.entity_exists(NULL) == false);
	assert(sc.entity_exists(nen) == false);

	// add_to_group
	sc.add_to_group("group1", en);
	sc.add_to_group("group2", en2);

	// belongs_to_group (1)
	assert(sc.belongs_to_group("group1", en) == true);
	assert(sc.belongs_to_group("group2", en2) == true);
	assert(sc.belongs_to_group("group1", nen) == false);
	assert(sc.belongs_to_group("group2", en) == false);
	assert(sc.belongs_to_group("group1", en2) == false);
	assert(sc.belongs_to_group("group3", en) == false);
	assert(sc.belongs_to_group("group1", NULL) == false);

	// remove_from_group
	sc.remove_from_group("group1", en);
	sc.remove_from_group("group2", en);
	sc.remove_from_group("group1", NULL);
	sc.remove_from_group("group3", NULL);
	sc.remove_from_group("group1", nen);
	
	sc.add_to_group("group1", en); // On teste la remise en scene

	// belongs_to_group (2)
	assert(sc.belongs_to_group("group1", en) == true);
	assert(sc.belongs_to_group("group2", en2) == true);
	assert(sc.belongs_to_group("group1", nen) == false);
	assert(sc.belongs_to_group("group2", en) == false);
	assert(sc.belongs_to_group("group1", en2) == false);
	assert(sc.belongs_to_group("group3", en) == false);
	assert(sc.belongs_to_group("group1", NULL) == false);

	// remove_from_all_groups (1)
	sc.add_to_group("group2", en);
	sc.add_to_group("group3", en);
	assert(sc.belongs_to_group("group2", en) == true);
	assert(sc.belongs_to_group("group3", en) == true);
	sc.remove_from_all_groups(en);
	sc.remove_from_all_groups(nen);
	sc.remove_from_all_groups(NULL);

	// belongs_to_group (3)
	assert(sc.belongs_to_group("group1", en) == false);
	assert(sc.belongs_to_group("group2", en2) == true);
	assert(sc.belongs_to_group("group2", en) == false);
	assert(sc.belongs_to_group("group3", en) == false);

	// group_collides

/// Avec la fonction run (on passe par une suppression delayee)
	// add_script
	script s = [&]() -> void  {
		static int passages = 0;
		if(passages == 0) {
			// add_entity
			sc.add_entity(en);
			sc.add_entity(en2);

			// remove_entity
			sc.remove_entity(en);	// Entite presente
			sc.remove_entity(en2);	// Entite presente
			sc.add_entity(en2);		// On la rajoute apres
			sc.remove_entity(NULL);	// Entite nulle
			sc.remove_entity(nen);	// Entite non presente

			// entity_exists
			assert(sc.entity_exists(en) == true); // La suppression se fait a la fin de l'update
			assert(sc.entity_exists(en2) == true);
			++passages;
		} else {
			// entity_exists
			assert(sc.entity_exists(en) == false);
			assert(sc.entity_exists(en2) == false);
			// terminate
			sc.terminate();
		}
	};
	sc.add_script(s);

	sc.run();

	return 0;
}
