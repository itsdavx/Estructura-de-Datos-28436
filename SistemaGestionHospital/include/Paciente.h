#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
using namespace std;

struct Paciente {
    string nombre;
    int edad;
    string diagnostico;
    int numHistoria;
    int prioridad; // 1=alta, 2=media, 3=baja
};

// Sobrecarga de operadores
bool operator<(const Paciente &p1, const Paciente &p2);
bool operator>(const Paciente &p1, const Paciente &p2);
bool operator==(const Paciente &p1, const Paciente &p2);
ostream &operator<<(ostream &os, const Paciente &p);

#endif
