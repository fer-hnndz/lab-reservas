#ifndef RESERVA_H
#define RESERVA_H
#include <string>
#include "Solicitante.h"

using std::string;

class ListaReservas;
class ReservaDia;
class Cframe;

class Reserva{
    friend ListaReservas;
    friend ReservaDia;
    friend Cframe;
private:
    Reserva *next;

    string labSolicitado;
    string clase;
    string motivo;
    Solicitante *perfil = nullptr;

    // Strings para excel
    string repetirText = "No Aplica";
    string perfilText;
public:
    Reserva(
            string labSolicitado,
            string clase,
            string motivo,
            Solicitante *perfil,
            string perfilText
            ) {
        this->next = nullptr;
        this->labSolicitado = labSolicitado;
        this->clase = clase;
        this->motivo = motivo;
        this->perfil = perfil;
        this->perfilText = perfilText;
    }

    void setRepetirText(string r) {
        this->repetirText = r;
    }
};

#endif // RESERVA_H
