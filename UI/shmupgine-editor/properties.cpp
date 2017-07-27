#include "properties.h"

properties::properties() : attribute_widget() {
    lay_coord       = new QHBoxLayout(this);
    lbl_position    = new QLabel(tr("Position"), this);
    lbl_x           = new QLabel(tr("x"), this);
    lbl_y           = new QLabel(tr("y"), this);
    le_x            = new QLineEdit("0", this);
    le_y            = new QLineEdit("0", this);

    le_x->setValidator(new QIntValidator(-99999, 99999, this));
    le_y->setValidator(new QIntValidator(-99999, 99999, this));

    gb_box->setTitle(tr("Properties"));

    btn_delete->hide();
    cb_enabled->hide();

    lay_groupbox->addWidget(lbl_position);
    lay_coord->addWidget(lbl_x);
    lay_coord->addWidget(le_x);
    lay_coord->addWidget(lbl_y);
    lay_coord->addWidget(le_y);
    lay_groupbox->addLayout(lay_coord);

    connect(le_x, SIGNAL(textChanged(QString)), this, SLOT(update_scene()));
    connect(le_y, SIGNAL(textChanged(QString)), this, SLOT(update_scene()));
}

properties::~properties() {

}

QString properties::getCode() {
    QString code = QString("\tentity* ") + project_data::instance().get_entity_name(id_parent) + QString(" = new entity");
    if(le_x->text().toInt() != 0 || le_y->text().toInt() != 0)
        code += QString("(sf::Vector2f(") + le_x->text() + QString(", ") + le_y->text() + QString("))");
    code += QString(";\n");
    return code;
}

int properties::getPosX() {
    return le_x->text().toInt();
}

int properties::getPosY() {
    return le_y->text().toInt();
}

void properties::update_scene() {
    project_data::instance().update_entity_position(project_data::instance().current_entity_id, le_x->text().toInt(), le_y->text().toInt());
}
