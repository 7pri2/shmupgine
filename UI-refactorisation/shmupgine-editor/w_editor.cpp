#include "w_editor.h"

w_editor::w_editor(QWidget *parent) : QMainWindow(parent){
    /* * * * * * * * * * *
     * MEMORY ALLOCATION *
     * * * * * * * * * * */

    /// Menu Bar
    mb_menuBar      = new QMenuBar(this);
    // File
    m_file  = new QMenu(tr("File"), this);
    a_new   = new QAction(tr("&New project"), this);
    a_open  = new QAction(tr("&Open project"), this);
    a_save  = new QAction(tr("&Save project"), this);
    a_close = new QAction(tr("&Close project"), this);
    a_exit  = new QAction(tr("&Exit"), this);
    // Config
    m_config_window = new QMenu(tr("Config"), this);
    a_project       = new QAction(tr("&Project"), this);
    a_makefile      = new QAction(tr("&Makefile"), this);
    // Ressources
    m_ressources            = new QMenu(tr("Ressources"), this);
    a_graphics              = new QAction(tr("&Graphics manager"), this);
    a_entities_collection   = new QAction(tr("&Entities collection"), this);
    // Build
    m_build         = new QMenu(tr("Build"), this);
    a_run           = new QAction(tr("&Run"), this);
    a_build         = new QAction(tr("&Build"), this);
    a_build_and_run = new QAction(tr("Build a&nd run"), this);

    /* * * * * * * * *
     * SETUP MENUBAR *
     * * * * * * * * */

    setMenuBar(mb_menuBar);

    // File
    mb_menuBar->addMenu(m_file);
    m_file->addAction(a_new);
    m_file->addAction(a_open);
    m_file->addSeparator();
    m_file->addAction(a_save);
    m_file->addSeparator();
    m_file->addAction(a_close);
    m_file->addSeparator();
    m_file->addAction(a_exit);
    // Config
    mb_menuBar->addMenu(m_config_window);
    m_config_window->addAction(a_project);
    m_config_window->addAction(a_makefile);
    // Ressources
    mb_menuBar->addMenu(m_ressources);
    m_ressources->addAction(a_graphics);
    m_ressources->addAction(a_entities_collection);
    // Build
    mb_menuBar->addMenu(m_build);
    m_build->addAction(a_run);
    m_build->addAction(a_build);
    m_build->addAction(a_build_and_run);

    /* * * * * * * *
     * CONNECTIONS *
     * * * * * * * */

    connect(a_exit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(m_ressources, SIGNAL(triggered(QAction*)), this, SLOT(handle_ressources_choice(QAction*)));
    connect(m_file, SIGNAL(triggered(QAction*)), this, SLOT(handle_file_choice(QAction*)));
    connect(m_config_window, SIGNAL(triggered(QAction*)), this, SLOT(handle_config_choice(QAction*)));
}

w_editor::~w_editor() {

}

void w_editor::handle_config_choice(QAction *a) {
    if(a == a_project)
        p_config_panel::Instance()->show();
}

void w_editor::handle_file_choice(QAction *a) {
    if(a == a_new)
        w_new_project::Instance()->show();
}

void w_editor::handle_ressources_choice(QAction *a) {
    if(a == a_graphics)
        p_graphics_manager::Instance()->show();
    else if(a == a_entities_collection)
        p_entities_collection::Instance()->show();

}
