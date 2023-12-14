#ifndef RESERVA_H
#define RESERVA_H
#include <string>
#include "Solicitante.h"

using std::string;

class ListaReservas;
class Reserva{
    friend ListaReservas;
private:
    Reserva *next;

    string labSolicitado;
    string clase;
    string motivo;
    Solicitante perfil;
};

#endif // RESERVA_H
