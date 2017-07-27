#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsItem>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>

#include "project_data.h"

#define MAX_INT 429496729

class graphics_manager : public QWidget {
    Q_OBJECT
public:
    friend class project_data;
    explicit graphics_manager(QWidget *parent = 0);
    ~graphics_manager();

signals:

private slots:
    void add_picture();
    void fill_infos(QModelIndex index);
    void update_infos(QStandardItem* item);
    void update_model();
    void delete_picture();
    void dis_or_enable_details();

private:
    QListView*          lv_pictures_view;

    QGraphicsScene* gs_scene;
    QGraphicsView*  gv_view;

    QLabel* lbl_name;
    QLabel* lbl_path;
    QLabel* lbl_width;
    QLabel* lbl_height;
    QLabel* lbl_zoom;

    QLineEdit*  le_name;
    QLineEdit*  le_path;
    QLineEdit*  le_width;
    QLineEdit*  le_height;
    QLineEdit*  le_zoom;

    QHBoxLayout*    lay_mainlayout;
    QVBoxLayout*    lay_details;
    QVBoxLayout*    lay_pictures_list;
    QHBoxLayout*    lay_buttons;
    QHBoxLayout*    lay_width;
    QHBoxLayout*    lay_height;
    QHBoxLayout*    lay_path;
    QHBoxLayout*    lay_name;

    QPushButton*    btn_open;
    QPushButton*    btn_remove;

    void setup_layouts();
    void apply_constraints();
};

#endif // GRAPHICS_MANAGER_H
