#include "cframe.h"
#include "ui_cframe.h"
#include <QPixmap>
#include <iostream>
using namespace std;

Cframe::Cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cframe)
{
    ui->setupUi(this);
   //Fond del Combox
    QString style = "QComboBox#CBX_LabSol { color: black; }";
   ui->CBX_LabSol->setStyleSheet(style);
   //Fond del Combox
   QString style2 = "QComboBox#CBX_PerfSol { color: black; }";
   ui->CBX_PerfSol->setStyleSheet(style2);
      //Fond del Combox
   QString style3 = "QComboBox#CBX_RepReserv{ color: black; }";
   ui->CBX_RepReserv->setStyleSheet(style3);
   QString style4 = "QPushButton#PB_Enviar{ color: black; }";
   ui->PB_Enviar->setStyleSheet(style4);

}

Cframe::~Cframe()
{

    delete ui;
}


void Cframe::on_pushButton_clicked(){


}


void Cframe::on_CBX_PerfSol_activated(const QString &arg1){

    if (arg1 == "Alumno") {
       ui->CBX_RepReserv->setVisible(false);
       ui->label_RepRerserv->setVisible(false);
    }else{
        ui->CBX_RepReserv->setVisible(true);
        ui->label_RepRerserv->setVisible(true);

    }
}

