#include "mainwindow.h"

//using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    Q3DSurface surface;
    surface.setFlags(surface.flags() ^ Qt::FramelessWindowHint);
    QSurfaceDataArray *data = new QSurfaceDataArray;
    QSurfaceDataRow *dataRow1 = new QSurfaceDataRow;
    QSurfaceDataRow *dataRow2 = new QSurfaceDataRow;

    *dataRow1 << QVector3D(0.0f, 0.1f, 0.0f) << QVector3D(1.0f, 0.5f, 0.0f);  //0.5f, 0.5f
    *dataRow2 << QVector3D(0.0f, 1.8f, 0.0f) << QVector3D(1.0f, 1.2f, 0.0f);
    *data << dataRow1 << dataRow2;

    QSurface3DSeries *series = new QSurface3DSeries;
    series->dataProxy()->resetArray(data);
    surface.addSeries(series);
    surface.show();
    window.resize(200, 120);

    QPushButton quit("Quit", &window);

    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(10, 30, 180, 40);

    QObject::connect(&quit, SIGNAL(clicked()), &a, SLOT(quit()));// Définit les parametre du bouton quit avec la liaison par le &
                // envoi un signal             app quitté
    MainWindow w;
    window.show(); //permet d'afficher la fenetre de quit
    return a.exec();
}
