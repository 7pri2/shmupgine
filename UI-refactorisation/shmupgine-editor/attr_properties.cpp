#include "attr_properties.h"

attr_properties::attr_properties(entities_attributes_panel* container) : attribute(container) {
    lay_coord       = new QHBoxLayout(this);
    lbl_position    = new QLabel(tr("Position"), this);
    lbl_x           = new QLabel(tr("x"), this);
    lbl_y           = new QLabel(tr("y"), this);
    le_x            = new QLineEdit("0", this);
    le_y            = new QLineEdit("0", this);

    le_x->setValidator(new QIntValidator(-99999, 99999, this));
    le_y->setValidator(new QIntValidator(-99999, 99999, this));

    gb_box->setTitle(tr("Properties"));

    btn_delete->hide();
    cb_enabled->hide();

    lay_groupbox->addWidget(lbl_position);
    lay_coord->addWidget(lbl_x);
    lay_coord->addWidget(le_x);
    lay_coord->addWidget(lbl_y);
    lay_coord->addWidget(le_y);
    lay_groupbox->addLayout(lay_coord);

    connect(le_x, SIGNAL(textChanged(QString)), this, SLOT(update_scene()));
    connect(le_y, SIGNAL(textChanged(QString)), this, SLOT(update_scene()));
}

attr_properties::~attr_properties() {

}

QString attr_properties::getCode() {

}

int attr_properties::getPosX() {
    return le_x->text().toInt();
}

int attr_properties::getPosY() {
    return le_y->text().toInt();
}
