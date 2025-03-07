#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/expression.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Calculer_clicked();

    void on_pushButton_Simplifier_clicked();
    expression* stringtoexpression (QStringList token);
    void on_pushButton_Save_clicked();

    void on_pushButton_Load_clicked();

    void on_pushButton_Graph3D_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
