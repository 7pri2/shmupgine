#include "attribute_widget.h"

attribute_widget::attribute_widget() : QWidget() {
    cb_enabled      = new QCheckBox(tr("Enabled"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    lay_groupbox    = new QVBoxLayout(this);
    gb_box          = new QGroupBox(this);
    btn_delete      = new QPushButton(QString::fromUtf8(CROSS_2), this);
    id_parent       = -1;

    btn_delete->setStyleSheet("border: none;");
    btn_delete->setMaximumSize(20, 20);

    cb_enabled->setChecked(true);
    lay_groupbox->addWidget(cb_enabled);
    gb_box->setLayout(lay_groupbox);
    lay_mainlayout->addWidget(gb_box);
    setLayout(lay_mainlayout);

    connect(btn_delete, SIGNAL(clicked()), this, SLOT(delete_attribute()));
}

attribute_widget::~attribute_widget() {

}

void attribute_widget::setId_parent(int id) {
    id_parent = id;
}

int attribute_widget::getId_parent() {
    return id_parent;
}

void attribute_widget::delete_attribute() {
    close();
    project_data::instance().remove_attribute(this);
    delete this;
}

QString attribute_widget::getCode() {
}
