#include "shmupgine.h"

int main(int argc, char* argv[]) {
    shmupgine::init();
    scene sc1;
    bullet entity1;
    bullet entity2;
    bullet entity3;
    bullet entity4;
    bullet entity5;
    bullet entity6;
	entity1.setPosition(20, 20);
	entity2.setPosition(300, 120);
	entity3.setPosition(400, 220);
	entity4.setPosition(540, 320);
	entity5.setPosition(430, 120);
	entity6.allocateAttribute<controls>();
	entity6.getAttribute<controls>()->move_speed = 250;
	entity6.setPosition(100, 100);
	entity1.allocateAttribute<destructor>();
	entity1.getAttribute<destructor>()->addCollision_entity(&entity6);
	entity2.allocateAttribute<destructor>();
	entity2.getAttribute<destructor>()->addCollision_entity(&entity6);
	entity3.allocateAttribute<destructor>();
	entity3.getAttribute<destructor>()->addCollision_entity(&entity6);
	entity4.allocateAttribute<destructor>();
	entity4.getAttribute<destructor>()->addCollision_entity(&entity6);
	entity5.allocateAttribute<destructor>();
	entity5.getAttribute<destructor>()->addCollision_entity(&entity6);
    sc1.add_entity(&entity1);
    sc1.add_entity(&entity2);
    sc1.add_entity(&entity3);
    sc1.add_entity(&entity4);
    sc1.add_entity(&entity5);
    sc1.add_entity(&entity6);
    sc1.run();
    shmupgine::close();
    return 0;
}
