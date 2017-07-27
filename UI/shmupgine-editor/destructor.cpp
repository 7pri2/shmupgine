#include "destructor.h"

destructor::destructor() : attribute_widget() {
    win_select_entity   = new select_entity();

    lv_entities         = new QListView(this);
    lv_groups           = new QListView(this);

    sm_entities         = new QStandardItemModel(this);
    sm_groups           = new QStandardItemModel(this);

    btn_add_entity      = new QPushButton(tr("Add"), this);
    btn_remove_entity   = new QPushButton(tr("Remove"), this);
    btn_add_group       = new QPushButton(tr("Add"), this);
    btn_remove_group    = new QPushButton(tr("Remove"), this);

    lay_entities_btn    = new QHBoxLayout(this);
    lay_groups_btn      = new QHBoxLayout(this);

    lbl_entities        = new QLabel(tr("Entities"), this);
    lbl_groups          = new QLabel(tr("Groups"), this);

    cb_out_of_bounds    = new QCheckBox(tr("Out of bounds"), this);

    lv_entities->setEditTriggers(QAbstractItemView::NoEditTriggers);
    lv_groups->setEditTriggers(QAbstractItemView::NoEditTriggers);

    lv_entities->setModel(sm_entities);
    lv_groups->setModel(sm_groups);

    gb_box->setTitle(tr("Destructor"));

    lay_entities_btn->addWidget(btn_add_entity);
    lay_entities_btn->addWidget(btn_remove_entity);

    lay_groups_btn->addWidget(btn_add_group);
    lay_groups_btn->addWidget(btn_remove_group);

    lay_groupbox->addWidget(lbl_entities);
    lay_groupbox->addWidget(lv_entities);
    lay_groupbox->addLayout(lay_entities_btn);
    lay_groupbox->addWidget(lbl_groups);
    lay_groupbox->addWidget(lv_groups);
    lay_groupbox->addLayout(lay_groups_btn);
    lay_groupbox->addWidget(cb_out_of_bounds);

    connect(btn_add_entity, SIGNAL(clicked()), this, SLOT(open_select_entity()));
    connect(win_select_entity->get_select_btn(), SIGNAL(clicked()), this, SLOT(selectEntity()));
    connect(btn_remove_entity, SIGNAL(clicked()), this, SLOT(removeEntity()));
}

destructor::~destructor() {
    delete win_select_entity;
}

QString destructor::getCode() {
    QString code = QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->allocateAttribute<destructor>();\n");
    if(cb_out_of_bounds->isChecked())
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<destructor>()->whenOutOfBounds = true;\n");
    for(int i = 0; i < sm_entities->rowCount(); ++i)
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<destructor>()->addCollision_entity(&") + sm_entities->index(i,0).data().toString() + QString(");\n");
    return code;
}

void destructor::open_select_entity() {
    win_select_entity->show();
}

void destructor::selectEntity() {
    win_select_entity->close();
    sm_entities->appendRow(new QStandardItem(win_select_entity->get_selected_entity()));
}

void destructor::removeEntity() {
    sm_entities->removeRow(lv_entities->currentIndex().row());
}
