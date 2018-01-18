#include "p_config_panel.h"

p_config_panel::p_config_panel(QWidget *parent) : QWidget(parent) {
    /* * * * * * * * * * *
     * MEMORY ALLOCATION *
     * * * * * * * * * * */
    lbl_name            = new QLabel(tr("Project name"), this);
    lbl_working_dir     = new QLabel(tr("Working directory"), this);
    lbl_compiler        = new QLabel(tr("Compiler"), this);
    lbl_compiler_flags  = new QLabel(tr("Compiler flags"), this);
    lbl_engine          = new QLabel(tr("Path to shmupgine"), this);
    lbl_make            = new QLabel(tr("Make"), this);

    le_name             = new QLineEdit(project_data::Instance()->prj_config[NAME], this);
    le_working_dir      = new QLineEdit(project_data::Instance()->prj_config[WORKING_DIR], this);
    le_compiler         = new QLineEdit(project_data::Instance()->prj_config[COMPILER_PATH], this);
    le_compiler_flags   = new QLineEdit(project_data::Instance()->prj_config[COMPILER_FLAGS], this);
    le_engine           = new QLineEdit(project_data::Instance()->prj_config[ENGINE_PATH], this);
    le_make             = new QLineEdit(project_data::Instance()->prj_config[MAKE_PATH], this);

    lay_mainlayout      = new QVBoxLayout(this);
    lay_working_dir     = new QHBoxLayout(this);
    lay_compiler        = new QHBoxLayout(this);
    lay_compiler_flags  = new QHBoxLayout(this);
    lay_engine          = new QHBoxLayout(this);
    lay_make            = new QHBoxLayout(this);
    lay_buttons         = new QHBoxLayout(this);

    btn_working_dir = new QPushButton("...", this);
    btn_compiler    = new QPushButton("...", this);
    btn_engine      = new QPushButton("...", this);
    btn_make        = new QPushButton("...", this);

    /* * * * * * * * * * *
     * WINDOW MANAGEMENT *
     * * * * * * * * * * */

    // Working dir
    lay_working_dir->addWidget(le_working_dir);
    lay_working_dir->addWidget(btn_working_dir);

    // Compiler
    lay_compiler->addWidget(lbl_compiler);
    lay_compiler->addWidget(le_compiler);
    lay_compiler->addWidget(btn_compiler);

    // Compiler flags
    lay_compiler_flags->addWidget(lbl_compiler_flags);
    lay_compiler_flags->addWidget(le_compiler_flags);

    // Engine path
    lay_engine->addWidget(lbl_engine);
    lay_engine->addWidget(le_engine);
    lay_engine->addWidget(btn_engine);

    // Make
    lay_make->addWidget(lbl_make);
    lay_make->addWidget(le_make);
    lay_make->addWidget(btn_make);

    // Main Layout
    this->setLayout(lay_mainlayout);
    lay_mainlayout->addWidget(lbl_name);
    lay_mainlayout->addWidget(le_name);
    lay_mainlayout->addWidget(lbl_working_dir);
    lay_mainlayout->addLayout(lay_working_dir);
    lay_mainlayout->addLayout(lay_compiler);
    lay_mainlayout->addLayout(lay_compiler_flags);
    lay_mainlayout->addLayout(lay_engine);
    lay_mainlayout->addLayout(lay_make);

    // Resize buttons
    btn_working_dir->setMaximumWidth(BTN_WIDTH);
    btn_compiler->setMaximumWidth(BTN_WIDTH);
    btn_engine->setMaximumWidth(BTN_WIDTH);
    btn_make->setMaximumWidth(BTN_WIDTH);

    /* * * * * * * *
     * CONNECTIONS *
     * * * * * * * */

    connect(le_compiler, SIGNAL(textChanged(QString)), this, SLOT(update_compiler(QString)));
    connect(le_working_dir, SIGNAL(textChanged(QString)), this, SLOT(update_working_dir(QString)));
    connect(le_compiler_flags, SIGNAL(textChanged(QString)), this, SLOT(update_compiler_flags(QString)));
    connect(le_engine, SIGNAL(textChanged(QString)), this, SLOT(update_engine(QString)));
    connect(le_make, SIGNAL(textChanged(QString)), this, SLOT(update_make(QString)));
    connect(le_name, SIGNAL(textChanged(QString)), this, SLOT(update_name(QString)));

    fill_fields();
}

p_config_panel::~p_config_panel() {

}

void p_config_panel::update_name(QString n_name) {
    project_data::Instance()->prj_config[NAME] = n_name;
    project_data::Instance()->f_config_changed = true;
}

void p_config_panel::update_compiler(QString n_compiler) {
    project_data::Instance()->prj_config[COMPILER_PATH] = n_compiler;
    project_data::Instance()->f_config_changed = true;
}

void p_config_panel::update_compiler_flags(QString n_compiler_flags) {
    project_data::Instance()->prj_config[COMPILER_FLAGS] = n_compiler_flags;
    project_data::Instance()->f_config_changed = true;
}

void p_config_panel::update_working_dir(QString n_working_dir) {
    project_data::Instance()->prj_config[WORKING_DIR] = n_working_dir;
    project_data::Instance()->f_config_changed = true;
}

void p_config_panel::update_make(QString n_make) {
    project_data::Instance()->prj_config[MAKE_PATH] = n_make;
    project_data::Instance()->f_config_changed = true;
}

void p_config_panel::update_engine(QString n_engine) {
    project_data::Instance()->prj_config[ENGINE_PATH] = n_engine;
    project_data::Instance()->f_config_changed = true;
}

void p_config_panel::fill_fields() {
    le_name->setText(project_data::Instance()->prj_config[NAME]);
    le_working_dir->setText(project_data::Instance()->prj_config[WORKING_DIR]);
    le_compiler->setText(project_data::Instance()->prj_config[COMPILER_PATH]);
    le_compiler_flags->setText(project_data::Instance()->prj_config[COMPILER_FLAGS]);
    le_engine->setText(project_data::Instance()->prj_config[ENGINE_PATH]);
    le_make->setText(project_data::Instance()->prj_config[MAKE_PATH]);
}

