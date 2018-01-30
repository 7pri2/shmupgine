#include "attribute.h"
#include "entities_attributes_panel.h"

attribute::attribute(entities_attributes_panel* parent) : QWidget() {
    /* * * * * * * *
     * ALLOCATION  *
     * * * * * * * */

    container       = parent;
    cb_enabled      = new QCheckBox(tr("Enabled"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    lay_groupbox    = new QVBoxLayout(this);
    gb_box          = new QGroupBox(this);
    btn_delete      = new QPushButton(QString::fromUtf8(CROSS_2), this);
    id_parent       = -1;

    /* * * * * * * * * * *
     * WIDGET MANAGEMENT *
     * * * * * * * * * * */

    btn_delete->setStyleSheet("border: none;");
    btn_delete->setMaximumSize(20, 20);

    cb_enabled->setChecked(true);
    lay_groupbox->addWidget(cb_enabled);
    gb_box->setLayout(lay_groupbox);
    lay_mainlayout->addWidget(gb_box);
    setLayout(lay_mainlayout);

    /* * * * * * * *
     * CONNECTIONS *
     * * * * * * * */

    connect(btn_delete, SIGNAL(clicked()), this, SLOT(delete_attribute()));
}

attribute::~attribute() {

}

void attribute::setId_parent(int id) {
    id_parent = id;
}

int attribute::getId_parent() {
    return id_parent;
}

void attribute::delete_attribute() {
    close();
    container->remove_attribute(this);
    delete this;
}

QString attribute::getCode() {
}
