#ifndef SELECT_SPRITE_H
#define SELECT_SPRITE_H

#include <QWidget>
#include <QListView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "project_data.h"

class select_sprite : public QWidget {
    Q_OBJECT
public:
    explicit select_sprite(QWidget *parent = 0);
    ~select_sprite();

    QString         get_selected_sprite();
    QPushButton*    get_select_btn();

signals:

public slots:
    void            sprite_selected();

private:
    QListView*      lv_sprites;
    QPushButton*    btn_select;
    QPushButton*    btn_cancel;
    QVBoxLayout*    lay_mainlayout;
    QHBoxLayout*    lay_buttons;
};

#endif // SELECT_SPRITE_H
