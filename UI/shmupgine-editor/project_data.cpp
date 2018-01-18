#include <fstream>
#include "project_data.h"
#include "graphic_renderer.h"
#include "properties.h"

project_data::project_data() {
    pictures_model  = new QStandardItemModel();
    entities_model  = new QStandardItemModel();
    attr_list       = new std::list<attribute_widget*>;
    items_list      = new std::list<QGraphicsPixmapItem*>;
    gscene          = new QGraphicsScene;

    current_picture_id  = 0;
    picture_max_id      = 0;
    entity_max_id       = 0;
    current_entity_id   = 0;

    f_config_changed = true;

    prj_configuration << "";    // name of the project
    CREATE_INFORMATIONS
}

project_data::~project_data() {
}

QString project_data::generate_makefile() {
    if(f_config_changed) {
        f_config_changed = false;
        QString filename = QString(prj_configuration.at(engine))+QString("base_makefile");
        std::ifstream base_makefile((filename).toStdString().c_str());

        if(!base_makefile) {
            std::cerr << QString(QObject::tr("Can't read file ")).toStdString()
                      << filename.toStdString()
                      << QString(QObject::tr(". Abort.")).toStdString()
                      << std::endl;
            exit(EXIT_FAILURE);
        }

        m_makefile  = QString("CXX=")          + prj_configuration.at(compiler)        + QString("\n")
                    + QString("CXXFLAGS=")     + prj_configuration.at(compiler_flags)  + QString("\n")
                    + QString("LIBPATH=")      + prj_configuration.at(engine)          + QString("\n")
                    + QString("PROJECT_PATH=")  + prj_configuration.at(working_dir)     + QString("\n")
                    + QString("PROJECT_NAME=") + prj_configuration.at(name)            + QString("\n");
        std::string str;
        getline(base_makefile, str, (char)base_makefile.eof());
            m_makefile += QString::fromStdString(str);
    }
    return m_makefile;
}

QString project_data::get_pictures_name(int id) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            return pictures_model->item(i)->text();
    return "";
}

QString project_data::get_pictures_path(int id) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id, 0).data().toInt() == id)
            return pictures_model->index(i,0).child(i_path,0).data().toString();
    return "";
}

QString project_data::get_pictures_width(int id) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            return pictures_model->index(i,0).child(i_width,0).data().toString();
    return "";
}

QString project_data::get_pictures_height(int id) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            return pictures_model->index(i,0).child(i_height,0).data().toString();
    return "";
}

QString project_data::get_pictures_zoom(int id) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            return pictures_model->index(i,0).child(i_zoom,0).data().toString();
    return "";
}

QString project_data::get_picture_path(QString name) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().data().toString() == name)
            return pictures_model->item(i)->index().child(i_path, 0).data().toString();
    return "";
}

QString project_data::get_pictures_name() {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            return pictures_model->item(i)->text();
    return "";
}

QString project_data::get_pictures_path() {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id, 0).data().toInt() == current_picture_id)
            return pictures_model->index(i,0).child(i_path,0).data().toString();
    return "";
}

QString project_data::get_pictures_width() {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            return pictures_model->index(i,0).child(i_width,0).data().toString();
    return "";
}

QString project_data::get_pictures_height() {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            return pictures_model->index(i,0).child(i_height,0).data().toString();
    return "";
}

QString project_data::get_pictures_zoom() {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            return pictures_model->index(i,0).child(i_zoom,0).data().toString();
    return "";
}

void project_data::set_pictures_path(int id, QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            pictures_model->item(i)->child(i_path)->setText(text);
}

void project_data::set_pictures_name(int id, QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            pictures_model->item(i)->setText(text);
}

void project_data::set_pictures_width(int id, QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id){
            pictures_model->item(i)->child(i_width)->setText(text);
            std::cout << pictures_model->item(i)->child(i_width)->text().toStdString();
        }
}

void project_data::set_pictures_height(int id, QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            pictures_model->item(i)->child(i_height)->setText(text);
}

void project_data::set_pictures_zoom(int id, QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            pictures_model->item(i)->child(i_zoom)->setText(text);
}

void project_data::set_pictures_path(QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            pictures_model->item(i)->child(i_path)->setText(text);
}

void project_data::set_pictures_name(QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            pictures_model->item(i)->setText(text);
}

void project_data::set_pictures_width(QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id){
            pictures_model->item(i)->child(i_width)->setText(text);
            std::cout << pictures_model->item(i)->child(i_width)->text().toStdString();
        }
}

void project_data::set_pictures_height(QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            pictures_model->item(i)->child(i_height)->setText(text);
}

void project_data::set_pictures_zoom(QString text) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == current_picture_id)
            pictures_model->item(i)->child(i_zoom)->setText(text);
}

void project_data::append_picture(QString filename) {
    picture_max_id++;
    QPixmap file = QPixmap(filename);
    QStandardItem* picture = new QStandardItem(filename);
    picture->setIcon(QIcon(file));
    pictures_model->appendRow(picture);  // name
    picture->appendRow(new QStandardItem(filename));   // path
    picture->appendRow(new QStandardItem(QString::number(picture_max_id))); // id
    picture->appendRow(new QStandardItem(QString::number(file.width())));   // width
    picture->appendRow(new QStandardItem(QString::number(file.height())));  // height
}


void project_data::remove_picture(int id) {
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        if(pictures_model->item(i)->index().child(i_id,0).data().toInt() == id)
            pictures_model->removeRow(i);
}

QString project_data::get_entity_name() {
    for(int i = 0; i < entities_model->rowCount(); ++i) {
        if(entities_model->index(i,0).child(e_id,0).data().toInt() == current_entity_id)
            return entities_model->index(i,0).data().toString();
    }
    return "";
}

QString project_data::get_entity_name(int id) {
    for(int i = 0; i < entities_model->rowCount(); ++i) {
        if(entities_model->index(i,0).child(e_id,0).data().toInt() == id)
            return entities_model->index(i,0).data().toString();
    }
    return "";
}


QString project_data::get_entities_code(QString scene_name) {
    QString code;
    for(int i = 0; i < entities_model->rowCount(); ++i)
        code += QString("\t") + scene_name + QString(".add_entity(") + entities_model->index(i, 0).data().toString() + ");\n";
    return code;
}

void project_data::register_entity(QStandardItem *item) {
    entities_model->appendRow(item);
    items_list->push_back(new QGraphicsPixmapItem);
    gscene->addItem(items_list->back());
    items_list->back()->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void project_data::add_attribute(attribute_widget *attr) {
    attr_list->push_back(attr);
}

void project_data::update_what_is_visible() {
    int id = project_data::instance().current_entity_id;
    for(std::list<attribute_widget*>::iterator it = attr_list->begin(); it!= attr_list->end(); ++it) {
        (*it)->setVisible((*it)->getId_parent() == id);
        std::cout << (*it)->getId_parent() << "/" << id << std::endl;
    }
}

void project_data::remove_attribute(attribute_widget *attr) {
    attr_list->remove(attr);
}

QString project_data::get_attributes_code() {
    QString code;
    for(std::list<attribute_widget*>::iterator it = attr_list->begin(); it != attr_list->end(); ++it)
        code += (*it)->getCode();
    return code;
}

QString project_data::get_pictures_code() {
    QString code;
    for(int i = 0; i < pictures_model->rowCount(); ++i)
        code += QString("\tgmanager::new_texture(\"") + pictures_model->index(i, 0).data().toString() + QString("\", \"") + pictures_model->index(i, 0).child(i_path, 0).data().toString() + QString("\", ") + pictures_model->index(i, 0).child(i_width, 0).data().toString() + QString(", ") + pictures_model->index(i, 0).child(i_height, 0).data().toString() + QString(");\n");
    return code;
}


void project_data::remove_entity(int row) {
    int id = entities_model->index(row, 0).child(e_id, 0).data().toInt();
    entities_model->removeRow(row);
    std::list<QGraphicsPixmapItem*>::iterator it = items_list->begin();
    std::advance(it, row);
    items_list->remove(*it);
    for(std::list<attribute_widget*>::iterator it = attr_list->begin(); it != attr_list->end(); ++it)
        if((*it)->getId_parent() == id) {
            remove_attribute(*it);
            (*it)->hide();
            it = attr_list->begin();
        }
}

void project_data::draw_entities_on_scene() {
    QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0, 640, 480);
    rect->setBrush(QBrush(Qt::black));
    project_data::instance().gscene->addItem(rect);
    for(std::list<QGraphicsPixmapItem*>::iterator it = items_list->begin(); it != items_list->end(); ++it)
        gscene->addItem(*it);
}


void project_data::update_entity_position(int id, int x, int y) {
    int row;
    for(int i = 0; i < entities_model->rowCount(); ++i)
        if(entities_model->index(i,0).child(e_id,0).data().toInt() == id) {
            row = i;
            break;
        }
    std::list<QGraphicsPixmapItem*>::iterator it = items_list->begin();
    std::advance(it, row);
    (*it)->setPos(x, y);
}


void project_data::update_entity_pixmap(int id, QPixmap *pic) {
    int row;
    for(int i = 0; i < entities_model->rowCount(); ++i)
        if(entities_model->index(i,0).child(e_id,0).data().toInt() == id) {
            row = i;
            break;
        }
    std::list<QGraphicsPixmapItem*>::iterator it = items_list->begin();
    std::advance(it, row);
    (*it)->setPixmap(*pic);
}

void project_data::save_project_file() {
    std::ofstream file((prj_configuration.at(working_dir)+prj_configuration.at(name)+QString("/")+prj_configuration.at(name)+QString(".shmgproj")).toStdString().c_str());
}
