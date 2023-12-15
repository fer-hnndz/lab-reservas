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
   ui->DE_Fecha->setMinimumDate(QDate::currentDate());
   ui->DE_Fecha->setMaximumDate(QDate::currentDate().addYears(2));

}

Cframe::~Cframe(){

    delete ui;
}

/*
 * ===========================================
 * Codigo de Horas Dia
 * ==========================================
 */

bool Cframe::puedeReservar(int horaInicio, int horaFinal, QDate fecha, string lab) {
    ReservaDia *res = nullptr;

    // Revisar si existe alguna reservacion para ese dia
    for (int i = 0; i < reservasDia.size(); i++) {
        if (reservasDia[i].fecha == fecha && reservasDia[i].lab == lab) {
            cout << "[puedeReservar] Se encontro res para lab:" << lab << " en " << fecha.toString().toStdString() <<
                    "\n";
            res = &reservasDia[i];
            break;
        }
    }

    // No existe ninguna reservacion para ese dia, por ende, tiene todo el dia libre.
    if (res == nullptr) {
        cout << res;
        cout << "[puedeReservar] No existe reservacion para ese dia\n";
        return true;
    }

    // Verificaciones si se puede reservar

    if (res->horas[horaInicio]->esReservado()) {
        if (res->horas[horaInicio]->esInicio()) {
            cout << "La hora de inicio ya es un inicio.\n";
            return false;
        }
        //if (res->horas[horaInicio]->esFinal()) return true;

        // Si no es ni inicio y tampoco final (esta en medio de otro lab)
        if ( !(res->horas[horaInicio]->esInicio()) && !(res->horas[horaInicio]->esFinal()) ) {
            cout << "[puedeReservar] Hora de inicio se encuentra en medio de un lab\n";
            return false;}
    }

    // Recorrer de inicio a final para ver que todas las horas esten libres
    for (int i = horaInicio + 1; i < horaFinal; i++) {
        if (res->horas[i]->esReservado()) {
            cout << "[puedeReservar] Se encontro un reservado en medio del recorrido\n";
            return false;
        }
    }


    if (res->horas[horaFinal]->esInicio() || !(res->horas[horaFinal]->esReservado()) ) return true;
    else {
        cout << "La hora final no es inicio o estaba reservada\n";
        return false;
    }
}

void Cframe::agregarReservaDia(QDate fecha, string lab, int horaInicio, int horaFinal) {
    // Recorrer el array en busca de las reservas (si existen) para ese dia

    ReservaDia *res = nullptr;

    // Revisar si existe alguna reservacion para ese dia
    for (int i = 0; i < reservasDia.size(); i++) {
        if (reservasDia[i].fecha == fecha && reservasDia[i].lab == lab) {
            res = &reservasDia[i];
            break;
        }
    }

    bool noExistia = false;

    // No existe ninguna reservacion para ese dia, crear
    if (res == nullptr) {
        cout << "[agregarReservaDia()] Agregando nuevas reservas para el lab: " << lab << " dia " << fecha.toString().toStdString() << "\n";
        noExistia = true;
        res = new ReservaDia(fecha, lab, this->reservas.head);
    }


    // Recorrer desde el inicio hasta el final actualizando valores de horas

    res->horas[horaInicio]->setInicio(true);

    // 0 < 3
    // 0 -> inicio
    // 1 - > reservado
    // 2 -> reservado
    // 3 -> final

    for (int i = horaInicio + 1; i < horaFinal; i++) {
        res->horas[i]->setReservado(true);
    }
    res->horas[horaFinal]->setFinal(true);
    res->imprimirDia();

    if (noExistia) {
        cout << "[agregarReservaDia] Agregando al array de reservas dia porque no existia\n";
        reservasDia.push_back(*res);
    }
    cout << "Size de reservas Dia: " << reservasDia.size() << "\n";


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


    // Comprobacion campos llenos
    if(texto_ClaseRequerida.isEmpty()||texto_Correo.isEmpty()||texto_MotivoUso.isEmpty()||texto_NomComp.isEmpty()||texto_NumCuenta.isEmpty()||texto_Nombres_Cuentas.trimmed().isEmpty()||texto_TE_Equipos.trimmed().isEmpty()){
          QMessageBox messageBox;
           messageBox.setIcon(QMessageBox::Critical);
           messageBox.setWindowTitle("Error");
           messageBox.setText("¡Porfavor completar todos los espacios solicitados antes de enviar el formulario!");
           messageBox.exec();
           return;
    }
    QString opcion = ui->CBX_PerfSol->currentText();

    if(opcion=="Docente"){
        QDate fecha = ui->DE_Fecha->date();
        string lab = ui->CBX_LabSol->currentText().toStdString();
        int indexInicio = ui->CBX_HInicio->currentIndex();
        int indexFinal = ui->CBX_HFinal->currentIndex() + 2;

        if ( !puedeReservar(indexInicio, indexFinal, fecha, lab) ) {
             QMessageBox messageBox;
             messageBox.setIcon(QMessageBox::Critical);
             messageBox.setWindowTitle("Error");
             messageBox.setText("¡Su laboratorio choca con otro laboratorio previamente reservado!");
             messageBox.exec();
            return;
        }
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
        agregarReservaDia(fecha, lab, indexInicio, indexFinal);
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

