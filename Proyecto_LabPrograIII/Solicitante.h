#ifndef SOLICITANTE_H
#define SOLICITANTE_H

#include <string>
#include <cstring>
#include <QDate>
using std::string;

class Solicitante {
    public:
        string nombreCompleto;
        string cuenta; // Limitar los numeros de cuenta a 8 caracteres.
        string correo;
        uint8_t cantidadPersonas; // Usar un tipo de dato mas pequeno para optimizar memoria
        string nombreCuentas; // Nombres y numero de cuentas de los integrantes
        string equipos; // Equipos a utilizar durante la reserva
        QDate fechaReservacion;

        // Estos guardaran la posicion de la hora seleccionada dentro del combobox de las horas de inicio/final.
        // Permite poder chequear mas facilmente si se selecciono una hora valida.
        int horaInicio;
        int horaFinal;


        Solicitante(
                string nombreCompleto,
                string cuenta,
                string correo,
                int cantidadPersonas,
                string nombreCuentas,
                string equipos,
                QDate fechaReservacion,
                int horaInicio,
                int horaFinal
        ) {
            this->nombreCompleto = nombreCompleto;

            this->cuenta = cuenta;
            this->correo = correo;
            this->cantidadPersonas = cantidadPersonas;
            this->nombreCuentas = nombreCuentas;
            this->equipos = equipos;
            this->fechaReservacion = fechaReservacion;
            this->horaInicio = horaInicio;
            this->horaFinal = horaFinal;
        }

};

#endif // SOLICITANTE_H
