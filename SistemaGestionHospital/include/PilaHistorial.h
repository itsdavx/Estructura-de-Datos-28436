#ifndef PILA_HISTORIAL_H
#define PILA_HISTORIAL_H

#include "Paciente.h"

struct NodoPila {
    Paciente dato;
    NodoPila *siguiente;
};

struct Pila {
    NodoPila *tope;
};

//Funciones de Pila
void inicializarPila(Pila &p);
bool pilaVacia(const Pila &p);
void apilar(Pila &p, Paciente paciente);
bool desapilar(Pila &p, Paciente &paciente);
void mostrarHistorial(const Pila &p);

#endif
