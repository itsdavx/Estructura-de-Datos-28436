#include "../include/Menu.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "\n================================================\n";
    cout << "  SISTEMA DE GESTION DE PACIENTES - HOSPITAL   \n";
    cout << "================================================\n";
    cout << "\n1.  Registrar nuevo paciente\n";
    cout << "2.  Buscar paciente por historia clinica\n";
    cout << "3.  Buscar paciente por nombre\n";
    cout << "4.  Eliminar paciente (alta medica)\n";
    cout << "5.  Mostrar todos los pacientes\n";
    cout << "6.  Registrar cita medica\n";
    cout << "7.  Atender siguiente cita\n";
    cout << "8.  Ver citas pendientes\n";
    cout << "9.  Ver historial de atenciones\n";
    cout << "10. Deshacer ultima atencion\n";
    cout << "11. Calcular promedio de edad (atendidos)\n";
    cout << "12. Contar pacientes por diagnostico\n";
    cout << "13. Comparar dos pacientes\n";
    cout << "0.  Salir\n";
    cout << "\nSeleccione una opcion: ";
}
