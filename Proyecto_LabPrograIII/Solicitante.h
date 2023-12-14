#ifndef SOLICITANTE_H
#define SOLICITANTE_H

#include <string>
#include <cstring>

using std::string;

class Reserva;
class Solicitante {
    public:
        string nombreCompleto;
        char cuenta[8]; // Limitar los numeros de cuenta a 8 caracteres.
        string correo;
        uint8_t cantidadPersonas; // Usar un tipo de dato mas pequeno para optimizar memoria
        string nombreCuentas; // Nombres y numero de cuentas de los integrantes
        string equipos; // Equipos a utilizar durante la reserva
        string fechaReservacion;

        // Estos guardaran la posicion de la hora seleccionada dentro del combobox de las horas de inicio/final.
        // Permite poder chequear mas facilmente si se selecciono una hora valida.
        int horaInicio;
        int horaFinal;


        Solicitante(
                string nombreCompleto,
                char *cuenta[8],
                string correo,
                uint8_t cantidadPersonas,
                string nombreCuentas,
                string equipos,
                string fechaReservacion,
                uint8_t horaInicio,
                uint8_t horaFinal
        ) {
            this->nombreCompleto = nombreCompleto;

            strcpy(this->cuenta, *cuenta);
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
