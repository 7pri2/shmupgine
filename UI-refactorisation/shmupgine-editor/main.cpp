#include <QApplication>
#include "windows_panels.h"
#include "entities_attributes_panel.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    entities_attributes_panel ap;
    ap.show();
    return app.exec();
}
