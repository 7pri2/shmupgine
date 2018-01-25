#ifndef ATTRIBUTE_PANEL_H
#define ATTRIBUTE_PANEL_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "model_entity_block.h"
#include "attribute.h"

class project_data;
class editor;

class attribute_panel : public QWidget {
    Q_OBJECT
public:
    friend class editor;

    explicit attribute_panel(model_entity_block *parent = 0);
    ~attribute_panel();

signals:

public slots:
    void add_attribute(attribute* attr);

private:
    QPushButton*    btn_new;
    QVBoxLayout*    lay_mainlayout;

    void setup_layouts();
};

#endif // ATTRIBUTE_PANEL_H
