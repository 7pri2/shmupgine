#ifndef ENTITY_PANEL_H
#define ENTITY_PANEL_H

#include <QWidget>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include "model_entity_block.h"
#include "project_data.h"

class editor;

class entity_panel : public QWidget {
    Q_OBJECT
public:
    friend class editor;

    explicit entity_panel(model_entity_block *parent = 0);
    ~entity_panel();

signals:

public slots:
    void update_current_index(QModelIndex index);
    void remove_entity();
    void new_entity();

private slots:
    void update_what_is_visible();

private:
    QPushButton*    btn_new;
    QPushButton*    btn_delete;

    QVBoxLayout*    lay_mainlayout;
    QVBoxLayout*    lay_btn;

    QListView*          lv_list;
    QStandardItemModel* entities_model;
    QModelIndex         current_entity;

    int entity_max_id;

    void setup_layout();
};


#endif // ENTITY_PANEL_H
