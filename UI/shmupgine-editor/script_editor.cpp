#include "script_editor.h"

script_editor::script_editor(QWidget *parent) : QWidget(parent) {
    te_editor   = new QPlainTextEdit(this);
    btn_save    = new QPushButton(tr("Save"), this);
    btn_cancel  = new QPushButton(tr("Cancel"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    lay_btn         = new QHBoxLayout(this);

    lay_mainlayout->addWidget(te_editor);
    lay_btn->addWidget(btn_save);
    lay_btn->addWidget(btn_cancel);
    lay_mainlayout->addLayout(lay_btn);

    disable_btn();

    connect(btn_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(te_editor, SIGNAL(textChanged()), this, SLOT(enable_btn()));
    connect(btn_save, SIGNAL(clicked()), this, SLOT(disable_btn()));
}

script_editor::~script_editor() {}

void script_editor::disable_btn() {
    btn_cancel->setEnabled(false);
    btn_save->setEnabled(false);
}

void script_editor::enable_btn() {
    btn_cancel->setEnabled(true);
    btn_save->setEnabled(true);
}
