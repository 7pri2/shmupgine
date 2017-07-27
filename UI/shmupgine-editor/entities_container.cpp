#include "entities_container.h"

entities_container::entities_container(QWidget *parent) : QWidget(parent) {
    btn_new     = new QPushButton(tr("New entity"), this);
    btn_delete  = new QPushButton(tr("Delete entity"), this);
    lv_list     = new QListView(this);

    lay_mainlayout  = new QVBoxLayout(this);
    lay_btn         = new QVBoxLayout(this);

    lv_list->setModel(project_data::instance().entities_model);

    setup_layout();
    connect(lv_list, SIGNAL(clicked(QModelIndex)), this, SLOT(update_current_index(QModelIndex)));
    connect(btn_delete, SIGNAL(clicked()), this, SLOT(remove_entity()));
}

entities_container::~entities_container() {}

void entities_container::setup_layout() {
    lay_mainlayout->addWidget(lv_list);
    lay_mainlayout->addLayout(lay_btn);
    lay_btn->addWidget(btn_new);
    lay_btn->addWidget(btn_delete);
    setLayout(lay_mainlayout);
}

void entities_container::update_current_index(QModelIndex index) {
    project_data::instance().current_entity_id = index.child(e_id, 0).data().toInt();
    project_data::instance().update_what_is_visible();
}

void entities_container::remove_entity() {
    project_data::instance().remove_entity(lv_list->currentIndex().row());
    update_current_index(lv_list->currentIndex());
    project_data::instance().update_what_is_visible();
}
