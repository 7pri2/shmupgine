#ifndef ATTR_GRAPHIC_RENDERER_H
#define ATTR_GRAPHIC_RENDERER_H

#include <QPushButton>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsItem>
#include "windows_panels.h"
#include "attribute.h"

class attr_graphic_renderer : public attribute {
    Q_OBJECT
public:
    attr_graphic_renderer(entities_attributes_panel*);
    ~attr_graphic_renderer();

    virtual QString getCode();
    QPixmap get_picture();

private slots:
    void selectSprite();

private:
    QGraphicsView*  gv_view;
    QGraphicsScene* gs_scene;
    QLabel*         lbl_sprite;
    QLineEdit*      le_sprite;
    QPushButton*    btn_open_sprite;
    QHBoxLayout*    lay_sprite;
    QPixmap*        pm_picture;
};

#endif // ATTR_GRAPHIC_RENDERER_H
