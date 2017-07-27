#include "graphics_manager.h"
#include <iostream>

graphics_manager::graphics_manager(QWidget *parent) : QWidget(parent) {
    lv_pictures_view    = new QListView(this);

    gs_scene    = new QGraphicsScene(this);
    gv_view     = new QGraphicsView(gs_scene, this);

    lbl_name    = new QLabel(tr("Name"), this);
    lbl_path    = new QLabel(tr("Path"), this);
    lbl_width   = new QLabel(tr("Width"), this);
    lbl_height  = new QLabel(tr("Height"), this);

    le_name     = new QLineEdit(this);
    le_path     = new QLineEdit(this);
    le_width    = new QLineEdit(this);
    le_height   = new QLineEdit(this);

    lay_mainlayout      = new QHBoxLayout(this);
    lay_details         = new QVBoxLayout(this);
    lay_pictures_list   = new QVBoxLayout(this);
    lay_buttons         = new QHBoxLayout(this);
    lay_width           = new QHBoxLayout(this);
    lay_height          = new QHBoxLayout(this);
    lay_path            = new QHBoxLayout(this);
    lay_name            = new QHBoxLayout(this);

    btn_open    = new QPushButton(tr("Open"), this);
    btn_remove  = new QPushButton(tr("Remove"), this);

    lv_pictures_view->setModel(project_data::instance().pictures_model);

    setup_layouts();
    apply_constraints();
    dis_or_enable_details();

    connect(btn_open, SIGNAL(clicked()), this, SLOT(add_picture()));
    connect(lv_pictures_view, SIGNAL(clicked(QModelIndex)), this, SLOT(fill_infos(QModelIndex)));
    connect(lv_pictures_view, SIGNAL(clicked(QModelIndex)), this, SLOT(dis_or_enable_details()));
    connect(project_data::instance().pictures_model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(update_infos(QStandardItem*)));
    connect(le_name, SIGNAL(textEdited(QString)), this, SLOT(update_model()));
    connect(le_path, SIGNAL(textEdited(QString)), this, SLOT(update_model()));
    connect(le_width, SIGNAL(textEdited(QString)), this, SLOT(update_model()));
    connect(le_height, SIGNAL(textEdited(QString)), this, SLOT(update_model()));
    connect(btn_remove, SIGNAL(clicked()), this, SLOT(delete_picture()));
}

graphics_manager::~graphics_manager() {}

void graphics_manager::apply_constraints() {
    le_width->setValidator(new QIntValidator(0, MAX_INT, this));
    le_height->setValidator(new QIntValidator(0, MAX_INT, this));
}

void graphics_manager::setup_layouts() {
    lay_name->addWidget(lbl_name);
    lay_name->addWidget(le_name);
    lay_path->addWidget(lbl_path);
    lay_path->addWidget(le_path);
    lay_width->addWidget(lbl_width);
    lay_width->addWidget(le_width);
    lay_height->addWidget(lbl_height);
    lay_height->addWidget(le_height);
    lay_details->addWidget(gv_view);
    lay_details->addLayout(lay_name);
    lay_details->addLayout(lay_path);
    lay_details->addLayout(lay_width);
    lay_details->addLayout(lay_height);
    lay_pictures_list->addWidget(lv_pictures_view);
    lay_buttons->addWidget(btn_open);
    lay_buttons->addWidget(btn_remove);
    lay_pictures_list->addLayout(lay_buttons);
    lay_mainlayout->addLayout(lay_pictures_list);
    lay_mainlayout->addLayout(lay_details);
}

void graphics_manager::add_picture() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open picture"), "", tr("Pictures (*.png *.jpg)"));
    if(!filename.isEmpty())
        project_data::instance().append_picture(filename);
}

void graphics_manager::fill_infos(QModelIndex index) {
    project_data::instance().current_picture_id = index.child(i_id, 0).data().toInt();
    std::cout << project_data::instance().get_pictures_name().toStdString();
    QPixmap file = QPixmap(project_data::instance().get_pictures_path());
    gs_scene->clear();
    gs_scene->setSceneRect(0, 0, project_data::instance().get_pictures_width().toInt(), project_data::instance().get_pictures_height().toInt());
    gs_scene->addItem(new QGraphicsPixmapItem(file));
    le_name->setText(project_data::instance().get_pictures_name());
    le_path->setText(project_data::instance().get_pictures_path());
    le_height->setText(project_data::instance().get_pictures_height());
    le_width->setText(project_data::instance().get_pictures_width());
}

void graphics_manager::update_infos(QStandardItem *item) {
    if(item->index().child(i_id,0).data().toInt() == project_data::instance().current_picture_id)
        le_name->setText(item->index().data().toString());
}

void graphics_manager::update_model() {
    project_data::instance().set_pictures_name(le_name->text());
    project_data::instance().set_pictures_path(le_path->text());
    project_data::instance().set_pictures_width(le_width->text());
    project_data::instance().set_pictures_height(le_height->text());
}

void graphics_manager::delete_picture() {
    int id = project_data::instance().current_picture_id;
    if(id != 0)
        project_data::instance().remove_picture(id);
    fill_infos(lv_pictures_view->currentIndex());
    dis_or_enable_details();
}

void graphics_manager::dis_or_enable_details() {
    bool id_state = project_data::instance().current_picture_id != 0;
    gv_view->setEnabled(id_state);
    lbl_height->setEnabled(id_state);
    lbl_name->setEnabled(id_state);
    lbl_path->setEnabled(id_state);
    lbl_width->setEnabled(id_state);
    le_height->setEnabled(id_state);
    le_name->setEnabled(id_state);
    le_path->setEnabled(id_state);
    le_width->setEnabled(id_state);
}
