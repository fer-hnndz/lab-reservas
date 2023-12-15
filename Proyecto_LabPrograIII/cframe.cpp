#include "cframe.h"
#include "ui_cframe.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <SolicianteRepetible.h>
#include <Solicitante.h>
using namespace std;

Cframe::Cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cframe)
{
    ListaReservas list;
    this->reservas = list;

    // TODO: Cargar data el excel y llenar list
    // Llenar reservas dia con info en base a list


    // UI
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


void Cframe::on_PB_Enviar_clicked(){
    QString texto_ClaseRequerida = ui->lineEdit_ClaseRequerida->text();
    QString texto_Correo = ui->lineEdit_Correo->text();
    QString texto_MotivoUso= ui->lineEdit_MotivoUso->text();
    QString texto_NomComp= ui->lineEdit_NomComp->text();
    QString texto_NumCuenta= ui->lineEdit_NumCuenta->text();
    QString texto_Nombres_Cuentas = ui->TE_Nombres_Cuentas->toPlainText();
    QString texto_TE_Equipos = ui->TE_Equipos->toPlainText();

    if(texto_ClaseRequerida.isEmpty()||texto_Correo.isEmpty()||texto_MotivoUso.isEmpty()||texto_NomComp.isEmpty()||texto_NumCuenta.isEmpty()||texto_Nombres_Cuentas.trimmed().isEmpty()||texto_TE_Equipos.trimmed().isEmpty()){
          QMessageBox messageBox;
           messageBox.setIcon(QMessageBox::Critical);
           messageBox.setWindowTitle("Error");
           messageBox.setText("¡Porfavor completar todos los espacios solicitados antes de enviar el formulario!");
           messageBox.exec();
           return;
    }
    // TODO: Limpiar campos y mostrar alerta
    QString opcion = ui->CBX_PerfSol->currentText();

    if(opcion=="Docente"){
        QDate fecha = ui->DE_Fecha->date();
        string lab = ui->CBX_LabSol->currentText().toStdString();
        int indexInicio = ui->CBX_HInicio->currentIndex();
        int indexFinal = ui->CBX_HFinal->currentIndex();

           // TODO: REVISAR QUE ESTE DENTRO DE LAS HORAS POSIBLES
        int cantP = ui->spinBox_CantIntegrantes->value();


        string repetirOpcion = ui->CBX_RepReserv->currentText().toStdString();
        RepetirReserva rep;
        if (repetirOpcion == "Weekly")
            rep = RepetirReserva(Weekly);
        else if (repetirOpcion == "Daily")
            rep = RepetirReserva(Daily);
        else
            rep = RepetirReserva(NoRepeat);

        string nombreCompleto = ui->lineEdit_NomComp->text().toStdString();
        string numCuenta =  ui->lineEdit_NumCuenta->text().toStdString();
        string correo = ui->lineEdit_Correo->text().toStdString();
        string nombresCuentas = ui->TE_Nombres_Cuentas->toPlainText().toStdString();
        string equipoUsar = ui->TE_Equipos->toPlainText().toStdString();

        //SolicitanteRepetible *asol = new SolicitanteRepetible(
                    //)
        SolicitanteRepetible *sol = new SolicitanteRepetible(
                    nombreCompleto,
                    numCuenta,
                    correo,
                    cantP,
                    nombresCuentas,
                    equipoUsar,
                    fecha,
                    indexInicio,
                    indexFinal,
                    rep
         );
        Reserva *newRes = new Reserva(
                    lab,ui->lineEdit_ClaseRequerida->text().toStdString(),
                    ui->lineEdit_MotivoUso->text().toStdString(),
                    dynamic_cast<Solicitante *>(sol)
                    );

        reservas.push_back(newRes);
        QMessageBox::information(nullptr, "Exito", "Reserva agendada correctamente.");

    }else if(opcion=="Administrativo"){
        QDate fecha = ui->DE_Fecha->date();
        string lab = ui->CBX_LabSol->currentText().toStdString();
        int indexInicio = ui->CBX_HInicio->currentIndex();
        int indexFinal = ui->CBX_HFinal->currentIndex();

           // TODO: REVISAR QUE ESTE DENTRO DE LAS HORAS POSIBLES
        int cantP = ui->spinBox_CantIntegrantes->value();


        string repetirOpcion = ui->CBX_RepReserv->currentText().toStdString();
        RepetirReserva rep;
        if (repetirOpcion == "Weekly")
            rep = RepetirReserva(Weekly);
        else if (repetirOpcion == "Daily")
            rep = RepetirReserva(Daily);
        else
            rep = RepetirReserva(NoRepeat);

        string nombreCompleto = ui->lineEdit_NomComp->text().toStdString();
        string numCuenta =  ui->lineEdit_NumCuenta->text().toStdString();
        string correo = ui->lineEdit_Correo->text().toStdString();
        string nombresCuentas = ui->TE_Nombres_Cuentas->toPlainText().toStdString();
        string equipoUsar = ui->TE_Equipos->toPlainText().toStdString();

        //SolicitanteRepetible *asol = new SolicitanteRepetible(
                    //)
        SolicitanteRepetible *sol = new SolicitanteRepetible(
                    nombreCompleto,
                    numCuenta,
                    correo,
                    cantP,
                    nombresCuentas,
                    equipoUsar,
                    fecha,
                    indexInicio,
                    indexFinal,
                    rep
         );
        Reserva *newRes = new Reserva(
                    lab,ui->lineEdit_ClaseRequerida->text().toStdString(),
                    ui->lineEdit_MotivoUso->text().toStdString(),
                    dynamic_cast<Solicitante *>(sol)
                    );

        reservas.push_back(newRes);
        QMessageBox::information(nullptr, "Exito", "Reserva agendada correctamente.");


        ui->lineEdit_ClaseRequerida->clear();
        ui->lineEdit_Correo->clear();
        ui->lineEdit_NomComp->clear();
        ui->lineEdit_NumCuenta->clear();
        ui->TE_Nombres_Cuentas->clear();
        ui->TE_Equipos->clear();
        ui->lineEdit_MotivoUso->clear();

    }else if(opcion=="Educación Continua"){
        QDate fecha = ui->DE_Fecha->date();
        string lab = ui->CBX_LabSol->currentText().toStdString();
        int indexInicio = ui->CBX_HInicio->currentIndex();
        int indexFinal = ui->CBX_HFinal->currentIndex();

           // TODO: REVISAR QUE ESTE DENTRO DE LAS HORAS POSIBLES
        int cantP = ui->spinBox_CantIntegrantes->value();


        string repetirOpcion = ui->CBX_RepReserv->currentText().toStdString();
        RepetirReserva rep;
        if (repetirOpcion == "Weekly")
            rep = RepetirReserva(Weekly);
        else if (repetirOpcion == "Daily")
            rep = RepetirReserva(Daily);
        else
            rep = RepetirReserva(NoRepeat);

        string nombreCompleto = ui->lineEdit_NomComp->text().toStdString();
        string numCuenta =  ui->lineEdit_NumCuenta->text().toStdString();
        string correo = ui->lineEdit_Correo->text().toStdString();
        string nombresCuentas = ui->TE_Nombres_Cuentas->toPlainText().toStdString();
        string equipoUsar = ui->TE_Equipos->toPlainText().toStdString();

        //SolicitanteRepetible *asol = new SolicitanteRepetible(
                    //)
        SolicitanteRepetible *sol = new SolicitanteRepetible(
                    nombreCompleto,
                    numCuenta,
                    correo,
                    cantP,
                    nombresCuentas,
                    equipoUsar,
                    fecha,
                    indexInicio,
                    indexFinal,
                    rep
         );
        Reserva *newRes = new Reserva(
                    lab,ui->lineEdit_ClaseRequerida->text().toStdString(),
                    ui->lineEdit_MotivoUso->text().toStdString(),
                    dynamic_cast<Solicitante *>(sol)
                    );

        reservas.push_back(newRes);
        QMessageBox::information(nullptr, "Exito", "Reserva agendada correctamente.");

        ui->lineEdit_ClaseRequerida->clear();
        ui->lineEdit_Correo->clear();
        ui->lineEdit_NomComp->clear();
        ui->lineEdit_NumCuenta->clear();
        ui->TE_Nombres_Cuentas->clear();
        ui->TE_Equipos->clear();
        ui->lineEdit_MotivoUso->clear();
    }else if(opcion=="Alumno"){
        QDate fecha = ui->DE_Fecha->date();
        string lab = ui->CBX_LabSol->currentText().toStdString();
        int indexInicio = ui->CBX_HInicio->currentIndex();
        int indexFinal = ui->CBX_HFinal->currentIndex();

           // TODO: REVISAR QUE ESTE DENTRO DE LAS HORAS POSIBLES
        int cantP = ui->spinBox_CantIntegrantes->value();
        string nombreCompleto = ui->lineEdit_NomComp->text().toStdString();
        string numCuenta =  ui->lineEdit_NumCuenta->text().toStdString();
        string correo = ui->lineEdit_Correo->text().toStdString();
        string nombresCuentas = ui->TE_Nombres_Cuentas->toPlainText().toStdString();
        string equipoUsar = ui->TE_Equipos->toPlainText().toStdString();

        //SolicitanteRepetible *asol = new SolicitanteRepetible(
                    //)
        Solicitante *sol = new Solicitante(
                    nombreCompleto,
                    numCuenta,
                    correo,
                    cantP,
                    nombresCuentas,
                    equipoUsar,
                    fecha,
                    indexInicio,
                    indexFinal
         );
        Reserva *newRes = new Reserva(
                    lab,ui->lineEdit_ClaseRequerida->text().toStdString(),
                    ui->lineEdit_MotivoUso->text().toStdString(),
                    dynamic_cast<Solicitante *>(sol)
                    );

        reservas.push_back(newRes);
        QMessageBox::information(nullptr, "Exito", "Reserva agendada correctamente.");
        ui->lineEdit_ClaseRequerida->clear();
        ui->lineEdit_Correo->clear();
        ui->lineEdit_NomComp->clear();
        ui->lineEdit_NumCuenta->clear();
        ui->TE_Nombres_Cuentas->clear();
        ui->TE_Equipos->clear();
        ui->lineEdit_MotivoUso->clear();
    }
    ui->lineEdit_ClaseRequerida->clear();
    ui->lineEdit_Correo->clear();
    ui->lineEdit_NomComp->clear();
    ui->lineEdit_NumCuenta->clear();
    ui->TE_Nombres_Cuentas->clear();
    ui->TE_Equipos->clear();
    ui->lineEdit_MotivoUso->clear();
}

