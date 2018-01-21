#include "entity_panel.h"

entity_panel::entity_panel(QWidget *parent) : QWidget(parent) {
    btn_new     = new QPushButton(tr("New entity"), this);
    btn_delete  = new QPushButton(tr("Delete entity"), this);
    lv_list     = new QListView(this);

    lay_mainlayout  = new QVBoxLayout(this);
    lay_btn         = new QVBoxLayout(this);

    lv_list->setModel(entities_model);

    setup_layout();
    connect(lv_list, SIGNAL(clicked(QModelIndex)), this, SLOT(update_current_index(QModelIndex)));
    connect(btn_delete, SIGNAL(clicked()), this, SLOT(remove_entity()));
}

entity_panel::~entity_panel() {}

void entity_panel::setup_layout() {
    lay_mainlayout->addWidget(lv_list);
    lay_mainlayout->addLayout(lay_btn);
    lay_btn->addWidget(btn_new);
    lay_btn->addWidget(btn_delete);
    setLayout(lay_mainlayout);
}

void entity_panel::update_current_index(QModelIndex index) {
    current_entity = index;
    update_what_is_visible();
}

void entity_panel::remove_entity() {
    //project_data::instance().remove_entity(lv_list->currentIndex().row());
    //update_current_index(lv_list->currentIndex());
    //project_data::instance().update_what_is_visible();
}

void entity_panel::update_what_is_visible() {/*
    int id = current_entity.row();
    for(std::list<attribute_widget*>::iterator it = attr_list->begin(); it!= attr_list->end(); ++it) {
        (*it)->setVisible((*it)->getId_parent() == id);
    }*/
}
