#include <QApplication>
#include "mainlayout.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainLayout layout;

    layout.show();
    return app.exec();
}
