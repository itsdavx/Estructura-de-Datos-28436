#include <iostream>
#include <string>
using namespace std;

class Paciente {
public:
    string nombre;
    int edad;
    string diagnostico;
    int prioridad; // 1 = alta, 2 = media, 3 = baja

    Paciente(string n = "", int e = 0, string d = "", int p = 3) {
        nombre = n;
        edad = e;
        diagnostico = d;
        prioridad = p;
    }

    // Sobrecarga de operador '>' para comparar por edad
    bool operator>(const Paciente& otro) const {
        return edad > otro.edad;
    }

    // Sobrecarga de operador '<' para comparar por prioridad (1 es más urgente)
    bool operator<(const Paciente& otro) const {
        return prioridad < otro.prioridad;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << "\nEdad: " << edad
             << "\nDiagnóstico: " << diagnostico
             << "\nPrioridad: " << prioridad << endl;
    }
};

struct Nodo {
    Paciente* paciente; 
    Nodo* siguiente;
};

class Historial {
private:
    Nodo* tope;

public:
    Historial() {
        tope = nullptr;
    }

    ~Historial() {
        // Liberar toda la memoria dinámica
        while (!estaVacio()) {
            deshacerAtencion();
        }
    }

    bool estaVacio() {
        return tope == nullptr;
    }

    // Registrar atención
    void registrarAtencion(const Paciente& p) {
        Nodo* nuevo = new Nodo;
        nuevo->paciente = new Paciente(p);
        nuevo->siguiente = tope;
        tope = nuevo;
        cout << "\n Atención registrada para el paciente: " << p.nombre << endl;
    }

    // Deshacer la última atención
    void deshacerAtencion() {
        if (estaVacio()) {
            cout << "\nNo hay atenciones para deshacer.\n";
            return;
        }

        Nodo* temp = tope;
        cout << "\nAtención eliminada del historial: " << temp->paciente->nombre << endl;

        tope = tope->siguiente;
        delete temp->paciente; 
        delete temp; 
    }

    // Mostrar las atenciones realizadas
    void mostrarHistorial() {
        if (estaVacio()) {
            cout << "\n No hay atenciones registradas.\n";
            return;
        }

        cout << "\n Historial de Atenciones:\n";
        Nodo* actual = tope;
        while (actual != nullptr) {
            cout << "-----------------------------\n";
            actual->paciente->mostrar();
            actual = actual->siguiente;
        }
    }
};


void menuHistorial() {
    Historial historial;
    int opcion;

    do {
        cout << "\n==============================\n"
             << "  🏥 MÓDULO DE HISTORIAL MÉDICO\n"
             << "==============================\n"
             << "1. Registrar atención\n"
             << "2. Deshacer última atención\n"
             << "3. Mostrar historial completo\n"
             << "0. Volver al menú principal\n"
             << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, diagnostico;
            int edad, prioridad;
            cout << "\nNombre del paciente: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cin.ignore();
            cout << "Diagnóstico: ";
            getline(cin, diagnostico);
            cout << "Prioridad (1=Alta, 2=Media, 3=Baja): ";
            cin >> prioridad;

            Paciente nuevo(nombre, edad, diagnostico, prioridad);
            historial.registrarAtencion(nuevo);
        }
        else if (opcion == 2) {
            historial.deshacerAtencion();
        }
        else if (opcion == 3) {
            historial.mostrarHistorial();
        }
        else if (opcion == 0) {
            cout << "\n Volviendo al menú principal...\n";
        }
        else {
            cout << "\n Opción inválida, intente nuevamente.\n";
        }

    } while (opcion != 0);
}

int main() {
    int opcion;

    do {
        cout << "\n====================================\n";
        cout << "   🏥 SISTEMA DE GESTIÓN HOSPITALARIA\n";
        cout << "====================================\n";
        cout << "1. Módulo de Pacientes (Lista Dinámica)\n";
        cout << "2. Módulo de Citas (Cola)\n";
        cout << "3. Módulo de Historial (Pila)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n Llamar función: menuPacientes();\n";
                // menu pacientes (Por implementar)
                break;
            case 2:
                cout << "\n Llamar función: menuCitas();\n";
                // menu citas (Por implementar)
                break;
            case 3:
                menuHistorial(); 
                break;
            case 0:
                cout << "\n👋 Saliendo del sistema...\n";
                break;
            default:
                cout << "\n❌ Opción inválida, intente nuevamente.\n";
        }

    } while (opcion != 0);
}

