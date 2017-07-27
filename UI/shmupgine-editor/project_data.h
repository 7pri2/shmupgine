#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H

#include <QStringListModel>
#include <QStandardItemModel>
#include <iostream>
#include <fstream>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <map>
#include "singleton.h"
#include "attribute_widget.h"
#include "list"

#define BTN_WIDTH   32

typedef bool flag;

enum {
    name,
    working_dir,
    compiler,
    compiler_flags,
    engine,
    make
};  // enum for config string list

enum {
    i_path,
    i_id,
    i_width,
    i_height,
    i_zoom
};  // enum for pictures model

enum {
    e_id
};  // enum for entities model

class graphics_manager;
class attribute_widget;
class entities_container;
class select_sprite;
class select_entity;
class editor;

class project_data : public singleton<project_data> {
public:
    friend class singleton<project_data>;
    friend class graphics_manager;
    friend class entities_container;
    friend class select_sprite;
    friend class select_entity;
    friend class editor;

    project_data();
    ~project_data();

    // Pictures
    QString get_pictures_name(int id);
    QString get_pictures_path(int id);
    QString get_pictures_width(int id);
    QString get_pictures_height(int id);
    QString get_pictures_zoom(int id);

    QString get_picture_path(QString name);
    QString get_pictures_code();

    QString get_pictures_name();
    QString get_pictures_path();
    QString get_pictures_width();
    QString get_pictures_height();
    QString get_pictures_zoom();

    void    set_pictures_name(int id, QString text);
    void    set_pictures_path(int id, QString text);
    void    set_pictures_width(int id, QString text);
    void    set_pictures_height(int id, QString text);
    void    set_pictures_zoom(int id, QString text);

    void    set_pictures_name(QString text);
    void    set_pictures_path(QString text);
    void    set_pictures_width(QString text);
    void    set_pictures_height(QString text);
    void    set_pictures_zoom(QString text);

    void    append_picture(QString filename);
    void    remove_picture(int id);

    int picture_max_id;
    int current_picture_id;

    // Entities
    QString get_entity_name();  // Get current's entity's name
    QString get_entity_name(int id);
    QString get_entities_code(QString scene_name);

    void register_entity(QStandardItem *item);
    void remove_entity(int row);

    void update_entity_position(int id, int x, int y);
    void update_entity_pixmap(int id, QPixmap *pic);

    int entity_max_id;
    int current_entity_id;

    // Project config
    QString generate_makefile();
    QStringList prj_configuration;

    // Attributes
    void add_attribute(attribute_widget* attr);
    void update_what_is_visible();
    void remove_attribute(attribute_widget* attr);
    QString get_attributes_code();

    // Scene
    void draw_entities_on_scene();

    // flags
    flag    f_config_changed;

private:
    QGraphicsScene*                 gscene;
    QString                         m_makefile;
    QStandardItemModel*             pictures_model;
    QStandardItemModel*             entities_model;
    std::list<attribute_widget*>    *attr_list;
    std::list<QGraphicsPixmapItem*> *items_list;
    void draw_entity_on_scene(int id);
};

#endif // PROJECT_DATA_H
