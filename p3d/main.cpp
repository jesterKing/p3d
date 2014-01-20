#include "QmlAppViewer.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    QmlAppViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/p3d/main.qml"));
    viewer.window->setClearBeforeRendering(false);
    viewer.show();

    return app.exec();
}
