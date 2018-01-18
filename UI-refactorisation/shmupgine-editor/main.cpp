#include <QApplication>
#include "windows_panels.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    w_editor::Instance()->show();
    return app.exec();
}
