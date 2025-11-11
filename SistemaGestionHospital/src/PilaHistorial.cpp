#include "../include/PilaHistorial.h"
#include <iostream>
using namespace std;

void inicializarPila(Pila &p) { 
    p.tope = nullptr; 
}

bool pilaVacia(const Pila &p) { 
    return p.tope == nullptr; 
}

void apilar(Pila &p, Paciente paciente) {
    NodoPila *nuevo = new NodoPila{paciente, p.tope};
    p.tope = nuevo;
}

bool desapilar(Pila &p, Paciente &paciente) {
    if (pilaVacia(p))
        return false;
    NodoPila *temp = p.tope;
    paciente = temp->dato;
    p.tope = temp->siguiente;
    delete temp;
    return true;
}

void mostrarHistorial(const Pila &p) {
    if (pilaVacia(p)) {
        cout << "\nNo hay atenciones en el historial.\n";
        return;
    }
    cout << "\n---------------------------- HISTORIAL DE ATENCIONES ----------------------------n";
    NodoPila *temp = p.tope;
    int pos = 1;
    while (temp) {
        cout << pos++ << ". " << temp->dato.nombre << " - " << temp->dato.diagnostico << " (Historia: " << temp->dato.numHistoria << ")\n";
        temp = temp->siguiente;
    }
}
