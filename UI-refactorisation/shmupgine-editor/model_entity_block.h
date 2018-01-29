#ifndef MODEL_ENTITY_BLOCK_H
#define MODEL_ENTITY_BLOCK_H

#include <QWidget>

class attribute_panel;
class entity_panel;

class model_entity_block : public QWidget {
public:
    model_entity_block(QWidget *parent = 0);
    ~model_entity_block();

    entity_panel*       get_entity_panel();
    attribute_panel*    get_attribute_panel();

private:
    entity_panel*       entites;
    attribute_panel*    attributes;
};

#endif // MODEL_ENTITY_BLOCK_H
