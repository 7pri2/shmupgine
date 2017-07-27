#ifndef GRAPHIC_RENDERER_H
#define GRAPHIC_RENDERER_H

#include "attribute_widget.h"
#include <QPushButton>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include "project_data.h"
#include <QGraphicsItem>
#include "select_sprite.h"

class graphic_renderer : public attribute_widget {
    Q_OBJECT
public:
    graphic_renderer();
    ~graphic_renderer();

    virtual QString getCode();
    QPixmap get_picture();

public slots:
    void open_select_Sprite();

private slots:
    void selectSprite();

private:
    select_sprite*  win_select;

    QGraphicsView*  gv_view;
    QGraphicsScene* gs_scene;
    QLabel*         lbl_sprite;
    QLineEdit*      le_sprite;
    QPushButton*    btn_open_sprite;
    QHBoxLayout*    lay_sprite;
    QPixmap*        pm_picture;
};

#endif // GRAPHIC_RENDERER_H
