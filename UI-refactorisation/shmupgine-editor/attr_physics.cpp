#include "attr_physics.h"

attr_physics::attr_physics(entities_attributes_panel* container) : attribute(container) {
    /* Allocation des QSpinBox */
    dial_angle  = new QDial(this);
    sb_velocity = new QSpinBox(this);
    sb_angle    = new QSpinBox(this);

    /* Allocation des QLabel */
    lbl_angle       = new QLabel(tr("Angle"), this);
    lbl_velocity    = new QLabel(tr("Velocity"), this);

    /* Allocation des layouts */
    lay_angle 		= new QHBoxLayout(this);
    lay_velocity 	= new QHBoxLayout(this);
    lay_sb_angle    = new QVBoxLayout(this);

    /* Application des validateurs */
    /*s_angle->setValidator(new QIntValidator(0, 359, this));
    sb_velocity->setValidator(new QDoubleValidator(-99999, 99999, 2, this));*/
    sb_angle->setRange(0,359);
    dial_angle->setRange(0, 359);

    /* Mise en place du layout d'angle */
    lay_sb_angle->addWidget(dial_angle);
    lay_sb_angle->addWidget(sb_angle);
    lay_angle->addWidget(lbl_angle);
    lay_angle->addLayout(lay_sb_angle);

    /* Mise en place du layout de velocite */
    lay_velocity->addWidget(lbl_velocity);
    lay_velocity->addWidget(sb_velocity);

    gb_box->setTitle(tr("Physics"));

    /* Mise en palce de tous les layouts */
    lay_groupbox->addLayout(lay_angle);
    lay_groupbox->addLayout(lay_velocity);

    /* Signaux et slots */
    connect(dial_angle, SIGNAL(valueChanged(int)), sb_angle, SLOT(setValue(int)));
    connect(sb_angle, SIGNAL(valueChanged(int)), dial_angle, SLOT(setValue(int)));
}

attr_physics::~attr_physics() {}

QString attr_physics::getCode() {
}
