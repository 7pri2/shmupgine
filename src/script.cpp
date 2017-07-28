#include "script.h"

script::script() : attribute() {
	m_loop = []() -> void { return; };
}

script::script(entity* parent) : attribute(parent) {
	m_loop = []() -> void { return; };
}

script::~script() {

}

void script::run() {
#ifdef DEBUG
	std::cout << "\tscript... ";
#endif
	m_loop();
#ifdef DEBUG
	std::cout << debug::done;
#endif
}

void script::set_loop_function(std::function<void()> loop) {
	m_loop = loop;
}

script* script::make_copy(entity* newparent) {
	script* ptr = new script(*this);
	ptr->parent = newparent;
	return ptr;
}
