#ifndef RESERVADIA_H
#define RESERVADIA_H

#define HORAS_CONST 11

#include <QDate>
#include <HorasReservadas.h>
#include <Reserva.h>
#include <iostream>

using std::cout;
/*
 * Clase que almacena las horas reservadas para un dia en especifico
 */

class ReservaDia {
public:
    QDate fecha;
    string lab;
    HorasReservadas *horas[HORAS_CONST];

    // Constructor
    ReservaDia(QDate fecha, string lab, Reserva *reservasHead) {
        this->fecha = fecha;
        this->lab = lab;

        // Empezar todo libre
        for (int i = 0; i < HORAS_CONST; i++) {
            this->horas[i] = new HorasReservadas(i);
        }

        // Recorrer la lista de reservas buscando las reservas hechas el mismo dia
        Reserva *res = reservasHead;
        while (res != nullptr) {

            // Si no es la fecha del dia actual, seguir
            if (res->perfil->fechaReservacion != fecha) {
                res = res->next;
                continue;
            }

            // Verificar que sea del mismo lab
            if ( !(res->labSolicitado == lab)) {
                res = res->next;
                continue;
            }

            // Actualizar valores del dia de reservas
            int inicio = res->perfil->horaInicio;
            int final = res->perfil->horaFinal;

            this->horas[inicio]->setInicio(true);

            // 0 < 3
            // 0 -> inicio
            // 1 - > reservado
            // 2 -> reservado
            // 3 -> final

            for (int i = inicio + 1; i < final; i++) {
                this->horas[i]->setReservado(true);
            }
            this->horas[final]->setFinal(true);

            res = res->next;

        }
    }

    ~ReservaDia() {
        for (int i = 0; i < HORAS_CONST; i++) {
            delete horas[i];
        }
    }

    void imprimirDia() {
        for (int i = 0; i < HORAS_CONST; i++) {
            if (horas[i]->esInicio()) {
                cout << "I ";
                continue;
            };

            if (horas[i]->esFinal()) {
                cout << "F ";
                continue;
            }
            if (horas[i]->esReservado()) cout << "R ";
            else cout << "O ";
        }

        cout << "\n";
    }

};

#endif // RESERVADIA_H
