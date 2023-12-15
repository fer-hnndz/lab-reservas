#ifndef SOLICIANTEREPETIBLE_H
#define SOLICIANTEREPETIBLE_H

#include <QDate>
/*
 * Esta clase representa los solicitantes que pueden repetir una reservacion.
 * (Docente, Educacion Continua, Administrativo)
 */


#include "RepetirReserva.h"
#include "Solicitante.h"
class SolicitanteRepetible : public Solicitante {
    public:
        RepetirReserva repetir;

        // Constructor completo
        SolicitanteRepetible(
                string nombreCompleto,
                string cuenta,
                string correo,
                int cantidadPersonas,
                string nombreCuentas,
                string equipos,
                QDate fechaReservacion,
                int horaInicio,
                int horaFinal,
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
