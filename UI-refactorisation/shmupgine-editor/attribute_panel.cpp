#include "attribute_panel.h"

attribute_panel::attribute_panel(model_entity_block *parent) : QWidget(parent) {
    btn_new         = new QPushButton(tr("+"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    setup_layouts();
}

attribute_panel::~attribute_panel() {}

void attribute_panel::setup_layouts() {
    lay_mainlayout->addWidget(btn_new);
    setLayout(lay_mainlayout);
    lay_mainlayout->setAlignment(Qt::AlignTop);
}

void attribute_panel::add_attribute(attribute_widget *attr) {
    lay_mainlayout->addWidget(attr);
}
