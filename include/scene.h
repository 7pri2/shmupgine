#ifndef __SCENE_H__
#define __SCENE_H__

#include <list>
#include <vector>
#include <map>
#include <functional>
#include "debug.h"
#include "bar.h"

class entity;
class destructor;

typedef std::list<entity*> 		group;
typedef std::function<void()>	script;

/* L'utilisation normale de la scene est la suivante:
 * 1/ Des entités sont créées et customisées à l'aide d'attributs
 * 2/ Elles sont ajoutées à la scène en question grâce à add_entity
 * 3/ La scène est lancée grâce à la méthode run()	*/

class scene {
	friend class destructor;
public:
	scene();
	~scene();

/* La fonction run permet de lancer la scene; c'est elle qui gère ensuite
 * toutes les entités et les évenements qui s'y déroulent. */
	void run();

/* Fonctions d'interactions avec le moteur */
	void 	add_entity(entity* en);
	void 	remove_entity(entity* en);
	bool	entity_exists(entity* en);

/* Fonction de manipulation des groupes d'entites */
	void	add_to_group(std::string groupname, entity* en);
	void	remove_from_group(std::string groupname, entity* en);
	bool	belongs_to_group(std::string groupname, entity* en);
	void	remove_from_all_groups(entity* en);
	/* Fonction pour connaitre si une entite du groupe entre en collision avec
	 * l'entite passee en parametre */
	bool	group_collides(std::string groupname, entity* en);

/* Fonctions de manipulation des scripts */
	void	add_script(std::function<void()> script);

/* Fonctions de manipulation des barres */
	void	add_bar(bar *b);

private:
/* update est la fonction qui permet de mettre à jour la scène, de gérer
 * différents attributs et entités, ainsi que les afficher, etc..[]		*/ 
	void 	update();

/* remove_entities parcoure la liste des entités placés sur la liste des 
 * entités à être supprimées et les supprime de cette liste, de la liste
 * des entités appartenant à la scène et libère leur mémoire */
	void 	remove_entities();

/* run_attributes parcoure la liste des entitées et parcoure et execute
 * les effets de leurs attributs qui sont activés */
	void 	run_attributes();

/* run_scripts parcoure la liste des scripts de la scene pour jouer leurs 
 * programmation */
	void	run_scripts();

/* Fonction de debug qui sert a afficher la liste des entites de chaque 
 * groupe */
	void	show_groups();

/* Fonction de dessin des barres de la scene */
	void	draw_bar(bar* b);
	void	draw_bars();

	std::map<std::string, group>	m_groups;
	std::list<entity*>				m_entities;
	std::vector<entity*>			m_to_be_removed;
	std::list<script>				m_scripts;
	std::list<bar*>					m_bars;
};

#endif
