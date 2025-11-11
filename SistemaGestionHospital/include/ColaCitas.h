#ifndef COLA_CITAS_H
#define COLA_CITAS_H

#include "Paciente.h"

struct NodoCola {
    Paciente dato;
    NodoCola *siguiente;
};

struct Cola{
    NodoCola *front;
    NodoCola *rear;
};

//Funciones de Cola
void inicializarCola(Cola &c);
bool colaVacia(const Cola &c);
void encolarCita(Cola &c, Paciente paciente);
bool desencolarCita(Cola &c, Paciente &paciente);
void mostrarCitas(const Cola &c);

#endif