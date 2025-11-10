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
             << "\nDiagnostico: " << diagnostico
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
        cout << "\n Atencion registrada para el paciente: " << p.nombre << endl;
    }

    // Deshacer la última atención
    void deshacerAtencion() {
        if (estaVacio()) {
            cout << "\nSin atenciones para deshacer.\n";
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
             << "MODULO DE HISTORIAL MEDICO\n"
             << "==============================\n"
             << "1. Registrar atencion\n"
             << "2. Deshacer última atencion\n"
             << "3. Mostrar historial completo\n"
             << "0. Volver al menu principal\n"
             << "Seleccione una opcion: ";
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
            cout << "\n Regresando al menú principal...\n";
        }
        else {
            cout << "\n Opcion invalida, intente de nuevo.\n";
        }

    } while (opcion != 0);
}

int main() {
    int opcion;

    do {
        cout << "\n====================================\n"
            << "SISTEMA DE GESTIÓN DE HOSPITAL\n"
            << "====================================\n"
            << "1. Modulo de Pacientes (Lista Dinámica)\n"
            << "2. Modulo de Citas (Cola)\n"
            << "3. Módulo de Historial (Pila)\n"
            << "0. Salir\n"
            << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n Llamar funcion: menuPacientes();\n";
                // menu pacientes (Por implementar)
                break;
            case 2:
                cout << "\n Llamar funcion: menuCitas();\n";
                // menu citas (Por implementar)
                break;
            case 3:
                menuHistorial(); 
                break;
            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion invalida, intente de nuevo.\n";
        }

    } while (opcion != 0);
}

