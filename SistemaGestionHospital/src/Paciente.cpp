#include "../include/Paciente.h"

bool operator<(const Paciente &p1, const Paciente &p2) { return p1.edad < p2.edad; }
bool operator>(const Paciente &p1, const Paciente &p2) { return p1.edad > p2.edad; }
bool operator==(const Paciente &p1, const Paciente &p2) { return p1.prioridad == p2.prioridad; }

ostream &operator<<(ostream &os, const Paciente &p)
{
    os << "Historia: " << p.numHistoria << " | "
       << "Nombre: " << p.nombre << " | "
       << "Edad: " << p.edad << " | "
       << "Diagnostico: " << p.diagnostico << " | "
       << "Prioridad: "
       << (p.prioridad == 1 ? "ALTA" : p.prioridad == 2 ? "MEDIA"
                                                        : "BAJA");
    return os;
}
