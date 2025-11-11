#ifndef LISTA_PACIENTES_H
#define LISTA_PACIENTES_H

#include "Paciente.h"

struct NodoLista {
    Paciente dato;
    NodoLista *siguiente;
};

//Funciones de Lista
void inicializarLista(NodoLista *&cabeza);
void insertarPaciente(NodoLista *&cabeza, string nombre, int edad, string diagnostico, int numHistoria, int prioridad);
NodoLista *buscarPorHistoria(NodoLista *cabeza, int numHistoria);
NodoLista *buscarPorNombre(NodoLista *cabeza, string nombre);
bool eliminarPaciente(NodoLista *&cabeza, int numHistoria);
void mostrarPacientes(NodoLista *cabeza);

#endif
