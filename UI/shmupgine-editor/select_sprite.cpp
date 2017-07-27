#include "select_sprite.h"

select_sprite::select_sprite(QWidget *parent) : QWidget(parent) {
    lv_sprites      = new QListView(this);
    btn_select      = new QPushButton(tr("Select"), this);
    btn_cancel      = new QPushButton(tr("Cancel"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    lay_buttons     = new QHBoxLayout(this);

    btn_select->setEnabled(false);

    lay_buttons->addWidget(btn_select);
    lay_buttons->addWidget(btn_cancel);
    lay_mainlayout->addWidget(lv_sprites);
    lay_mainlayout->addLayout(lay_buttons);

    setLayout(lay_mainlayout);

    lv_sprites->setModel(project_data::instance().pictures_model);
    lv_sprites->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(btn_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(lv_sprites, SIGNAL(clicked(QModelIndex)), this, SLOT(sprite_selected()));
}

select_sprite::~select_sprite() {

}

void select_sprite::sprite_selected() {
    btn_select->setEnabled(true);
}

QString select_sprite::get_selected_sprite() {
    return lv_sprites->currentIndex().data().toString();
}

QPushButton* select_sprite::get_select_btn() {
    return btn_select;
}
