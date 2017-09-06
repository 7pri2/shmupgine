#include "physics.h"

physics::physics() : attribute_widget() {
	/* Allocation des QLineEdit */
    le_angle    = new QLineEdit("0", this);
    le_velocity = new QLineEdit("0", this);

	/* Allocation des QLabel */
    lbl_angle       = new QLabel(tr("Angle"), this);
    lbl_velocity    = new QLabel(tr("Velocity"), this);

	/* Allocation des layouts */
	lay_angle 		= new QHBoxLayout(this);
	lay_velocity 	= new QHBoxLayout(this);

	/* Application des validateurs */
    le_angle->setValidator(new QIntValidator(0, 359, this));
    le_velocity->setValidator(new QDoubleValidator(-99999, 99999, 2, this));

	/* Mise en place du layout d'angle */
	lay_angle->addWidget(lbl_angle);
	lay_angle->addWidget(le_angle);

	/* Mise en place du layout de velocite */
	lay_velocity->addWidget(lbl_velocity);
	lay_velocity->addWidget(le_velocity);

    gb_box->setTitle(tr("Physics"));

	/* Mise en palce de tous les layouts */
    lay_groupbox->addLayout(lay_angle);
    lay_groupbox->addLayout(lay_velocity);
}

physics::~physics() {}

QString physics::getCode() {
    QString code = QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->allocate_attribute<physics>();\n");
    if(le_angle->text().toInt() != 0)
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->get_attribute<physics>()->set_angle(") + le_angle->text() + QString(");\n");
    if(le_velocity->text().toInt() != 0)
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->get_attribute<physics>()->setVelocity(") + le_velocity->text() + QString(");\n");
    return code;
}
