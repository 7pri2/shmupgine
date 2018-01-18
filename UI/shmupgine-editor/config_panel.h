#ifndef config_panel_H
#define config_panel_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDialog>
#include <QPushButton>

#include "project_data.h"

class config_panel : public QWidget {
    Q_OBJECT
public:
    explicit config_panel(QWidget *parent = 0);
    ~config_panel();

signals:

public slots:
    void fill_fields();
    void update_name(QString n_name);
    void update_working_dir(QString n_working_dir);
    void update_compiler(QString n_compiler);
    void update_compiler_flags(QString n_compiler_flags);
    void update_make(QString n_make);
    void update_engine(QString n_engine);

private:
    QLabel* lbl_name;
    QLabel* lbl_working_dir;
    QLabel* lbl_compiler;
    QLabel* lbl_compiler_flags;
    QLabel* lbl_engine;
    QLabel* lbl_make;

    QLineEdit*  le_name;
    QLineEdit*  le_working_dir;
    QLineEdit*  le_compiler;
    QLineEdit*  le_compiler_flags;
    QLineEdit*  le_engine;
    QLineEdit*  le_make;

    QVBoxLayout*    lay_mainlayout;
    QHBoxLayout*    lay_working_dir;
    QHBoxLayout*    lay_compiler;
    QHBoxLayout*    lay_compiler_flags;
    QHBoxLayout*    lay_engine;
    QHBoxLayout*    lay_make;
    QHBoxLayout*    lay_buttons;

    QPushButton*    btn_working_dir;
    QPushButton*    btn_compiler;
    QPushButton*    btn_engine;
    QPushButton*    btn_make;

    // Design management procedure
    void    fill_main_layout();
    void    setup_child_layouts();
    void    resize_buttons();

};

#endif // config_panel_H
