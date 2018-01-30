#ifndef ENTITIES_ATTRIBUTES_PANEL_H
#define ENTITIES_ATTRIBUTES_PANEL_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <list>

#include "attributes.h"

class entities_attributes_panel : public QWidget {
    Q_OBJECT
public:
    entities_attributes_panel(QWidget* parent = 0);
    ~entities_attributes_panel();

signals:

public slots:
    // ATTRIBUTES
    void showMenu();
    void handle_Actions(QAction*);
    void remove_attribute(attribute* attr);

    // ENTITIES
    void update_current_index(QModelIndex index);
    void remove_entity();
    void new_entity();

private slots:
    void update_what_is_visible();

private:
    // ENTITIES
    QWidget*        entities_widget;
    QPushButton*    btn_new_entity;
    QPushButton*    btn_delete_entity;

    QVBoxLayout*    lay_entities_layout;
    QVBoxLayout*    lay_btn;

    QListView*          lv_list;
    QStandardItemModel* entities_model;
    QModelIndex         current_entity;

    int entity_max_id;

    // ATTRIBUTES
    void add_attribute(attribute* attr);
    void add_attribute(int id, attribute* attr); // pour new_entity()

    QWidget*        attributes_widget;

    QPushButton*    btn_new_attribute;
    QVBoxLayout*    lay_attr_layout;

    // Menu
    QMenu*      m_choose_attribute;
    QAction*    a_physics;
    QAction*    a_graphic_renderer;
    QAction*    a_destructor;
    QAction*    a_controls;

    std::list<attribute*>   attr_list;

    // MAINWIDGET
    QSplitter*      s_splitter;
    QHBoxLayout*    lay_mainlayout;
};

#endif // ENTITIES_ATTRIBUTES_PANEL_H
