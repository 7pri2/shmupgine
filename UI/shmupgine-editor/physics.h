#ifndef PHYSICS_H
#define PHYSICS_H

#include <QDial>
#include <QSpinBox>
#include "attribute_widget.h"

class physics : public attribute_widget {
    Q_OBJECT
public:
    physics();
    ~physics();

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

#endif // PHYSICS_H
