#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "attribute_widget.h"
#include <QLineEdit>

class properties : public attribute_widget {
    Q_OBJECT
public:
    properties();
    ~properties();

    virtual QString getCode();
    int getPosX();
    int getPosY();

public slots:
    void update_scene();

private:
    QLabel*         lbl_position;
    QLabel*         lbl_x;
    QLabel*         lbl_y;
    QLineEdit*      le_x;
    QLineEdit*      le_y;
    QHBoxLayout*    lay_coord;
};

#endif // PROPERTIES_H
