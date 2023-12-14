#ifndef SOLICIANTEREPETIBLE_H
#define SOLICIANTEREPETIBLE_H

/*
 * Esta clase representa los solicitantes que pueden repetir una reservacion.
 * (Docente, Educacion Continua, Administrativo)
 */


#include "RepetirReserva.h"
#include "Solicitante.h"
class SolicitanteRepetible : Solicitante {
    public:
        RepetirReserva repetir;

        // Constructor completo
        SolicitanteRepetible(
                string nombreCompleto,
                char *cuenta[8],
                string correo,
                uint8_t cantidadPersonas,
                string nombreCuentas,
                string equipos,
                string fechaReservacion,
                uint8_t horaInicio,
                uint8_t horaFinal,
                RepetirReserva repetir
        ) : Solicitante(
                nombreCompleto,
                cuenta,
                correo,
                cantidadPersonas,
                nombreCuentas,
                equipos,
                fechaReservacion,
                horaInicio,
                horaFinal
            )
        {
            this->repetir = repetir;
        }


};

#endif // SOLICIANTEREPETIBLE_H
