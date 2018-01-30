#include "entities_attributes_panel.h"

entities_attributes_panel::entities_attributes_panel(QWidget *parent) : QWidget(parent) {
    /* * * * * * * *
     * ALLOCATION  *
     * * * * * * * */

    // Entities
    entities_widget     = new QWidget(this);
    btn_new_entity      = new QPushButton(tr("New entity"), entities_widget);
    btn_delete_entity   = new QPushButton(tr("Delete entity"), entities_widget);

    lay_entities_layout = new QVBoxLayout(entities_widget);
    lay_btn             = new QVBoxLayout(entities_widget);

    lv_list             = new QListView(entities_widget);
    entities_model      = new QStandardItemModel(entities_widget);

    // Attributes
    attributes_widget   = new QWidget(this);
    btn_new_attribute   = new QPushButton(tr("+"), attributes_widget);
    lay_attr_layout     = new QVBoxLayout(attributes_widget);

    // Attr Menu
    m_choose_attribute  = new QMenu(attributes_widget);
    a_physics           = new QAction(tr("&physics"), attributes_widget);
    a_graphic_renderer  = new QAction(tr("&graphic renderer"), attributes_widget);
    a_destructor        = new QAction(tr("&destructor"), attributes_widget);
    a_controls          = new QAction(tr("&controls"), attributes_widget);

    // Main window
    lay_mainlayout      = new QHBoxLayout(this);
    s_splitter          = new QSplitter(this);

    /* * * * * * * * * * *
     *  MENU MANAGEMENT  *
     * * * * * * * * * * */

    m_choose_attribute->addAction(a_physics);
    m_choose_attribute->addAction(a_graphic_renderer);
    m_choose_attribute->addAction(a_destructor);
    m_choose_attribute->addAction(a_controls);

    entity_max_id = 0;
    lv_list->setModel(entities_model);

    /* * * * * * * *
     *   LAYOUTS   *
     * * * * * * * */

    // Entities
    lay_entities_layout->addWidget(lv_list);
    lay_entities_layout->addLayout(lay_btn);
    lay_btn->addWidget(btn_new_entity);
    lay_btn->addWidget(btn_delete_entity);

    // Attributes
    lay_attr_layout->addWidget(btn_new_attribute);
    lay_attr_layout->setAlignment(Qt::AlignTop);

    // Window
    s_splitter->addWidget(entities_widget);
    s_splitter->addWidget(attributes_widget);
    lay_mainlayout->addWidget(s_splitter);

    /* * * * * * * *
     * CONNECTIONS *
     * * * * * * * */

    connect(btn_new_attribute, SIGNAL(clicked()), this, SLOT(showMenu()));
    connect(lv_list, SIGNAL(clicked(QModelIndex)), this, SLOT(update_current_index(QModelIndex)));
    connect(btn_delete_entity, SIGNAL(clicked()), this, SLOT(remove_entity()));
    connect(btn_new_entity, SIGNAL(clicked()), this, SLOT(new_entity()));
    connect(m_choose_attribute, SIGNAL(triggered(QAction*)), this, SLOT(handle_Actions(QAction*)));
}

entities_attributes_panel::~entities_attributes_panel() {

}

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
    item->appendRow(new QStandardItem(QString::number(entity_max_id)));
    entities_model->appendRow(item);
    add_attribute(entity_max_id, new attr_properties(this));
}

void entities_attributes_panel::update_what_is_visible() {
    int id = current_entity.child(0,0).data().toInt();
    for(std::list<attribute*>::iterator it = attr_list.begin(); it != attr_list.end(); ++it) {
        (*it)->setVisible((*it)->getId_parent() == id);
    }
}

void entities_attributes_panel::add_attribute(attribute *attr) {
    attr->setId_parent(current_entity.child(0,0).data().toInt());
    attr->setParent(attributes_widget);
    lay_attr_layout->addWidget(attr);
    attr_list.push_back(attr);
    update_what_is_visible();
}

void entities_attributes_panel::add_attribute(int id, attribute *attr) {
    attr->setId_parent(id);
    attr->setParent(attributes_widget);
    lay_attr_layout->addWidget(attr);
    attr_list.push_back(attr);
    update_what_is_visible();
}

void entities_attributes_panel::handle_Actions(QAction *a) {
    if(a == a_destructor)
        add_attribute(new attr_destructor(this));
    else if(a == a_controls)
        add_attribute(new attr_controls(this));
    else if(a == a_graphic_renderer)
        add_attribute(new attr_graphic_renderer(this));
    else if(a == a_physics)
        add_attribute(new attr_physics(this));
}

void entities_attributes_panel::showMenu() {
    if(current_entity.child(0,0).data().toInt()) // id
        m_choose_attribute->popup(QCursor::pos());
}

void entities_attributes_panel::remove_attribute(attribute *attr) {
    attr_list.remove(attr);
}
