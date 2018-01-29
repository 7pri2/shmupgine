#include "entities_attributes_panel.h"

entities_attributes_panel::entities_attributes_panel(QWidget *parent) : QWidget(parent) {
    entities_widget     = new QWidget(this);
    btn_new_entity      = new QPushButton(tr("New entity"), entities_widget);
    btn_delete_entity   = new QPushButton(tr("Delete entity"), entities_widget);

    attributes_widget   = new QWidget(this);
    btn_new_attribute   = new QPushButton(tr("+"), attributes_widget);
    lay_attr_layout     = new QVBoxLayout(attributes_widget);

    m_choose_attribute  = new QMenu(attributes_widget);
    a_physics           = new QAction(tr("&physics"), attributes_widget);
    a_graphic_renderer  = new QAction(tr("&graphic renderer"), attributes_widget);
    a_destructor        = new QAction(tr("&destructor"), attributes_widget);
    a_controls          = new QAction(tr("&controls"), attributes_widget);

    lay_entities_layout = new QVBoxLayout(entities_widget);
    lay_btn             = new QVBoxLayout(entities_widget);

    lv_list         = new QListView(entities_widget);
    entities_model  = new QStandardItemModel(entities_widget);

    lay_mainlayout  = new QHBoxLayout(this);
    s_splitter      = new QSplitter(this);

    // ATTR_MENU
    m_choose_attribute->addAction(a_physics);
    m_choose_attribute->addAction(a_graphic_renderer);
    m_choose_attribute->addAction(a_destructor);
    m_choose_attribute->addAction(a_controls);

    entity_max_id = 0;
    lv_list->setModel(entities_model);

    lay_entities_layout->addWidget(lv_list);
    lay_entities_layout->addLayout(lay_btn);
    lay_btn->addWidget(btn_new_entity);
    lay_btn->addWidget(btn_delete_entity);

    lay_attr_layout->addWidget(btn_new_attribute);
    lay_attr_layout->setAlignment(Qt::AlignTop);

    s_splitter->addWidget(entities_widget);
    s_splitter->addWidget(attributes_widget);
    lay_mainlayout->addWidget(s_splitter);

    connect(btn_new_attribute, SIGNAL(clicked()), this, SLOT(showMenu()));
    connect(lv_list, SIGNAL(clicked(QModelIndex)), this, SLOT(update_current_index(QModelIndex)));
    connect(btn_delete_entity, SIGNAL(clicked()), this, SLOT(remove_entity()));
    connect(btn_new_entity, SIGNAL(clicked()), this, SLOT(new_entity()));
}

entities_attributes_panel::~entities_attributes_panel() {}

void entities_attributes_panel::update_current_index(QModelIndex index) {
    current_entity = index;
    update_what_is_visible();
}

void entities_attributes_panel::remove_entity() {
    entities_model->removeRow(lv_list->currentIndex().row());
    update_current_index(lv_list->currentIndex());
    update_what_is_visible();
}

void entities_attributes_panel::new_entity() {
    entity_max_id += 1;
    QStandardItem* item = new QStandardItem(QString(QObject::tr("entity"))+QString::number(entity_max_id));
    entities_model->appendRow(item);
    //item->appendRow(new QStandardItem(QString::number(entity_max_id)));
    //create_attribute(id, new properties());
}

void entities_attributes_panel::update_what_is_visible() {/*
    int id = current_entity.row();
    for(std::list<attribute_widget*>::iterator it = attr_list->begin(); it!= attr_list->end(); ++it) {
        (*it)->setVisible((*it)->getId_parent() == id);
    }*/
}

void entities_attributes_panel::add_attribute(attribute *attr) {
    lay_attr_layout->addWidget(attr);
}

void entities_attributes_panel::handle_Actions(QAction *a) {
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

void entities_attributes_panel::showMenu() {
    m_choose_attribute->popup(QCursor::pos());
}
