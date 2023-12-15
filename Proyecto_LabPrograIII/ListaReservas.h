#ifndef LISTARESERVAS_H
#define LISTARESERVAS_H

#include "Reserva.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::cout;
/*
 * Esta clase es una lista anidada que guarda todas las reservas cargadas del archivo
 */
class Cframe;
class ListaReservas {
    friend Cframe;
private:
    Reserva *head;

public:
    ListaReservas() {
        // TODO: Cargar datos desde el archivo
        head = nullptr;
        cout << "Instantiated\n";

        ifstream file("reservas.xls", ifstream::in);

        if (!file.is_open()) {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
            return;
        }

         string horasStr[11] = {"6:40", "8:10", "9:55", "11:15", "12:35", "13:20", "14:40", "16:00", "17:20", "18:40", "20:00"};


        // Lectura y procesamiento del archivo
        std::string line;
        std::getline(file, line); // Salta la línea del encabezado si es aplicable

        // Cargar datos a archivo
        while (std::getline(file, line)) {
            std::istringstream ss(line);

            // Lee los valores desde el archivo para crear objetos Solicitante
            string labSolicitado, clase, motivo, perfilText, repetirText, nombreCompleto, cuenta, correo, nombreCuentas, equipos, fechaReservacionStr, horaInicioStr, horaFinalStr, cantidadPersonasStr;
            int cantidadPersonas, horaInicio, horaFinal;
            std::getline(ss, labSolicitado, '\t');
            std::getline(ss, clase, '\t');
            std::getline(ss, motivo, '\t');
            std::getline(ss, perfilText, '\t');
            std::getline(ss, repetirText, '\t');
            std::getline(ss, nombreCompleto, '\t');
            std::getline(ss, cuenta, '\t');
            std::getline(ss, correo, '\t');
            std::getline(ss, cantidadPersonasStr, '\t');
            cantidadPersonas = std::stoi(cantidadPersonasStr);
            std::getline(ss, nombreCuentas, '\t');
            std::getline(ss, equipos, '\t');
            std::getline(ss, fechaReservacionStr, '\t');
            std::getline(ss, horaInicioStr, '\t');
            std::getline(ss, horaFinalStr);

            // Solo para probar si se guardan bien los datos
            cout << labSolicitado <<std::endl;
            cout << clase << std::endl;
            cout << motivo << std::endl;
            cout << perfilText << std::endl;
            cout << repetirText << std::endl;
            cout << nombreCompleto << std::endl;
            cout << cuenta << std::endl;
            cout << correo << std::endl;
            cout << cantidadPersonas << "\n";
            cout << nombreCuentas << std::endl;
            cout << equipos << std::endl;
            cout << "==================\n";

            // Convierte las cadenas a los tipos de datos correspondientes
            QDate fechaReservacion = QDate::fromString(QString::fromStdString(fechaReservacionStr));
            cout << fechaReservacion.toString().toStdString() << "\n";
            cout << horaInicioStr << "\n"; // IMPRIME
            cout << fechaReservacion.toString().toStdString() << "\n";
            cout << "Transofmrando hora...\n";
            for (int iter = 0; iter < 11; iter++) {
                if (horasStr[iter] == horaInicioStr) {
                    horaInicio = iter;
                }
            }

            for (int iter = 0; iter < 11; iter++) {
                if (horasStr[iter] == horaFinalStr) {
                    horaFinal = iter;
                }
            }

            cout << horaInicioStr << "\n";
            cout << horaFinalStr << "\n";
            cout << horaInicio << "\n";
            cout << horaFinal << "\n";

            cout << "TERMINADO IMPRIMIR DATA\n";

            // Crea un objeto Solicitante con los datos leídos
            Solicitante *solicitante = new Solicitante(nombreCompleto, cuenta, correo, cantidadPersonas, nombreCuentas, equipos, fechaReservacion, horaInicio, horaFinal);

            // Crea un objeto Reserva con el objeto Solicitante
            Reserva *reserva = new Reserva(labSolicitado, clase, motivo, solicitante, perfilText);

            // Agrega la reserva a la lista ListaReservas
            push_back(reserva);
        }
        file.close();

    }


    ~ListaReservas() {
        ofstream file("reservas.xls", ofstream::out); // No ponerle app ya que vamos a volver a escribir toda la lista, por lo cual nada se va a duplicar
        cout << "Destruyendo Lista...\n";

        Reserva *resActual = head;
        Reserva *tempRes = nullptr;

        int nodosRecorridos = 0;
        cout << "[~ListasReservas()] Intentando eliminar todos los nodos de la lista...\n";

        // Formato de Excel
        file << "Lab Solicitado\tClase para la que requiere laboratorio\tMotivo de Reserva\tPerfil de Solicitante\tRepetir Reservacion\tNombre Completo\tNumero de Cuenta\tCorreo\tCantidad de Integrantes\tNombres y Numeros de Cuenta de Integrantes\tEquipo a utilzarse\tFecha de Reserva\tHora Inicio\tHora Final\n";


        string horas[11] = {"6:40", "8:10", "9:55", "11:15", "12:35", "13:20", "14:40", "16:00", "17:20", "18:40", "20:00"};
        while (resActual != nullptr) {
            // Guardar en archivo

            // TODO: GUARDAR EL NOMBRE DEL PERFIL EN DONDE ESTA LA DOBLE COMA
            Solicitante *sol = resActual->perfil;
            file << resActual->labSolicitado << "\t" << resActual->clase << "\t" << resActual->motivo << "\t" << resActual->perfilText << "\t" << resActual->repetirText << "\t" <<sol->nombreCompleto << "\t" << sol->cuenta << "\t" << sol->correo << "\t" << std::to_string(sol->cantidadPersonas) << "\t" << replaceNewLines(sol->nombreCuentas) << "\t" << replaceNewLines(sol->equipos) << "\t" << sol->fechaReservacion.toString().toStdString() << "\t" << horas[sol->horaInicio] << "\t" << horas[sol->horaFinal] << "\n";

            tempRes = resActual;
            resActual = resActual->next;
            delete tempRes;
            nodosRecorridos++;
        }

        cout << "[~ListasResvervas()] Todos los nodos fueron destruidos. Nodos eliminados: " << nodosRecorridos << "\n";
    }

    void push_back(Reserva *res) {


        if (head == nullptr) {
            head = res;
            return;
        }

        Reserva *resActual = head;

        // Recorrer la lista hasta al final
        while (resActual->next != nullptr) {
            resActual = resActual->next;
        }

        // Agregar la nueva reserva
        resActual->next = res;
        cout << "Agregado!\n";

    }

    string replaceNewLines(string old) {
        size_t pos = 0;
        while ((pos = old.find("\n", pos)) != std::string::npos) {
            old.replace(pos, 1, " | ");
            pos += 3;
        }

        return old;
    }
};


#endif // LISTARESERVAS_H
