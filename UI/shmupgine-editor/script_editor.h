#ifndef SCRIPT_EDITOR_H
#define SCRIPT_EDITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>

class script;

class script_editor : public QWidget {
    friend class script;
    Q_OBJECT
public:
    explicit script_editor(QWidget *parent = 0);
    ~script_editor();

signals:

public slots:
    void disable_btn();
    void enable_btn();

private:
    QPlainTextEdit* te_editor;
    QPushButton*    btn_save;
    QPushButton*    btn_cancel;
    QHBoxLayout*    lay_btn;
    QVBoxLayout*    lay_mainlayout;
};

#endif // SCRIPT_EDITOR_H
