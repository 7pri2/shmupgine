#ifndef ATTR_PHYSICS_H
#define ATTR_PHYSICS_H

#include <QDial>
#include <QSpinBox>
#include "attribute.h"

class attr_physics : public attribute {
    Q_OBJECT
public:
    attr_physics(entities_attributes_panel*);
    ~attr_physics();

    virtual QString getCode();

private:
    QDial*      dial_angle;
    QSpinBox*   sb_angle;
    QSpinBox*   sb_velocity;

    QLabel*     lbl_angle;
    QLabel*     lbl_velocity;

    QHBoxLayout*	lay_angle;
    QVBoxLayout*    lay_sb_angle;
    QHBoxLayout*	lay_velocity;
};

#endif // ATTR_PHYSICS_H
