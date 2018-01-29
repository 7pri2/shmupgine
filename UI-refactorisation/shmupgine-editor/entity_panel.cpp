#include "entity_panel.h"

entity_panel::entity_panel(model_entity_block *parent) : QWidget(parent) {
    btn_new     = new QPushButton(tr("New entity"), this);
    btn_delete  = new QPushButton(tr("Delete entity"), this);

    lay_mainlayout  = new QVBoxLayout(this);
    lay_btn         = new QVBoxLayout(this);

    lv_list         = new QListView(this);
    entities_model  = new QStandardItemModel(this);

    entity_max_id = 0;
    lv_list->setModel(entities_model);

    setup_layout();
    connect(lv_list, SIGNAL(clicked(QModelIndex)), this, SLOT(update_current_index(QModelIndex)));
    connect(btn_delete, SIGNAL(clicked()), this, SLOT(remove_entity()));
    connect(btn_new, SIGNAL(clicked()), this, SLOT(new_entity()));
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
    entities_model->removeRow(lv_list->currentIndex().row());
    update_current_index(lv_list->currentIndex());
    update_what_is_visible();
}

void entity_panel::new_entity() {
    entity_max_id += 1;
    QStandardItem* item = new QStandardItem(QString(QObject::tr("entity"))+QString::number(entity_max_id));
    entities_model->appendRow(item);
    //item->appendRow(new QStandardItem(QString::number(entity_max_id)));
    //create_attribute(id, new properties());
}

void entity_panel::update_what_is_visible() {/*
    int id = current_entity.row();
    for(std::list<attribute_widget*>::iterator it = attr_list->begin(); it!= attr_list->end(); ++it) {
        (*it)->setVisible((*it)->getId_parent() == id);
    }*/
}
