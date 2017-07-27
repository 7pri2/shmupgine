#include "config_panel.h"

config_panel::config_panel(QWidget *parent) : QWidget(parent) {
    lbl_name            = new QLabel(tr("Project name"), this);
    lbl_working_dir     = new QLabel(tr("Working directory"), this);
    lbl_compiler        = new QLabel(tr("Compiler"), this);
    lbl_compiler_flags  = new QLabel(tr("Compiler flags"), this);
    lbl_engine          = new QLabel(tr("Path to shmupgine"), this);
    lbl_make            = new QLabel(tr("Make"), this);

    le_name             = new QLineEdit(project_data::instance().prj_configuration.at(name), this);
    le_working_dir      = new QLineEdit(project_data::instance().prj_configuration.at(working_dir), this);
    le_compiler         = new QLineEdit(project_data::instance().prj_configuration.at(compiler), this);
    le_compiler_flags   = new QLineEdit(project_data::instance().prj_configuration.at(compiler_flags), this);
    le_engine           = new QLineEdit(project_data::instance().prj_configuration.at(engine), this);
    le_make             = new QLineEdit(project_data::instance().prj_configuration.at(make), this);

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

    resize_buttons();
    setup_child_layouts();
    fill_main_layout();

    connect(le_compiler, SIGNAL(textChanged(QString)), this, SLOT(update_compiler(QString)));
    connect(le_working_dir, SIGNAL(textChanged(QString)), this, SLOT(update_working_dir(QString)));
    connect(le_compiler_flags, SIGNAL(textChanged(QString)), this, SLOT(update_compiler_flags(QString)));
    connect(le_engine, SIGNAL(textChanged(QString)), this, SLOT(update_engine(QString)));
    connect(le_make, SIGNAL(textChanged(QString)), this, SLOT(update_make(QString)));
    connect(le_name, SIGNAL(textChanged(QString)), this, SLOT(update_name(QString)));
}

config_panel::~config_panel() {

}

void config_panel::fill_main_layout() {
    this->setLayout(lay_mainlayout);
    lay_mainlayout->addWidget(lbl_name);
    lay_mainlayout->addWidget(le_name);
    lay_mainlayout->addWidget(lbl_working_dir);
    lay_mainlayout->addLayout(lay_working_dir);
    lay_mainlayout->addLayout(lay_compiler);
    lay_mainlayout->addLayout(lay_compiler_flags);
    lay_mainlayout->addLayout(lay_engine);
    lay_mainlayout->addLayout(lay_make);
}

void config_panel::setup_child_layouts() {
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
}

void config_panel::resize_buttons() {
    btn_working_dir->setMaximumWidth(BTN_WIDTH);
    btn_compiler->setMaximumWidth(BTN_WIDTH);
    btn_engine->setMaximumWidth(BTN_WIDTH);
    btn_make->setMaximumWidth(BTN_WIDTH);
}

void config_panel::update_name(QString n_name) {
    project_data::instance().prj_configuration.replace(name, n_name);
    project_data::instance().f_config_changed = true;
}

void config_panel::update_compiler(QString n_compiler) {
    project_data::instance().prj_configuration.replace(compiler, n_compiler);
    project_data::instance().f_config_changed = true;
}

void config_panel::update_compiler_flags(QString n_compiler_flags) {
    project_data::instance().prj_configuration.replace(compiler_flags, n_compiler_flags);
    project_data::instance().f_config_changed = true;
}

void config_panel::update_working_dir(QString n_working_dir) {
    project_data::instance().prj_configuration.replace(working_dir, n_working_dir);
    project_data::instance().f_config_changed = true;
}

void config_panel::update_make(QString n_make) {
    project_data::instance().prj_configuration.replace(make, n_make);
    project_data::instance().f_config_changed = true;
}

void config_panel::update_engine(QString n_engine) {
    project_data::instance().prj_configuration.replace(engine, n_engine);
    project_data::instance().f_config_changed = true;
}

