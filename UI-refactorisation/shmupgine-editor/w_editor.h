#ifndef W_EDITOR_H
#define W_EDITOR_H

#include <QSplitter>
#include <QWidgetAction>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include "singleton.h"
#include "windows_panels.h"

class w_editor : public QMainWindow, public Singleton<w_editor> {
    Q_OBJECT

    friend class Singleton<w_editor>;

public:

private:
    w_editor(const w_editor&);
    w_editor(QWidget *parent = 0);
    virtual ~w_editor();

    /// Menu Bar
    QMenuBar*   mb_menuBar;
    // File
    QMenu*      m_file;
    QAction*    a_new;
    QAction*    a_open;
    QAction*    a_save;
    QAction*    a_close;
    QAction*    a_exit;
    // Config
    QMenu*      m_config_window;
    QAction*    a_project;
    QAction*    a_makefile;
    // Ressources
    QMenu*      m_ressources;
    QAction*    a_graphics;
    QAction*    a_entities_collection;
    // Build
    QMenu*      m_build;
    QAction*    a_run;
    QAction*    a_build;
    QAction*    a_build_and_run;
};

#endif // W_EDITOR_H
