#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "ListaPacientes.h"
#include "ColaCitas.h"
#include "PilaHistorial.h"
#include <string>

// Pacientes
void guardarPacientesCSV(NodoLista *cabeza, const std::string &rutaArchivo);
void cargarPacientesCSV(NodoLista *&cabeza, const std::string &rutaArchivo);

// Citas médicas
void guardarCitasCSV(const Cola &cola, const std::string &rutaArchivo);
void cargarCitasCSV(Cola &cola, const std::string &rutaArchivo);

// Historial de atenciones
void guardarHistorialCSV(const Pila &pila, const std::string &rutaArchivo);
void cargarHistorialCSV(Pila &pila, const std::string &rutaArchivo);

#endif