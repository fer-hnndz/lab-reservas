    #ifndef LISTARESERVAS_H
#define LISTARESERVAS_H

#include "Reserva.h"
#include <iostream>
#include <fstream>

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
