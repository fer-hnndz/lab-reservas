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
class ListaReservas {

private:
    Reserva *head;

public:
    ListaReservas() {
        // TODO: Cargar datos desde el archivo
        head = nullptr;
        cout << "Instantiated\n";

    }
    ~ListaReservas() {
        // Puede ser que se guarde cada vez que se agregue una reserva que puede que no sea necesario
        // guardar cuando la lista es destruida.

        // TODO: Guardar (?)

        ofstream file("reservas.xls", ofstream::out); // No ponerle app ya que vamos a volver a escribir toda la lista, por lo cual nada se va a duplicar
        cout << "Destruyendo Lista...\n";

        Reserva *resActual = head;
        Reserva *tempRes = nullptr;

        int nodosRecorridos = 0;
        cout << "[~ListasReservas()] Intentando eliminar todos los nodos de la lista...\n";

       // Formato de Excel
        file << "Lab Solicitado\tClase para la que requiere laboratorio\tMotivo de Reserva\tPerfil de Solicitante\tRepetir Reservacion\tNombre Completo\tNumero de Cuenta\tCorreo\tCantidad de Integrantes\tNombres y Numeros de Cuenta de Integrantes\tEquipo a utilzarse\tFecha de Reserva\tHora Inicio\tHora Final\n";
        while (resActual != nullptr) {
            // Guardar en archivo

            // TODO: GUARDAR EL NOMBRE DEL PERFIL EN DONDE ESTA LA DOBLE COMA
            Solicitante *sol = resActual->perfil;
            file << resActual->labSolicitado << "\t" << resActual->clase << "\t" << resActual->motivo << "\tPERFIL\tREPETIR\t" << sol->nombreCompleto << "\t" << sol->cuenta << "\t" << sol->correo << "\t" << sol->cantidadPersonas << "\t" << sol->nombreCuentas << "\t" << sol->equipos << "\t" << sol->fechaReservacion.toString().toStdString() << "\t" << sol->horaInicio << "\t" << sol->horaFinal<< "\n";

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
};


#endif // LISTARESERVAS_H
