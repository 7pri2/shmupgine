HEADERS += \
    editor.h \
    project_data.h \
    singleton.h \
    new_project.h \
    config_panel.h \
    config_window.h \
    graphics_manager.h \
    attribute_widget.h \
    attributes_container.h \
    entities_container.h \
    properties.h \
    physics.h \
    graphic_renderer.h \
    select_sprite.h \
    destructor.h \
    controls.h \
    select_entity.h \
    script.h \
    script_editor.h

SOURCES += \
    editor.cpp \
    main.cpp \
    project_data.cpp \
    new_project.cpp \
    config_panel.cpp \
    config_window.cpp \
    graphics_manager.cpp \
    attribute_widget.cpp \
    attributes_container.cpp \
    entities_container.cpp \
    properties.cpp \
    physics.cpp \
    graphic_renderer.cpp \
    select_sprite.cpp \
    destructor.cpp \
    controls.cpp \
    select_entity.cpp \
    script.cpp \
    script_editor.cpp

TRANSLATIONS = shmupgine-editor_fr.ts

QT += widgets
