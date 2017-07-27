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
    QLineEdit*  le_x;
    QLineEdit*  le_y;
    QLineEdit*  le_velocity;

    QLabel*     lbl_force;
    QLabel*     lbl_velocity;
    QLabel*     lbl_x;
    QLabel*     lbl_y;

    QHBoxLayout*    lay_coord;
    QHBoxLayout*    lay_velocity;
};

#endif // PHYSICS_H
