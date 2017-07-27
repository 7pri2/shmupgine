#ifdef DEBUG

#include <iostream>

/* Cet espace de nom est dédié à l'affichage de messages de debug; il met à 
 * disposition les modificateurs de couleur pour les messages propres au
 * debug	*/

namespace debug {
	extern std::string done;
	extern std::string title;
	extern std::string reset;
	extern std::string attr;
	extern std::string success;
	extern std::string error;
	extern std::string scene;

/* Fonctions affichant le texte msg avec le theme adequat */
	std::string	ptitle(std::string msg);
	std::string	pattr(std::string msg);
	std::string	psuccess(std::string msg);
	std::string	perror(std::string msg);
	std::string	pscene(std::string msg);
} /* namespace debug */

#endif
