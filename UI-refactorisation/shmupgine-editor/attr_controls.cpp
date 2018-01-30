#include "attr_controls.h"

attr_controls::attr_controls(entities_attributes_panel* container) : attribute(container) {
    /* * * * * * * * * * *
     * MEMORY ALLOCATION *
     * * * * * * * * * * */

    le_move_speed   = new QLineEdit("100", this);
    lbl_move_speed  = new QLabel(tr("Move speed"), this);
    lay_move_speed  = new QHBoxLayout(this);

    /* * * * * * * * * * * * * *
     * CONSTRAINTS AND MODELS  *
     * * * * * * * * * * * * * */

    le_move_speed->setValidator(new QDoubleValidator(0, 9999999, 2, this));
    gb_box->setTitle(tr("Controls"));

    /* * * * * * * *
     *   LAYOUTS   *
     * * * * * * * */

    lay_move_speed->addWidget(lbl_move_speed);
    lay_move_speed->addWidget(le_move_speed);
    lay_groupbox->addLayout(lay_move_speed);
}

attr_controls::~attr_controls() {

}

QString attr_controls::getCode() {

}
