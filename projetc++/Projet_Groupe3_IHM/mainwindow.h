#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createMenus();         // Crée les menus
    void createSidebar();       // Crée la barre latérale
    void createCentralArea();   // Crée la zone centrale pour les messages
    void applyStyle();          // Applique un style global
    void displayMessage(const QString &message); // Affiche un message

    QWidget *centralWidget;     // Widget central
    QWidget *sidebar;           // Barre latérale
    QLabel *centralLabel;       // Label pour afficher les messages
};

#endif // MAINWINDOW_H
