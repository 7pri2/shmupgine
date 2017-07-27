#include <QApplication>
#include <QTranslator>
#include "editor.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTranslator translator;

    translator.load("shmupgine-editor_en");
    app.installTranslator(&translator);

    editor *game_editor= new editor;
    game_editor->show();
    return app.exec();
}
