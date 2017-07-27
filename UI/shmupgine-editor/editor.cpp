#include "editor.h"
#include <QGraphicsPixmapItem>

editor::editor(QWidget *parent) : QMainWindow(parent) {
    sa_scroll_attributes= new QScrollArea(this);
    /// Menu Bar
    mb_menuBar      = new QMenuBar(this);
    // File
    m_file  = new QMenu(tr("File"), this);
    a_new   = new QAction(tr("&New project"), this);
    a_open  = new QAction(tr("&Open project"), this);
    a_save  = new QAction(tr("&Save project"), this);
    a_close = new QAction(tr("&Close"), this);
    // Config
    m_config_window = new QMenu(tr("Config"), this);
    a_project       = new QAction(tr("&Project"), this);
    a_makefile      = new QAction(tr("&Makefile"), this);
    a_graphics      = new QAction(tr("&Graphics manager"), this);
    // Build
    m_build         = new QMenu(tr("Build"), this);
    a_run           = new QAction(tr("&Run"), this);
    a_build         = new QAction(tr("&Build"), this);
    a_build_and_run = new QAction(tr("Build a&nd run"), this);

    /// Attribute menu
    m_choose_attribute  = new QMenu(this);
    a_physics           = new QAction(tr("&physics"), this);
    a_graphic_renderer  = new QAction(tr("&graphic renderer"), this);
    a_destructor        = new QAction(tr("&destructor"), this);
    a_controls          = new QAction(tr("&controls"), this);
    a_script            = new QAction(tr("&script"), this);

    win_new_project     = new new_project();
    win_config          = new config_window();

    panel_attributes    = new attributes_container(this);
    panel_entities      = new entities_container(this);
    panel_graphic_view  = new QGraphicsView(project_data::instance().gscene, this);

    lay_mainlayout  = new QHBoxLayout(this);
    wg_centerWidget = new QWidget(this);
    sp_splitter     = new QSplitter(this);

    panel_entities->setMinimumWidth(160);
    panel_entities->setMaximumWidth(300);

    sa_scroll_attributes->setWidget(panel_attributes);
    sa_scroll_attributes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sa_scroll_attributes->setWidgetResizable(true);
    sa_scroll_attributes->setMinimumWidth(250);
    sa_scroll_attributes->setMaximumWidth(350);

    setMinimumWidth(800);
    setMinimumHeight(400);

    setup_layouts();
    setup_attribute_menu();
    setup_window_menu();
    create_clear_gview();

    connect(m_config_window, SIGNAL(triggered(QAction*)), this, SLOT(manage_config_menu_choice(QAction*)));
    connect(panel_entities->btn_new, SIGNAL(clicked()), this, SLOT(add_entity()));
    connect(panel_entities->lv_list, SIGNAL(clicked(QModelIndex)), panel_attributes, SLOT(update_what_is_visible()));
    connect(panel_attributes->btn_new, SIGNAL(clicked()), this, SLOT(request_attribute_menu()));
    connect(m_choose_attribute, SIGNAL(triggered(QAction*)), this, SLOT(manage_attribute_menu_choice(QAction*)));
    connect(m_file, SIGNAL(triggered(QAction*)), this, SLOT(manage_file_menu_choice(QAction*)));
    connect(m_build, SIGNAL(triggered(QAction*)), this, SLOT(manage_build_menu_choice(QAction*)));
}

editor::~editor() {
    delete win_config;
    delete win_new_project;
}

void editor::setup_layouts() {
    sp_splitter->addWidget(panel_graphic_view);
    sp_splitter->addWidget(panel_entities);
    sp_splitter->addWidget(sa_scroll_attributes);
    lay_mainlayout->addWidget(sp_splitter);
    wg_centerWidget->setLayout(lay_mainlayout);
    setCentralWidget(wg_centerWidget);
}

void editor::add_entity() {
    project_data::instance().entity_max_id += 1;
    int id = project_data::instance().entity_max_id;
    QStandardItem* item = new QStandardItem(QString(QObject::tr("entity"))+QString::number(id));
    item->appendRow(new QStandardItem(QString::number(id)));
    project_data::instance().register_entity(item);
    create_attribute(id, new properties());
}

void editor::setup_attribute_menu() {
    m_choose_attribute->addAction(a_physics);
    m_choose_attribute->addAction(a_graphic_renderer);
    m_choose_attribute->addAction(a_destructor);
    m_choose_attribute->addAction(a_controls);
    m_choose_attribute->addAction(a_script);
}

void editor::request_attribute_menu() {
    int id = project_data::instance().current_entity_id;
    if(id) {
        m_choose_attribute->popup(QCursor::pos());
    }
}

void editor::manage_attribute_menu_choice(QAction *a) {
    if(a == a_physics)
        create_attribute(new physics);
    else if(a == a_graphic_renderer)
        create_attribute(new graphic_renderer);
    else if(a == a_destructor)
        create_attribute(new destructor);
    else if(a == a_controls)
        create_attribute(new controls);
    else if(a == a_script)
        create_attribute(new script);
}

void editor::manage_build_menu_choice(QAction *a) {
    if(a == a_build)
        build();
    else if(a == a_run)
        run();
    else if(a == a_build_and_run)
        build_and_run();
}

void editor::setup_window_menu() {
    setMenuBar(mb_menuBar);

    mb_menuBar->addMenu(m_file);
    m_file->addAction(a_new);
    m_file->addAction(a_open);
    m_file->addSeparator();
    m_file->addAction(a_save);
    m_file->addSeparator();
    m_file->addAction(a_close);

    mb_menuBar->addMenu(m_config_window);
    m_config_window->addAction(a_project);
    m_config_window->addAction(a_makefile);
    m_config_window->addAction(a_graphics);

    mb_menuBar->addMenu(m_build);
    m_build->addAction(a_run);
    m_build->addAction(a_build);
    m_build->addAction(a_build_and_run);
}

void editor::manage_config_menu_choice(QAction *a) {
    if(a == a_project)
        win_config->open_tab(config);
    else if(a == a_makefile)
        win_config->open_tab(makefile);
    else if(a == a_graphics)
        win_config->open_tab(gmanager);
}

void editor::manage_file_menu_choice(QAction *a) {
    if(a == a_new)
        win_new_project->show();
    else if(a == a_open)    // temp tests
        create_main_file();
    else if(a == a_save)
        ;
    else if(a == a_close)
        ;
}

void editor::create_attribute(attribute_widget *attr) {
    attr->setParent(panel_attributes);
    attr->setId_parent(project_data::instance().current_entity_id);
    panel_attributes->add_attribute(attr);
    project_data::instance().add_attribute(attr);
    project_data::instance().update_what_is_visible();
}

void editor::create_attribute(int id, attribute_widget *attr) {
    attr->setParent(panel_attributes);
    attr->setId_parent(id);
    panel_attributes->add_attribute(attr);
    project_data::instance().add_attribute(attr);
    project_data::instance().update_what_is_visible();
}

void editor::create_main_file() {
    QString content = QString("#include \"") + project_data::instance().prj_configuration.at(engine) + QString("shmupgine.h\"\n\n") +
            QString("int main(int argc, char* argv[]) {\n") +
            QString("\tshmupgine::init();\n") +
            project_data::instance().get_pictures_code() +
            QString("\tscene sc1;\n") +
            project_data::instance().get_attributes_code() +
            project_data::instance().get_entities_code("sc1") +
            QString("\tsc1.run();\n") +
            QString("\tshmupgine::close();\n") +
            QString("\treturn 0;\n") +
            QString("}");
    QString filename = project_data::instance().prj_configuration.at(working_dir)+project_data::instance().prj_configuration.at(name)+QString(".cpp");
    std::ofstream main(filename.toStdString().c_str());
    main << content.toStdString();
    main.close();
}

void editor::run() {
   QProcess::startDetached(project_data::instance().prj_configuration.at(working_dir) + project_data::instance().prj_configuration.at(name));
}

void editor::build() {
    create_main_file();
    create_makefile();
    QProcess::startDetached(project_data::instance().prj_configuration.at(make)+QString(" -f ")+project_data::instance().prj_configuration.at(working_dir)+QString("Makefile"));
}

void editor::build_and_run() {
    build();
    run();
}

void editor::create_makefile() {
    QString filename = project_data::instance().prj_configuration.at(working_dir)+QString("/Makefile");
    std::ofstream makefile(filename.toStdString().c_str());
    makefile << project_data::instance().generate_makefile().toStdString();
}

void editor::create_clear_gview() {
    QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0, 640, 480);
    rect->setBrush(QBrush(Qt::black));
    project_data::instance().gscene->addItem(rect);
}
