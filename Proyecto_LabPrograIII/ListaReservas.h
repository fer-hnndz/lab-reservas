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

        file << "Nombre Estudiante,Fecha\n";
        while (resActual != nullptr) {
            // Guardar en archivo
            file << resActual->perfil->nombreCompleto << "," << resActual->perfil->fechaReservacion.toString().toStdString() << "\n";

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
