#include "attribute.h"
#include "entity.h"

attribute::attribute() {
	enabled = true;
}

attribute::attribute(entity* parent) : attribute() {
	this->parent = parent;
}

void attribute::run() {
}
