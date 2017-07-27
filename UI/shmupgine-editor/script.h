#ifndef SCRIPT_H
#define SCRIPT_H

#include "attribute_widget.h"
#include "script_editor.h"
#include <QPlainTextEdit>

class script : public attribute_widget {
    Q_OBJECT
public:
    script();
    ~script();

    virtual QString getCode();

private slots:
    void openEditor();
    void getScript();
    void cancelEditor();

private:
    QPlainTextEdit* te_code;
    QPushButton*    btn_edit;
    script_editor*  s_editor;
};

#endif // SCRIPT_H
