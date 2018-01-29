#include <QApplication>
#include "windows_panels.h"
#include "model_entity_block.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    model_entity_block ap;
    ap.show();
    return app.exec();
}
