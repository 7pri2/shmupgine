/**
 * \file	gmanager.h
 * \brief	Defines the class `gmanager' which manages all the graphical 
 * 			ressources for the project
 */

#ifndef __GMANAGER_H__
#define __GMANAGER_H__	

#include <SFML/Graphics.hpp>
#include <map>
#include "singleton.h"

/// Defines the default bullet size for the project
#define DEF_BULLET_SIZE	16

/// Defines the default bullet's sprite path
#define BULLETPATH    	"res/bullet.png"

class graphicrenderer;

/**
 * \class	gmanager
 * \brief	This class manages the graphical ressources for the project
 *
 * To add pictures to your project, set sprites through graphicrenderers, you 
 * must use the gmanager. It is a singleton, so you can't create an object of 
 * this type. To add a texture to the project, use `gmanager::new_texture(
 * "texture_name", "path_to_texture", width, height);', then you can use is 
 * later for example with the attribute graphicrenderer, you can use the method 
 * `set_texture("texture_name");'.
 */
class gmanager : public singleton<gmanager> {
	friend class singleton<gmanager>;
	friend class graphicrenderer;
public:
	/**
	 * \brief Adds a new texture to the project
	 * \param	name	Name of the new texture, which is used to refer to the 
	 * 					texture in the project
	 * \param	path	Path of the new texture on the filesystem
	 * \param	width	Width of the texture
	 * \param	height	Height of the texture
	 */
	void new_texture(std::string name, std::string path, int width, int height);

private:
	gmanager(const gmanager&) {};
	gmanager();
	~gmanager();

	/// Map of textures which allows access to textures through strings
	std::map<std::string, sf::Texture*>	m_textures;

	/// Default texture for bullets
	sf::Texture*						m_tex_bullet;
};

#endif
