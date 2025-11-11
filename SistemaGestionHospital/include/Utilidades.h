#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "ListaPacientes.h"
#include "PilaHistorial.h"

//Uso de Templates
template <typename T>
T maximo(T a, T b) { return (a > b) ? a : b; }
template <typename T>
T minimo(T a, T b) { return (a < b) ? a : b; }
template <typename T>
void intercambiar(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}
template <typename NodoTipo>
int contarNodos(NodoTipo *cabeza)
{
    return cabeza ? 1 + contarNodos(cabeza->siguiente) : 0;
}
template <typename T>
int buscarEnArreglo(T arr[], int n, T valor)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == valor)
            return i;
    return -1;
}

//Funciones recursivas
double calcularPromedioEdadRecursivo(NodoPila *nodo, int suma, int cont);
int contarDiagnosticoRecursivo(NodoLista *nodo, string diagnostico);

#endif
