#include "attributes_container.h"

attributes_container::attributes_container(QWidget *parent) : QWidget(parent) {
    btn_new         = new QPushButton(tr("+"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    setup_layouts();
}

attributes_container::~attributes_container() {}

void attributes_container::setup_layouts() {
    lay_mainlayout->addWidget(btn_new);
    setLayout(lay_mainlayout);
    lay_mainlayout->setAlignment(Qt::AlignTop);
}

void attributes_container::add_attribute(attribute_widget *attr) {
    lay_mainlayout->addWidget(attr);
}
