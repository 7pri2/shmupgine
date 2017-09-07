#ifndef NEW_PROJECT_H
#define NEW_PROJECT_H

#define BTN_WIDTH   32

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDialog>
#include <QPushButton>
#include <QDir>

#include "project_data.h"

class editor;

class new_project : public QWidget {
    friend class editor;
    Q_OBJECT
public:
    explicit new_project(QWidget *parent = 0);
    ~new_project();

signals:

public slots:
    void    switch_create_btn_state();
    void    create_new_project();

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
    QVBoxLayout*    lay_advanced_config;
    QHBoxLayout*    lay_working_dir;
    QHBoxLayout*    lay_compiler;
    QHBoxLayout*    lay_compiler_flags;
    QHBoxLayout*    lay_engine;
    QHBoxLayout*    lay_make;
    QHBoxLayout*    lay_buttons;
    QHBoxLayout*    lay_show_more;

    QPushButton*    btn_create;
    QPushButton*    btn_cancel;

    QPushButton*    btn_working_dir;
    QPushButton*    btn_compiler;
    QPushButton*    btn_engine;
    QPushButton*    btn_make;

    QCheckBox*      chkbx_show_more;

    // Design management procedure
    void    fill_main_layout();
    void    setup_child_layouts();
    void    resize_buttons();
};

#endif // NEW_PROJECT_H
