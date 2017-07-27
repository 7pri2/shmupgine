#ifndef ENTITIES_CONTAINER_H
#define ENTITIES_CONTAINER_H

#include <QWidget>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>
#include "project_data.h"

class editor;

class entities_container : public QWidget {
    Q_OBJECT
public:
    friend class editor;

    explicit entities_container(QWidget *parent = 0);
    ~entities_container();

signals:

public slots:
    void update_current_index(QModelIndex index);
    void remove_entity();

private:
    QPushButton*    btn_new;
    QPushButton*    btn_delete;
    QListView*      lv_list;

    QVBoxLayout*    lay_mainlayout;
    QVBoxLayout*    lay_btn;

    void setup_layout();
};

#endif // ENTITIES_CONTAINER_H
