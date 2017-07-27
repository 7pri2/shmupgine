#ifndef ATTRIBUTES_CONTAINER_H
#define ATTRIBUTES_CONTAINER_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "attribute_widget.h"
#include "properties.h"

class project_data;
class editor;

class attributes_container : public QWidget {
    Q_OBJECT
public:
    friend class editor;

    explicit attributes_container(QWidget *parent = 0);
    ~attributes_container();

signals:

public slots:
    void add_attribute(attribute_widget* attr);

private:
    QPushButton*    btn_new;
    QVBoxLayout*    lay_mainlayout;

    void setup_layouts();
};

#endif // ATTRIBUTES_CONTAINER_H
