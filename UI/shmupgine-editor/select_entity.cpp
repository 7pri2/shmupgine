#include "select_entity.h"

select_entity::select_entity(QWidget *parent) : QWidget(parent) {
    lv_entities_view    = new QListView(this);
    btn_ok              = new QPushButton(tr("Select"), this);
    btn_cancel          = new QPushButton(tr("Cancel"), this);
    lay_mainlayout      = new QVBoxLayout(this);
    lay_btn             = new QHBoxLayout(this);

    btn_ok->setEnabled(false);

    setWindowTitle(tr("Select entity"));

    lay_btn->addWidget(btn_ok);
    lay_btn->addWidget(btn_cancel);
    lay_mainlayout->addWidget(lv_entities_view);
    lay_mainlayout->addLayout(lay_btn);

    lv_entities_view->setModel(project_data::instance().entities_model);
    lv_entities_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(btn_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(lv_entities_view, SIGNAL(clicked(QModelIndex)), this, SLOT(entity_selected()));
}

select_entity::~select_entity() {}

void select_entity::entity_selected() {
    btn_ok->setEnabled(true);
}

QString select_entity::get_selected_entity() {
    return lv_entities_view->currentIndex().data().toString();
}

QPushButton* select_entity::get_select_btn() {
    return btn_ok;
}
