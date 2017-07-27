#include "script.h"

script::script() : attribute_widget() {
    te_code     = new QPlainTextEdit(this);
    btn_edit    = new QPushButton(tr("Edit"), this);
    s_editor    = new script_editor();
    te_code->setFont(QFont(QString("arial"), 8));
    gb_box->setTitle(tr("Script"));
    te_code->setReadOnly(true);
    lay_groupbox->addWidget(te_code);
    lay_groupbox->addWidget(btn_edit);
    connect(btn_edit, SIGNAL(clicked()), this, SLOT(openEditor()));
    connect(s_editor->btn_save, SIGNAL(clicked()), this, SLOT(getScript()));
    connect(s_editor->btn_cancel, SIGNAL(clicked()), this, SLOT(cancelEditor()));
}

script::~script() {
    delete s_editor;
}

QString script::getCode() {
    QString code;
    code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->allocateAttribute<script>();\n");
    if(!te_code->toPlainText().isEmpty())
        code += QString("\t") + project_data::instance().get_entity_name(id_parent) + QString("->getAttribute<script>()->setLoopFunction( [&]() -> void {\n") + te_code->toPlainText() + QString("\n\t});\n");
    return code;
}

void script::openEditor() {
    s_editor->show();
}

void script::getScript() {
    te_code->setPlainText(s_editor->te_editor->toPlainText());
}

void script::cancelEditor() {
    s_editor->te_editor->setPlainText(te_code->toPlainText());
    s_editor->close();
}
