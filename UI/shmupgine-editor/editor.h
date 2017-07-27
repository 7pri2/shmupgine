#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QSplitter>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <fstream>
#include <QProcess>
#include <QScrollArea>
#include "new_project.h"
#include "config_window.h"
#include "project_data.h"
#include "physics.h"
#include "graphic_renderer.h"
#include "attributes_container.h"
#include "destructor.h"
#include "entities_container.h"
#include "controls.h"
#include "script.h"

class editor : public QMainWindow {
    Q_OBJECT
public:
    explicit editor(QWidget *parent = 0);
    ~editor();

signals:

public slots:
     void add_entity();
     void request_attribute_menu();
     void manage_attribute_menu_choice(QAction* a);
     void manage_config_menu_choice(QAction* a);
     void manage_file_menu_choice(QAction* a);
     void manage_build_menu_choice(QAction* a);
     void create_attribute(attribute_widget* attr);
     void create_attribute(int id, attribute_widget* attr);

private:
    new_project*        win_new_project;
    config_window*      win_config;

    attributes_container*   panel_attributes;
    entities_container*     panel_entities;
    QGraphicsView*          panel_graphic_view;

    QHBoxLayout*    lay_mainlayout;
    QWidget*        wg_centerWidget;
    QSplitter*      sp_splitter;

    QMenu*      m_choose_attribute;
    QAction*    a_physics;
    QAction*    a_graphic_renderer;
    QAction*    a_destructor;

    /// Menu Bar
    QMenuBar*   mb_menuBar;
    // File
    QMenu*      m_file;
    QAction*    a_new;
    QAction*    a_open;
    QAction*    a_save;
    QAction*    a_close;
    // Config
    QMenu*      m_config_window;
    QAction*    a_project;
    QAction*    a_makefile;
    QAction*    a_graphics;
    QAction*    a_controls;
    QAction*    a_script;
    // Build
    QMenu*      m_build;
    QAction*    a_run;
    QAction*    a_build;
    QAction*    a_build_and_run;

    QScrollArea*    sa_scroll_attributes;

    void setup_layouts();
    void setup_attribute_menu();
    void setup_window_menu();

    void build();
    void run();
    void build_and_run();
    void create_main_file();
    void create_makefile();
    void create_clear_gview();
};

#endif // EDITOR_H
