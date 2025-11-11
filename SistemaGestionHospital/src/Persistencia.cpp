#include "../include/Persistencia.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Persistencia Pacientes

void guardarPacientesCSV(NodoLista *cabeza, const string &rutaArchivo)
{
    ofstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo de pacientes.\n";
        return;
    }

    archivo << "Historia,Nombre,Edad,Diagnostico,Prioridad\n";
    for (NodoLista *temp = cabeza; temp; temp = temp->siguiente)
    {
        archivo << temp->dato.numHistoria << ","
                << temp->dato.nombre << ","
                << temp->dato.edad << ","
                << temp->dato.diagnostico << ","
                << temp->dato.prioridad << "\n";
    }
    archivo.close();
}

void cargarPacientesCSV(NodoLista *&cabeza, const string &rutaArchivo)
{
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        cerr << "(Aviso) No se encontro pacientes.csv, se creara al guardar.\n";
        return;
    }

    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string historiaStr, nombre, edadStr, diagnostico, prioridadStr;
        getline(ss, historiaStr, ',');
        getline(ss, nombre, ',');
        getline(ss, edadStr, ',');
        getline(ss, diagnostico, ',');
        getline(ss, prioridadStr, ',');

        int historia = stoi(historiaStr);
        int edad = stoi(edadStr);
        int prioridad = stoi(prioridadStr);

        insertarPaciente(cabeza, nombre, edad, diagnostico, historia, prioridad);
    }
    archivo.close();
}

// Persistencia Citas

void guardarCitasCSV(const Cola &cola, const string &rutaArchivo)
{
    ofstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        cerr << "Error al abrir citas.csv.\n";
        return;
    }

    archivo << "Historia,Nombre,Edad,Diagnostico,Prioridad\n";
    NodoCola *temp = cola.front;
    while (temp)
    {
        archivo << temp->dato.numHistoria << ","
                << temp->dato.nombre << ","
                << temp->dato.edad << ","
                << temp->dato.diagnostico << ","
                << temp->dato.prioridad << "\n";
        temp = temp->siguiente;
    }
    archivo.close();
}

void cargarCitasCSV(Cola &cola, const string &rutaArchivo)
{
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        cerr << "(Aviso) No se encontro citas.csv, se creara al guardar.\n";
        return;
    }

    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string historiaStr, nombre, edadStr, diagnostico, prioridadStr;
        getline(ss, historiaStr, ',');
        getline(ss, nombre, ',');
        getline(ss, edadStr, ',');
        getline(ss, diagnostico, ',');
        getline(ss, prioridadStr, ',');

        Paciente p;
        p.numHistoria = stoi(historiaStr);
        p.nombre = nombre;
        p.edad = stoi(edadStr);
        p.diagnostico = diagnostico;
        p.prioridad = stoi(prioridadStr);

        encolarCita(cola, p);
    }
    archivo.close();
}

// Persistencia Historial

void guardarHistorialCSV(const Pila &pila, const string &rutaArchivo)
{
    ofstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        cerr << "Error al abrir historial.csv.\n";
        return;
    }

    archivo << "Historia,Nombre,Edad,Diagnostico,Prioridad\n";
    NodoPila *temp = pila.tope;
    while (temp)
    {
        archivo << temp->dato.numHistoria << ","
                << temp->dato.nombre << ","
                << temp->dato.edad << ","
                << temp->dato.diagnostico << ","
                << temp->dato.prioridad << "\n";
        temp = temp->siguiente;
    }
    archivo.close();
}

void cargarHistorialCSV(Pila &pila, const string &rutaArchivo)
{
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open())
    {
        cerr << "(Aviso) No se encontro historial.csv, se creara al guardar.\n";
        return;
    }

    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string historiaStr, nombre, edadStr, diagnostico, prioridadStr;
        getline(ss, historiaStr, ',');
        getline(ss, nombre, ',');
        getline(ss, edadStr, ',');
        getline(ss, diagnostico, ',');
        getline(ss, prioridadStr, ',');

        Paciente p;
        p.numHistoria = stoi(historiaStr);
        p.nombre = nombre;
        p.edad = stoi(edadStr);
        p.diagnostico = diagnostico;
        p.prioridad = stoi(prioridadStr);

        apilar(pila, p);
    }
    archivo.close();
}