#include "physics.h"

physics::physics() : attribute_widget() {
    le_x        = new QLineEdit("0", this);
    le_y        = new QLineEdit("0", this);
    le_velocity = new QLineEdit("0", this);

    lbl_force       = new QLabel(tr("Force"), this);
    lbl_velocity    = new QLabel(tr("Velocity"), this);
    lbl_x           = new QLabel(tr("x"), this);
    lbl_y           = new QLabel(tr("y"), this);

    lay_coord       = new QHBoxLayout(this);
    lay_velocity    = new QHBoxLayout(this);

    le_x->setValidator(new QDoubleValidator(-99999, 99999, 2, this));
    le_y->setValidator(new QDoubleValidator(-99999, 99999, 2, this));
    le_velocity->setValidator(new QDoubleValidator(-99999, 99999, 2, this));

    gb_box->setTitle(tr("Physics"));
    lay_coord->addWidget(lbl_x);
    lay_coord->addWidget(le_x);
    lay_coord->addWidget(lbl_y);
    lay_coord->addWidget(le_y);
    lay_velocity->addWidget(lbl_velocity);
    lay_velocity->addWidget(le_velocity);
    lay_groupbox->addWidget(lbl_force);
    lay_groupbox->addLayout(lay_coord);
    lay_groupbox->addLayout(lay_velocity);
}

physics::~physics() {}

QString physics::getCode() {
    QString code = QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->allocateAttribute<physics>();\n");
    if(le_x->text().toInt() != 0 || le_y->text().toInt() != 0)
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<physics>()->setForce(sf::Vector2f(") + le_x->text() + QString(", ") + le_y->text() + QString("));\n");
    if(le_velocity->text().toInt() != 0)
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<physics>()->setVelocity(") + le_velocity->text() + QString(");\n");
    return code;
}
