#ifndef ATTR_PROPERTIES_H
#define ATTR_PROPERTIES_H

#include "attribute.h"
#include <QLineEdit>

class attr_properties : public attribute {
    Q_OBJECT
public:
    attr_properties(entities_attributes_panel* container);
    ~attr_properties();

    virtual QString getCode();
    int getPosX();
    int getPosY();

private:
    QLabel*         lbl_position;
    QLabel*         lbl_x;
    QLabel*         lbl_y;
    QLineEdit*      le_x;
    QLineEdit*      le_y;
    QHBoxLayout*    lay_coord;
};

#endif // ATTR_PROPERTIES_H
