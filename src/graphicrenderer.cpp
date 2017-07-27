#include "graphicrenderer.h"

graphicrenderer::graphicrenderer(entity* parent) : attribute(parent) {
	sprite.setPosition(parent->getPosition());
}

graphicrenderer::~graphicrenderer() {

}

void graphicrenderer::run() {
#ifdef DEBUG
	std::cout << "\tgraphicrenderer... ";
#endif
	shmupgine::window.draw(sprite);
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

graphicrenderer* graphicrenderer::make_copy(entity* newparent) {
	graphicrenderer* ptr = new graphicrenderer(*this);
	ptr->parent = newparent;
	return ptr;
}
