#include "attribute_panel.h"

attribute_panel::attribute_panel(model_entity_block *parent) : QWidget(parent) {
    btn_new         = new QPushButton(tr("+"), this);
    lay_mainlayout  = new QVBoxLayout(this);

    m_choose_attribute  = new QMenu(this);
    a_physics           = new QAction(tr("&physics"), this);
    a_graphic_renderer  = new QAction(tr("&graphic renderer"), this);
    a_destructor        = new QAction(tr("&destructor"), this);
    a_controls          = new QAction(tr("&controls"), this);

    m_choose_attribute->addAction(a_physics);
    m_choose_attribute->addAction(a_graphic_renderer);
    m_choose_attribute->addAction(a_destructor);
    m_choose_attribute->addAction(a_controls);

    lay_mainlayout->addWidget(btn_new);
    lay_mainlayout->setAlignment(Qt::AlignTop);

    setLayout(lay_mainlayout);

    connect(btn_new, SIGNAL(clicked()), this, SLOT(showMenu()));
}

attribute_panel::~attribute_panel() {}

void attribute_panel::add_attribute(attribute *attr) {
    lay_mainlayout->addWidget(attr);
}

void attribute_panel::handle_Actions(QAction *a) {
    /*
    switch (a) {
    case a_physics:
        add_attribute(new attr_physics);
        break;
    case a_graphic_renderer:
        add_attribute(new attr_graphic_renderer);
        break;
    case a_destructor:
        add_attribute(new attr_destructor);
        break;
    case a_controls:
        add_attribute(new attr_controls);
        break;
    }*/
}

void attribute_panel::showMenu() {
    m_choose_attribute->show();
    //m_choose_attribute->set
}
