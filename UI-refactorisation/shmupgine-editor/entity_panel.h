#ifndef ENTITY_PANEL_H
#define ENTITY_PANEL_H

#include <QWidget>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include "project_data.h"

class editor;

class entity_panel : public QWidget {
    Q_OBJECT
public:
    friend class editor;

    explicit entity_panel(QWidget *parent = 0);
    ~entity_panel();

signals:

public slots:
    void update_current_index(QModelIndex index);
    void remove_entity();

private slots:
    void update_what_is_visible();

private:
    QPushButton*    btn_new;
    QPushButton*    btn_delete;
    QListView*      lv_list;

    QVBoxLayout*    lay_mainlayout;
    QVBoxLayout*    lay_btn;

    QPushButton*    btn_new_attr;

    QStandardItemModel* entities_model;
    QModelIndex         current_entity;

    void setup_layout();
};


#endif // ENTITY_PANEL_H
