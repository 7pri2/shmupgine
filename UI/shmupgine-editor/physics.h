#ifndef PHYSICS_H
#define PHYSICS_H

#include <QLineEdit>
#include "attribute_widget.h"

class physics : public attribute_widget {
    Q_OBJECT
public:
    physics();
    ~physics();

    virtual QString getCode();

private:
    QLineEdit*  le_angle;
    QLineEdit*  le_velocity;

    QLabel*     lbl_angle;
    QLabel*     lbl_velocity;

	QHBoxLayout*	lay_angle;
	QHBoxLayout*	lay_velocity;
};

#endif // PHYSICS_H
