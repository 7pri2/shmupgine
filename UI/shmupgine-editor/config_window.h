#ifndef CONFIG_WINDOW_H
#define CONFIG_WINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include "config_panel.h"
#include "project_data.h"
#include "graphics_manager.h"

enum {
    config,
    makefile,
    gmanager
};

class config_window : public QMainWindow {
    Q_OBJECT
public:
    explicit config_window(QWidget *parent = 0);
    ~config_window();

signals:

public slots:
    void tab_changed(int current_tab);
    void open_tab(int tab);

private:
    QTabWidget*         m_tab;
    config_panel*       t_config;
    QPlainTextEdit*     t_makefile;
    graphics_manager*   t_gmanager;

    QPushButton*    btn_close;

    QVBoxLayout*    lay_mainlayout;
    QWidget*        wid_central;

    void setup_layouts();
    void design_tabs();
};

#endif // CONFIG_WINDOW_H
