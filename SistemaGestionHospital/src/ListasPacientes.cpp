#include "../include/ListaPacientes.h"
#include <iostream>

using namespace std;

void inicializarLista(NodoLista *&cabeza) {
     cabeza = nullptr; 
}

void insertarPaciente(NodoLista *&cabeza, string nombre, int edad, string diagnostico, int numHistoria, int prioridad) {
    NodoLista *nuevo = new NodoLista{{nombre, edad, diagnostico, numHistoria, prioridad}, nullptr};
    if (!cabeza)
        cabeza = nuevo;
    else {
        NodoLista *temp = cabeza;
        while (temp->siguiente)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

NodoLista *buscarPorHistoria(NodoLista *cabeza, int numHistoria) {
    for (NodoLista *temp = cabeza; temp; temp = temp->siguiente)
        if (temp->dato.numHistoria == numHistoria)
            return temp;
    return nullptr;
}

NodoLista *buscarPorNombre(NodoLista *cabeza, string nombre) {
    for (NodoLista *temp = cabeza; temp; temp = temp->siguiente)
        if (temp->dato.nombre == nombre)
            return temp;
    return nullptr;
}

bool eliminarPaciente(NodoLista *&cabeza, int numHistoria) {
    if (!cabeza)
        return false;
    if (cabeza->dato.numHistoria == numHistoria) {
        NodoLista *tmp = cabeza;
        cabeza = cabeza->siguiente;
        delete tmp;
        return true;
    }
    NodoLista *temp = cabeza;
    while (temp->siguiente) {
        if (temp->siguiente->dato.numHistoria == numHistoria) {
            NodoLista *eliminar = temp->siguiente;
            temp->siguiente = eliminar->siguiente;
            delete eliminar;
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

void mostrarPacientes(NodoLista *cabeza) {
    if (!cabeza) {
        cout << "\nNo hay pacientes registrados.\n";
        return;
    }
    cout << "\n---------------------------- LISTA DE PACIENTES ----------------------------\n";
    for (NodoLista *temp = cabeza; temp; temp = temp->siguiente)
        cout << temp->dato << endl;
}