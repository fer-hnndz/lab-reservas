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
    Solicitante *perfil = nullptr;
public:
    Reserva(
            string labSolicitado,
            string clase,
            string motivo,
            Solicitante *perfil
            ) {
        this->next = nullptr;
        this->labSolicitado = labSolicitado;
        this->clase = clase;
        this->motivo = motivo;
        this->perfil = perfil;
    }
};

#endif // RESERVA_H
