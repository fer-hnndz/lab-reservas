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
            return;
        }


        // Skip the header line
           std::string headerLine;
           std::getline(file, headerLine);

           string labSolicitado, clase, motivo, perfilText, repetirText, nombreCompleto, cuenta, correo, cantidadPersonasStr, nombresCuentas, equipos, fechaInicioStr, fechaFinalStr;

           // Read and process the rest of the file
           while (!file.eof()) {
               // Read a line from the file
               std::string line;
               std::getline(file, line);

               // Check for the end of the file
               if (file.eof()) {
                   break;
               }

               // Use a stringstream to extract values from the line
               std::istringstream ss(line);

               // Read values into variables
               ss >> labSolicitado >> clase >> motivo >> perfilText >> repetirText >> nombreCompleto
                  >> cuenta >> correo >> cantidadPersonasStr >> nombresCuentas >> equipos
                  >> fechaInicioStr >> fechaFinalStr;

               // Process the values (replace this with your actual processing logic)
               std::cout << "Read values: " << labSolicitado << ", " << clase << ", " << motivo << ", "
                         << perfilText << ", " << repetirText << ", " << nombreCompleto << ", "
                         << cuenta << ", " << correo << ", " << cantidadPersonasStr << ", "
                         << nombresCuentas << ", " << equipos << ", " << fechaInicioStr << ", "
                         << fechaFinalStr << std::endl;
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


        string horas[10] = {"6:40", "8:10", "9:55", "11:15", "13:20", "14:40", "16:00", "17:20", "18:40", "20:00"};
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
