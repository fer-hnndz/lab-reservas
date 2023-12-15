#ifndef HORASRESERVADAS_H
#define HORASRESERVADAS_H

/*
 * Clase que guarda informacion acerca de si una hora esta disponible o no
 */

class HorasReservadas {
private:
    int pos;
    bool _esInicio;
    bool _esFinal;
    bool _reservado;

public:
    HorasReservadas(int pos) {
        this->pos = pos;
        this->_esInicio = false;
        this->_esFinal = false;
        this->_reservado = false;
    }

    void setInicio(bool i) {
        this->_esInicio = i;
        if (i) this->_reservado = i; // Setear que esta reservado forzozamente
    }

    void setFinal(bool f) {
        this->_esFinal = f;
        if (f) this->_reservado = f; // Setear que esta reservado forzozamente
    }

    void setReservado(bool r) {
        this->_reservado = r;
    }

    // Getters
    int getPos() {return pos;}
    bool esInicio() {return this->_esInicio;}
    bool esFinal() {return this->_esFinal;}
    bool esReservado() {return this->_reservado;}
};

#endif // HORASRESERVADAS_H
