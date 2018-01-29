#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QPushButton>
#include <QIntValidator>
#include "project_data.h"

#define CROSS_1 "\u2A09"
#define CROSS_2 "\u2717"

class attribute : public QWidget {
    Q_OBJECT
public:
    explicit attribute();
    ~attribute();

    void setId_parent(int id);
    int getId_parent();
    virtual QString getCode();

signals:

public slots:
    void delete_attribute();

protected:
    QCheckBox*      cb_enabled;
    QVBoxLayout*    lay_groupbox;
    QGroupBox*      gb_box;
    QPushButton*    btn_delete;

    int id_parent;

private:
    QVBoxLayout*    lay_mainlayout;
};

#endif // ATTRIBUTE_H
