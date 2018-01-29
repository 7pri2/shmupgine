#include "model_entity_block.h"
#include "entity_panel.h"
#include "attribute_panel.h"

model_entity_block::model_entity_block(QWidget *parent) : QWidget(parent) {
    entites     = new entity_panel(this);
    attributes  = new attribute_panel(this);
}

model_entity_block::~model_entity_block() {

}

entity_panel* model_entity_block::get_entity_panel() {
    return entites;
}

attribute_panel* model_entity_block::get_attribute_panel() {
    return attributes;
}
