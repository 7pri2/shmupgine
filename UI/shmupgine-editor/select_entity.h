#ifndef SELECT_ENTITY_H
#define SELECT_ENTITY_H

#include <QWidget>
#include <QListView>
#include <QPushButton>
#include <QHBoxLayout>
#include "project_data.h"
#include <QVBoxLayout>

class select_entity : public QWidget {
    Q_OBJECT
public:
    explicit select_entity(QWidget *parent = 0);
    ~select_entity();

    QString         get_selected_entity();
    QPushButton*    get_select_btn();

signals:

public slots:
    void            entity_selected();

private:
    QListView*      lv_entities_view;
    QPushButton*    btn_ok;
    QPushButton*    btn_cancel;
    QHBoxLayout*    lay_btn;
    QVBoxLayout*    lay_mainlayout;
};

#endif // SELECT_ENTITY_H
