#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Expression Manager");
    resize(1000, 600);

    createMenus();       // Crée le menu
    createSidebar();     // Crée la barre latérale
    applyStyle();        // Applique un style moderne
}

MainWindow::~MainWindow() {}

void MainWindow::createMenus() {
    // Menu Fichier
    QMenu *fileMenu = menuBar()->addMenu(tr("Fichier"));
    QAction *saveAction = fileMenu->addAction(tr("Sauvegarder"));
    QAction *loadAction = fileMenu->addAction(tr("Charger"));

    connect(saveAction, &QAction::triggered, []() {
        QMessageBox::information(nullptr, "Info", "Sauvegarde déclenchée.");
    });
    connect(loadAction, &QAction::triggered, []() {
        QMessageBox::information(nullptr, "Info", "Chargement déclenché.");
    });

    // Menu Edition
    QMenu *editMenu = menuBar()->addMenu(tr("Edition"));
    editMenu->addAction(tr("Saisie de l'expression"));
    editMenu->addAction(tr("Affichage notation classique"));
    editMenu->addAction(tr("Affichage notation P.I."));
}

void MainWindow::createSidebar() {
    // Crée la barre latérale
    sidebar = new QWidget(this);
    sidebar->setFixedWidth(200);
    sidebar->setStyleSheet("background-color: #2c3e50;");

    // Layout principal de la barre latérale
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setContentsMargins(0, 0, 0, 0); // Pas de marges
    sidebarLayout->setSpacing(10);                // Espace entre les widgets

    // Boutons
    QPushButton *btnHome = new QPushButton("Accueil");
    QPushButton *btnGraph2D = new QPushButton("Graphique 2D");
    QPushButton *btnGraph3D = new QPushButton("Graphique 3D");
    QPushButton *btnSimplify = new QPushButton("Simplifier");

    // Connect each button to display a message
    connect(btnHome, &QPushButton::clicked, this, [this](){ displayMessage("Vous êtes dans la partie Accueil"); });
    connect(btnGraph2D, &QPushButton::clicked, this, [this](){ displayMessage("Vous êtes dans la partie Graphique 2D"); });
    connect(btnGraph3D, &QPushButton::clicked, this, [this](){ displayMessage("Vous êtes dans la partie Graphique 3D"); });
    connect(btnSimplify, &QPushButton::clicked, this, [this](){ displayMessage("Vous êtes dans la partie Simplification"); });
// changer la fonction bouton par un bouton affiche fonction
    // Style des boutons
    QString buttonStyle = R"(
        QPushButton {
            color: white;
            font-size: 16px;
            background-color: #34495e;
            border-radius: 8px;
            padding: 10px;
            margin: 0 20px;
        }
        QPushButton:hover {
            background-color: #3b5998;
        }
    )";
    btnHome->setStyleSheet(buttonStyle);
    btnGraph2D->setStyleSheet(buttonStyle);
    btnGraph3D->setStyleSheet(buttonStyle);
    btnSimplify->setStyleSheet(buttonStyle);

    // Ajoute des espaces extensibles pour centrer les boutons
    sidebarLayout->addStretch();         // Espace extensible avant
    sidebarLayout->addWidget(btnHome, 0, Qt::AlignCenter);
    sidebarLayout->addWidget(btnGraph2D, 0, Qt::AlignCenter);
    sidebarLayout->addWidget(btnGraph3D, 0, Qt::AlignCenter);
    sidebarLayout->addWidget(btnSimplify, 0, Qt::AlignCenter);
    sidebarLayout->addStretch();         // Espace extensible après

    // Widget central (placeholder) pour afficher les messages
    centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(centralWidget);

    // Création du QLabel central pour afficher les messages
    centralLabel = new QLabel("Bienvenue dans Expression Manager", centralWidget);
    centralLabel->setAlignment(Qt::AlignCenter);
    centralLabel->setStyleSheet("font-size: 18px; color: #34495e; padding: 20px;");

    // Ajoute le QLabel à la disposition
    centralLayout->addWidget(centralLabel);
    centralWidget->setLayout(centralLayout);

    // Disposition principale
    QWidget *mainWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->addWidget(sidebar);       // Ajoute la barre latérale
    mainLayout->addWidget(centralWidget); // Ajoute le contenu principal
    mainLayout->setContentsMargins(0, 0, 0, 0); // Pas de marges

    setCentralWidget(mainWidget);
}

void MainWindow::applyStyle() {
    // Applique un style global moderne
    setStyleSheet(
        "QMainWindow { background-color: #ecf0f1; } "
        "QMenuBar { background-color: #2c3e50; color: white; } "
        "QMenuBar::item { background-color: #2c3e50; color: white; padding: 5px 15px; } "
        "QMenuBar::item:selected { background-color: #34495e; } "
        "QMenu { background-color: #34495e; color: white; } "
        "QMenu::item:selected { background-color: #3b5998; }"
        );
}

void MainWindow::displayMessage(const QString &message) {
    // Mettez à jour le texte de centralLabel
    centralLabel->setText(message);
}
