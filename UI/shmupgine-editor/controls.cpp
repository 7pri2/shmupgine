#include "controls.h"

controls::controls() : attribute_widget() {
    le_move_speed   = new QLineEdit("100", this);
    lbl_move_speed  = new QLabel(tr("Move speed"), this);
    lay_move_speed  = new QHBoxLayout(this);

    le_move_speed->setValidator(new QDoubleValidator(0, 9999999, 2, this));
    gb_box->setTitle(tr("Controls"));

    lay_move_speed->addWidget(lbl_move_speed);
    lay_move_speed->addWidget(le_move_speed);
    lay_groupbox->addLayout(lay_move_speed);
}

controls::~controls() {

}

QString controls::getCode() {
    QString code = QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->allocateAttribute<controls>();\n");
    if(le_move_speed->text().toFloat() != 100)
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<controls>()->move_speed =") + le_move_speed->text() + QString(";\n");
    return code;
}
