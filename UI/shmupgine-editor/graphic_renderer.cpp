#include "graphic_renderer.h"

graphic_renderer::graphic_renderer() : attribute_widget() {
    win_select  = new select_sprite();

    pm_picture      = new QPixmap;
    gb_box->setTitle(tr("Graphic renderer"));
    lbl_sprite      = new QLabel(tr("Sprite"), this);
    le_sprite       = new QLineEdit(this);
    lay_sprite      = new QHBoxLayout(this);
    btn_open_sprite = new QPushButton("...", this);
    gs_scene        = new QGraphicsScene(this);
    gv_view         = new QGraphicsView(gs_scene, this);

    btn_open_sprite->setMaximumWidth(BTN_WIDTH);

    lay_groupbox->addWidget(lbl_sprite);
    lay_groupbox->addWidget(gv_view);
    lay_sprite->addWidget(le_sprite);
    lay_sprite->addWidget(btn_open_sprite);
    lay_groupbox->addLayout(lay_sprite);

    le_sprite->setReadOnly(true);

    connect(btn_open_sprite, SIGNAL(clicked()), this, SLOT(open_select_Sprite()));
    connect(win_select->get_select_btn(), SIGNAL(clicked()), this, SLOT(selectSprite()));
}

graphic_renderer::~graphic_renderer() {
    delete pm_picture;
}

void graphic_renderer::open_select_Sprite() {
    win_select->show();
}

void graphic_renderer::selectSprite() {
    win_select->close();
    le_sprite->setText(win_select->get_selected_sprite());
    pm_picture->load(project_data::instance().get_picture_path(le_sprite->text()));
    gs_scene->clear();
    gs_scene->setSceneRect(0, 0, pm_picture->width(), pm_picture->height());
    gs_scene->addItem(new QGraphicsPixmapItem(*pm_picture));
    project_data::instance().update_entity_pixmap(project_data::instance().current_entity_id, pm_picture);
}

QString graphic_renderer::getCode() {
    QString code;
    code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->allocateAttribute<graphicrenderer>();\n");
    if(!le_sprite->text().isEmpty())
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<graphicrenderer>()->sprite.setTexture(*gmanager::textures[\"") + le_sprite->text() + QString("\"]);\n");
    return code;
}

QPixmap graphic_renderer::get_picture() {
    return *pm_picture;
}
