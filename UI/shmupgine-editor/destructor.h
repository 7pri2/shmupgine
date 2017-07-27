#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include "attribute_widget.h"
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include "select_entity.h"

class destructor : public attribute_widget {
    Q_OBJECT
public:
    destructor();
    ~destructor();

    virtual QString getCode();

public slots:
    void open_select_entity();

private slots:
    void selectEntity();
    void removeEntity();

private:
    QListView*  lv_entities;
    QListView*  lv_groups;

    QStandardItemModel* sm_entities;
    QStandardItemModel* sm_groups;

    QPushButton*    btn_add_entity;
    QPushButton*    btn_remove_entity;
    QPushButton*    btn_add_group;
    QPushButton*    btn_remove_group;

    QHBoxLayout*    lay_entities_btn;
    QHBoxLayout*    lay_groups_btn;

    QLabel*         lbl_entities;
    QLabel*         lbl_groups;

    QCheckBox*      cb_out_of_bounds;
    select_entity*  win_select_entity;
};

#endif // DESTRUCTOR_H
