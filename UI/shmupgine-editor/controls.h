#ifndef CONTROLS_H
#define CONTROLS_H

#include "attribute_widget.h"
#include <QDoubleValidator>
#include <QLineEdit>

class controls : public attribute_widget {
public:
    controls();
    ~controls();

    virtual QString getCode();

private:
    QLabel*         lbl_move_speed;
    QLineEdit*      le_move_speed;
    QHBoxLayout*    lay_move_speed;
};

#endif // CONTROLS_H
