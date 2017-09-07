#include "new_project.h"

new_project::new_project(QWidget *parent) : QWidget(parent) {
    setFixedSize(sizeHint());

    lbl_name            = new QLabel(tr("Project name"), this);
    lbl_working_dir     = new QLabel(tr("Create in"), this);
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
    lay_advanced_config = new QVBoxLayout(this);
    lay_working_dir     = new QHBoxLayout(this);
    lay_compiler        = new QHBoxLayout(this);
    lay_compiler_flags  = new QHBoxLayout(this);
    lay_engine          = new QHBoxLayout(this);
    lay_make            = new QHBoxLayout(this);
    lay_buttons         = new QHBoxLayout(this);
    lay_show_more       = new QHBoxLayout(this);

    btn_create  = new QPushButton(tr("&Create"), this);
    btn_cancel  = new QPushButton(tr("&Cancel"), this);

    btn_working_dir = new QPushButton("...", this);
    btn_compiler    = new QPushButton("...", this);
    btn_engine      = new QPushButton("...", this);
    btn_make        = new QPushButton("...", this);

    chkbx_show_more = new QCheckBox(tr("Show advanced configuration"), this);

    connect(le_name, SIGNAL(textChanged(QString)), this, SLOT(switch_create_btn_state()));
    connect(le_compiler, SIGNAL(textChanged(QString)), this, SLOT(switch_create_btn_state()));
    connect(le_compiler_flags, SIGNAL(textChanged(QString)), this, SLOT(switch_create_btn_state()));
    connect(le_engine, SIGNAL(textChanged(QString)), this, SLOT(switch_create_btn_state()));
    connect(le_make, SIGNAL(textChanged(QString)), this, SLOT(switch_create_btn_state()));
    connect(le_working_dir, SIGNAL(textChanged(QString)), this, SLOT(switch_create_btn_state()));
    connect(btn_cancel, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(btn_create, SIGNAL(clicked(bool)), this, SLOT(create_new_project()));

    setWindowTitle(tr("Create new project"));
    resize_buttons();
    setup_child_layouts();
    fill_main_layout();
    switch_create_btn_state();
}

void new_project::fill_main_layout() {
    this->setLayout(lay_mainlayout);
    lay_mainlayout->addWidget(lbl_name);
    lay_mainlayout->addWidget(le_name);
    lay_mainlayout->addWidget(lbl_working_dir);
    lay_mainlayout->addLayout(lay_working_dir);
    lay_mainlayout->addLayout(lay_show_more);
    lay_mainlayout->addLayout(lay_advanced_config);
}

void new_project::setup_child_layouts() {
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

    // Exit buttons
    lay_buttons->addWidget(btn_create);
    lay_buttons->addWidget(btn_cancel);

    // Advanced configuration checkbox
    lay_show_more->addWidget(chkbx_show_more, 0, Qt::AlignRight);

    // Advanced configuration layout
    lay_advanced_config->addLayout(lay_compiler);
    lay_advanced_config->addLayout(lay_compiler_flags);
    lay_advanced_config->addLayout(lay_engine);
    lay_advanced_config->addLayout(lay_make);
    lay_advanced_config->addLayout(lay_buttons);
}

void new_project::resize_buttons() {
    btn_working_dir->setMaximumWidth(BTN_WIDTH);
    btn_compiler->setMaximumWidth(BTN_WIDTH);
    btn_engine->setMaximumWidth(BTN_WIDTH);
    btn_make->setMaximumWidth(BTN_WIDTH);
}

new_project::~new_project() {

}

void new_project::switch_create_btn_state() {
    bool can_be_activated =
        !le_compiler->text().isEmpty()          &&
        !le_compiler_flags->text().isEmpty()    &&
        !le_engine->text().isEmpty()            &&
        !le_make->text().isEmpty()              &&
        !le_name->text().isEmpty()              &&
        !le_working_dir->text().isEmpty();
    btn_create->setEnabled(can_be_activated);
}

void new_project::create_new_project() {
    close();
    QDir projectdir = QDir::root();
    project_data::instance().prj_configuration.replace(working_dir, le_working_dir->text());
    project_data::instance().prj_configuration.replace(name, le_name->text());
    project_data::instance().prj_configuration.replace(compiler, le_compiler->text());
    project_data::instance().prj_configuration.replace(compiler_flags, le_compiler_flags->text());
    project_data::instance().prj_configuration.replace(engine, le_engine->text());
    project_data::instance().prj_configuration.replace(make, le_make->text());
    projectdir.mkpath(le_working_dir->text()+le_name->text());
}
