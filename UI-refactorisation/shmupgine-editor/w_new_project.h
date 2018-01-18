#ifndef W_NEW_PROJECT_H
#define W_NEW_PROJECT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDialog>
#include <QPushButton>
#include <QDir>

#include "singleton.h"
#include "project_data.h"

class w_new_project : public QWidget, public Singleton<w_new_project> {
    Q_OBJECT

    friend class Singleton<w_new_project>;

public:

public slots:
    void    switch_create_btn_state();
    void    create_new_project();

private:
    w_new_project(const w_new_project&);
    w_new_project(QWidget *parent = 0);
    ~w_new_project();

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
};

#endif // W_NEW_PROJECT_H
