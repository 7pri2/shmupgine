#ifndef W_GRAPHICS_MANAGER_H
#define W_GRAPHICS_MANAGER_H

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
#include "singleton.h"
#include "select_window.h"

enum {
    PIC_PATH    = 0,
    PIC_WIDTH   = 1,
    PIC_HEIGHT  = 2
};

class w_graphics_manager : public QWidget, public Singleton<w_graphics_manager> {
    Q_OBJECT

    friend class Singleton<w_graphics_manager>;

public:
    QString select_picture();

private slots:
    void add_picture();
    void fill_infos(QModelIndex index);
    void update_infos(QStandardItem* item);
    void update_model();
    void delete_picture();
    void dis_or_enable_details();
    void append_picture(QString filename);

private:
    w_graphics_manager(QWidget *parent = 0);
    ~w_graphics_manager();

    QListView*  lv_pictures_view;

    QGraphicsScene* gs_scene;
    QGraphicsView*  gv_view;

    QLabel* lbl_name;
    QLabel* lbl_path;
    QLabel* lbl_width;
    QLabel* lbl_height;

    QLineEdit*  le_name;
    QLineEdit*  le_path;
    QLineEdit*  le_width;
    QLineEdit*  le_height;

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

    select_window*  select;

    QStandardItemModel* pictures_model;
    QModelIndex         current_selection;
};

#endif // W_GRAPHICS_MANAGER_H
