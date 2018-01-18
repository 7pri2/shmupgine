#include "config_window.h"

config_window::config_window(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle(tr("Project configuration"));

    m_tab       = new QTabWidget(this);
    t_config    = new config_panel(this);
    t_makefile  = new QPlainTextEdit(this);
    t_gmanager  = new graphics_manager(this);

    btn_close   = new QPushButton(tr("Close"), this);

    lay_mainlayout  = new QVBoxLayout(this);
    wid_central     = new QWidget(this);

    m_tab->addTab(t_config, tr("&Project"));
    m_tab->addTab(t_makefile, "&Makefile");
    m_tab->addTab(t_gmanager, tr("&Graphics manager"));

    setup_layouts();

    connect(m_tab, SIGNAL(currentChanged(int)), this, SLOT(tab_changed(int)));
    connect(btn_close, SIGNAL(clicked()), this, SLOT(close()));
}

config_window::~config_window() {}

void config_window::tab_changed(int current_tab) {
    switch(current_tab) {
    case makefile:
        t_makefile->setPlainText(project_data::instance().generate_makefile());
        break;
    default:
        break;
    }
}

void config_window::setup_layouts() {
    lay_mainlayout->addWidget(m_tab);
    lay_mainlayout->addWidget(btn_close);

    wid_central->setLayout(lay_mainlayout);
    setCentralWidget(wid_central);
}

void config_window::open_tab(int tab) {
    show();
    t_config->fill_fields();
    m_tab->setCurrentIndex(tab);
}
