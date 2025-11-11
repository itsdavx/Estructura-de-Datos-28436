#include "../include/ColaCitas.h"
#include <iostream>
using namespace std;

void inicializarCola(Cola &c) { c.front = c.rear = nullptr; }
bool colaVacia(const Cola &c) { return c.front == nullptr; }

void encolarCita(Cola &c, Paciente paciente)
{
    NodoCola *nuevo = new NodoCola{paciente, nullptr};
    if (colaVacia(c))
        c.front = c.rear = nuevo;
    else
    {
        c.rear->siguiente = nuevo;
        c.rear = nuevo;
    }
}

bool desencolarCita(Cola &c, Paciente &paciente)
{
    if (colaVacia(c))
        return false;
    NodoCola *temp = c.front;
    paciente = temp->dato;
    c.front = temp->siguiente;
    if (!c.front)
        c.rear = nullptr;
    delete temp;
    return true;
}

void mostrarCitas(const Cola &c)
{
    if (colaVacia(c))
    {
        cout << "\nNo hay citas pendientes.\n";
        return;
    }
    cout << "\n========== CITAS PENDIENTES ==========\n";
    NodoCola *temp = c.front;
    int pos = 1;
    while (temp)
    {
        cout << pos++ << ". " << temp->dato.nombre
             << " (Historia: " << temp->dato.numHistoria << ")\n";
        temp = temp->siguiente;
    }
}
