#include "systems.h"

int 				shmupgine::w_width;
int 				shmupgine::w_height;
std::string 		shmupgine::w_title;
sf::Clock			shmupgine::clock;
sf::RenderWindow	shmupgine::window;

void shmupgine::init() {
	shmupgine::w_width = 480;
	shmupgine::w_height = 980;
	shmupgine::w_title = "Shmupgine demo";
	shmupgine::window.create(sf::VideoMode(shmupgine::w_width, shmupgine::w_height), shmupgine::w_title);
	shmupgine::window.setVerticalSyncEnabled(true);
}
