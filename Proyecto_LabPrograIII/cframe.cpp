#include "cframe.h"
#include "ui_cframe.h"
#include <QPixmap>
#include <iostream>
using namespace std;

Cframe::Cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cframe)
{
    //para que tenga un tamaño fijo
    setFixedSize(700, 900);
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
   //Fond del PushButton
   QString style4 = "QPushButton#PB_Enviar{ color: black; }";
   ui->PB_Enviar->setStyleSheet(style4);
   //ComboBox fondos
   QString style5 = "QComboBox#CBX_HInicio { color: black; }";
   ui->CBX_HInicio->setStyleSheet(style5);
   QString style6 = "QComboBox#CBX_HFinal { color: black; }";
   ui->CBX_HFinal->setStyleSheet(style6);

}

Cframe::~Cframe(){

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

