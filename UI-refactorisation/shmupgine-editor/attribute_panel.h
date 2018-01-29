#ifndef ATTRIBUTE_PANEL_H
#define ATTRIBUTE_PANEL_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QVBoxLayout>
#include "model_entity_block.h"
#include "attribute.h"

class attribute_panel : public QWidget {
    Q_OBJECT
public:
    friend class editor;

    explicit attribute_panel(model_entity_block *parent = 0);
    ~attribute_panel();

signals:

public slots:
    void showMenu();
    void handle_Actions(QAction*);

private:
    void add_attribute(attribute* attr);

    QPushButton*    btn_new;
    QVBoxLayout*    lay_mainlayout;

    // Menu
    QMenu*      m_choose_attribute;
    QAction*    a_physics;
    QAction*    a_graphic_renderer;
    QAction*    a_destructor;
    QAction*    a_controls;

    void setup_layouts();
};

#endif // ATTRIBUTE_PANEL_H
