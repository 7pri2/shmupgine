#include "attr_graphic_renderer.h"


attr_graphic_renderer::attr_graphic_renderer(entities_attributes_panel* container) : attribute(container) {
    /* * * * * * * * * * *
     * MEMORY ALLOCATION *
     * * * * * * * * * * */

    pm_picture      = new QPixmap;
    lbl_sprite      = new QLabel(tr("Sprite"), this);
    le_sprite       = new QLineEdit(this);
    lay_sprite      = new QHBoxLayout(this);
    btn_open_sprite = new QPushButton("...", this);
    gs_scene        = new QGraphicsScene(this);
    gv_view         = new QGraphicsView(gs_scene, this);

    /* * * * * * * * * * *
     * WINDOW MANAGEMENT *
     * * * * * * * * * * */

    gb_box->setTitle(tr("Graphic renderer"));

    btn_open_sprite->setMaximumWidth(BTN_WIDTH);

    lay_groupbox->addWidget(lbl_sprite);
    lay_groupbox->addWidget(gv_view);
    lay_sprite->addWidget(le_sprite);
    lay_sprite->addWidget(btn_open_sprite);
    lay_groupbox->addLayout(lay_sprite);

    /* * * * * * * * * * * * * *
     * CONSTRAINTS AND MODELS  *
     * * * * * * * * * * * * * */

    le_sprite->setReadOnly(true);

    /* * * * * * * *
     * CONNECTIONS *
     * * * * * * * */

    connect(btn_open_sprite, SIGNAL(clicked(bool)), this, SLOT(selectSprite()));
}

attr_graphic_renderer::~attr_graphic_renderer() {
    delete pm_picture;
}

void attr_graphic_renderer::selectSprite() {
    QString sprite = w_graphics_manager::Instance()->select_picture();
    le_sprite->setText(sprite);/*
    pm_picture->load(project_data::instance().get_picture_path(le_sprite->text()));
    gs_scene->clear();
    gs_scene->setSceneRect(0, 0, pm_picture->width(), pm_picture->height());
    gs_scene->addItem(new QGraphicsPixmapItem(*pm_picture));
    project_data::instance().update_entity_pixmap(project_data::instance().current_entity_id, pm_picture);*/
}

QString attr_graphic_renderer::getCode() {

}

QPixmap attr_graphic_renderer::get_picture() {
    return *pm_picture;
}
