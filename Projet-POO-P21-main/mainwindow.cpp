#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Q3DSurface>
#include <QSurfaceDataProxy>
#include <QSurface3DSeries>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "include/cst.h"
#include "include/addition.h"
#include "include/soustraction.h"
#include "include/multiplication.h"
#include "include/division.h"
#include "include/carre.h"
#include "include/inverse.h"
#include "include/log_neperien.h"
#include "include/oppose.h"
#include "include/racine_carre.h"
#include "include/valeur_absolue.h"
#include "include/variable.h"
#include "include/sauvegarde.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Calculer_clicked()
{
    QStringList token =  ui->lineEdit->text().split(' ');
    expression* expr = stringtoexpression(token);

    float resultat = expr->calculer();
    ui->label->setText("= " + QString::number(resultat));
}


void MainWindow::on_pushButton_Simplifier_clicked()
{
    QStringList token =  ui->lineEdit->text().split(' ');
    expression* expr = stringtoexpression(token);
    expression* exprsimple = expr->simplifier();
    delete expr;
    std::stringstream buffer;
    exprsimple->afficher_pinv(buffer);
    ui->lineEdit->setText(QString::fromStdString(buffer.str()));
}

expression* MainWindow::stringtoexpression(QStringList token ){
    std::string Vs_entre;
    std::vector<expression*> Fvect_expr_liste;
    int Vi_liste_index;
    int Vb_exit = 0;
    int i = 0;
    cst* Vcst_val;
    while(i < token.size()){
        Vs_entre = token.at(i).toStdString();
        i++;
        Vi_liste_index = Fvect_expr_liste.size() -1;
        if ((Vs_entre[0] - '0' <= 9 && Vs_entre[0] - '0' >= 0) || Vs_entre[0] == '-'){
            Vcst_val = new cst();
            Vcst_val->Setvaleur(stof(Vs_entre));
            Fvect_expr_liste.push_back(Vcst_val);
        }else
        if (Vs_entre == "+"){
            Fvect_expr_liste.push_back(new addition(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "*"){
            Fvect_expr_liste.push_back(new multiplication(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "/"){
            Fvect_expr_liste.push_back(new division(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "inv"){
            Fvect_expr_liste.push_back(new inverse(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "opp"){
            Fvect_expr_liste.push_back(new oppose(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "abs"){
            Fvect_expr_liste.push_back(new valeur_absolue(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "ln"){
            Fvect_expr_liste.push_back(new log_neperien(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "^"){
            Fvect_expr_liste.push_back(new carre(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "sqrt"){
            Fvect_expr_liste.push_back(new racine_carre(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if(Vs_entre == "p"){
            Vb_exit = 1;
        }else
        if(Vs_entre == "x" || Vs_entre == "y"){
            Fvect_expr_liste.push_back(new variable(Vs_entre));
        }
    }

    expression* expr = Fvect_expr_liste.back();
    return expr;
}

void MainWindow::on_pushButton_Save_clicked()
{
    QStringList token =  ui->lineEdit->text().split(' ');
    expression* expr = stringtoexpression(token);
    SauvegardeExpression saved(expr);
    saved.sauvegarder(ui->lineEdit_2->text().toStdString());
}


void MainWindow::on_pushButton_Load_clicked()
{
    expression* expr;
    SauvegardeExpression load(nullptr);
    load.charger(ui->lineEdit_2->text().toStdString());
    expr = load.get_expression();
    std::stringstream buffer;
    expr->afficher_pinv(buffer);
    ui->lineEdit->setText(QString::fromStdString(buffer.str()));
}


void MainWindow::on_pushButton_Graph3D_clicked()
{
    table_symboles ts;
    QStringList token =  ui->lineEdit->text().split(' ');
    expression* expr = stringtoexpression(token);
    QtDataVisualization::Q3DSurface *surface = new QtDataVisualization::Q3DSurface();
    surface->setFlags(surface->flags() ^ Qt::FramelessWindowHint);
    QtDataVisualization::QSurfaceDataArray *data = new QtDataVisualization::QSurfaceDataArray;
    QtDataVisualization::QSurfaceDataRow *dataRow;
    float pas = ui->lineEdit_Pas->text().toFloat();
    float Xmin = ui->lineEdit_MinX->text().toFloat();
    float Xmax = ui->lineEdit_MaxX->text().toFloat();
    float Ymin = ui->lineEdit_MinY->text().toFloat();
    float Ymax = ui->lineEdit_MaxY->text().toFloat();
    float X = Xmin;
    float Y = Ymin;
    float Z = 0;
    int xSteps = (Xmax - Xmin) / pas;
    int ySteps = (Ymax - Ymin) / pas;
    float Zmin = 0;
    float Zmax = 0;
    for (int i = 0; i < xSteps+1; i++) {
        X = Xmin + i * pas;
        ts.ajouter_variable("x",X);
        dataRow = new QtDataVisualization::QSurfaceDataRow;
        for (int ii = 0; ii < ySteps+1; ii++) {
            Y = Ymin + ii * pas;
            ts.ajouter_variable("y",Y);
            Z = expr->evaluer(ts);
            if (Zmin == 0 && Zmax == 0){
                Zmin = Z;
                Zmax = Z;
            }else if(Z < Zmin){
                Zmin = Z;
            }else if(Z > Zmax){
                Zmax = Z;
            }
            *dataRow << QVector3D(X,Z,Y);
        }
        *data << dataRow;
    }
    QtDataVisualization::QSurface3DSeries *series = new QtDataVisualization::QSurface3DSeries;
    series->dataProxy()->resetArray(data);
    surface->axisX()->setRange(Xmin-pas,Xmax+pas);
    surface->axisY()->setRange(Zmin-pas,Zmax+pas);
    surface->axisZ()->setRange(Ymin-pas,Ymax+pas);
    surface->axisX()->setTitle("X");
    surface->axisY()->setTitle("Z");
    surface->axisZ()->setTitle("Y");
    surface->axisX()->setTitleVisible(true);
    surface->axisY()->setTitleVisible(true);
    surface->axisZ()->setTitleVisible(true);
    surface->resize(900,600);
    surface->setTitle("3d Graph");
    surface->addSeries(series);
    surface->setHorizontalAspectRatio(1.0);
    surface->setAspectRatio(1.0);
    surface->show();
}

