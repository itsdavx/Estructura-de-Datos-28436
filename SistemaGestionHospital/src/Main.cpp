#include "../include/ListaPacientes.h"
#include "../include/ColaCitas.h"
#include "../include/PilaHistorial.h"
#include "../include/Utilidades.h"
#include "../include/Menu.h"
#include "../include/Persistencia.h"

#include <iostream>

#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
    #include <direct.h>
#endif

using namespace std;

int main() {
    NodoLista* listaPacientes = nullptr;
    Cola colaCitas;
    Pila pilaHistorial;

    inicializarLista(listaPacientes);
    inicializarCola(colaCitas);
    inicializarPila(pilaHistorial);

    // Crear carpeta data si no existe
    #ifdef _WIN32
        _mkdir("data");
    #else
        mkdir("data", 0777);
    #endif


    // Cargar persistencia al iniciar
    cargarPacientesCSV(listaPacientes, "data/pacientes.csv");
    cargarCitasCSV(colaCitas, "data/citas.csv");
    cargarHistorialCSV(pilaHistorial, "data/historial.csv");


    int opcion;
    int contadorHistorias = obtenerMaxHistoria(listaPacientes);

    do {
        mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nEntrada invalida. Por favor ingrese un numero.\n";
            opcion = -1;
            continue;
        }

        cin.ignore();

        switch (opcion) {
            case 1: {
                string nombre, diagnostico;
                int edad, prioridad;

                cout << "\n--- REGISTRAR PACIENTE ---\n";
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Edad: ";
                cin >> edad;
                cin.ignore();
                cout << "Diagnostico: ";
                getline(cin, diagnostico);
                cout << "Prioridad (1=Alta, 2=Media, 3=Baja): ";
                cin >> prioridad;

                contadorHistorias++;
                insertarPaciente(listaPacientes, nombre, edad, diagnostico, contadorHistorias, prioridad);
                guardarPacientesCSV(listaPacientes, "data/pacientes.csv");

                cout << "\nPaciente registrado exitosamente. Historia Clinica: " 
                     << contadorHistorias << endl;
                break;
            }

            case 2: {
                int numHistoria;
                cout << "\nNumero de historia clinica: ";
                cin >> numHistoria;

                NodoLista* p = buscarPorHistoria(listaPacientes, numHistoria);
                if (p != nullptr) {
                    cout << "\n--- PACIENTE ENCONTRADO ---\n";
                    cout << p->dato << endl;
                } else {
                    cout << "\nPaciente no encontrado.\n";
                }
                break;
            }

            case 3: {
                string nombre;
                cout << "\nNombre del paciente: ";
                getline(cin, nombre);

                NodoLista* p = buscarPorNombre(listaPacientes, nombre);
                if (p != nullptr) {
                    cout << "\n--- PACIENTE ENCONTRADO ---\n";
                    cout << p->dato << endl;
                } else {
                    cout << "\nPaciente no encontrado.\n";
                }
                break;
            }

            case 4: {
                int numHistoria;
                cout << "\nNumero de historia del paciente a dar de alta: ";
                cin >> numHistoria;

                if (eliminarPaciente(listaPacientes, numHistoria)) {
                    guardarPacientesCSV(listaPacientes, "data/pacientes.csv");
                    cout << "\nPaciente dado de alta exitosamente.\n";
                } else {
                    cout << "\nPaciente no encontrado.\n";
                }
                break;
            }

            case 5: {
                mostrarPacientes(listaPacientes);
                break;
            }

            case 6: {
                int numHistoria;
                cout << "\nNumero de historia del paciente: ";
                cin >> numHistoria;

                NodoLista* p = buscarPorHistoria(listaPacientes, numHistoria);
                if (p != nullptr) {
                    encolarCita(colaCitas, p->dato);
                    guardarCitasCSV(colaCitas, "data/citas.csv");
                    cout << "\nCita registrada para: " << p->dato.nombre << endl;
                } else {
                    cout << "\nPaciente no encontrado. Registre al paciente primero.\n";
                }
                break;
            }

            case 7: {
                Paciente p;
                if (desencolarCita(colaCitas, p)) {
                    apilar(pilaHistorial, p);
                    guardarCitasCSV(colaCitas, "data/citas.csv");
                    guardarHistorialCSV(pilaHistorial, "data/historial.csv");
                    cout << "\nAtencion realizada para: " << p.nombre << endl;
                    cout << "Diagnostico: " << p.diagnostico << endl;
                } else {
                    cout << "\nNo hay citas pendientes.\n";
                }
                break;
            }

            case 8: {
                mostrarCitas(colaCitas);
                break;
            }

            case 9: {
                mostrarHistorial(pilaHistorial);
                break;
            }

            case 10: {
                Paciente p;
                if (desapilar(pilaHistorial, p)) {
                    cout << "\nSe deshizo la ultima atencion de: " << p.nombre << endl;
                    encolarCita(colaCitas, p);
                    guardarCitasCSV(colaCitas, "data/citas.csv");
                    guardarHistorialCSV(pilaHistorial, "data/historial.csv");
                    cout << "Cita devuelta a la cola.\n";
                } else {
                    cout << "\nNo hay atenciones para deshacer.\n";
                }
                break;
            }

            case 11: {
                if (!pilaVacia(pilaHistorial)) {
                    double promedio = calcularPromedioEdadRecursivo(pilaHistorial.tope, 0, 0);
                    cout << "\nPromedio de edad de pacientes atendidos: " 
                         << promedio << " anios\n";
                } else {
                    cout << "\nNo hay atenciones en el historial.\n";
                }
                break;
            }

            case 12: {
                string diagnostico;
                cout << "\nDiagnostico a buscar: ";
                getline(cin, diagnostico);

                int count = contarDiagnosticoRecursivo(listaPacientes, diagnostico);
                cout << "\nCantidad de pacientes con '" << diagnostico << "': " 
                     << count << endl;
                break;
            }

            case 13: {
                int hist1, hist2;
                cout << "\nPrimer paciente (historia): ";
                cin >> hist1;
                cout << "Segundo paciente (historia): ";
                cin >> hist2;

                NodoLista* p1 = buscarPorHistoria(listaPacientes, hist1);
                NodoLista* p2 = buscarPorHistoria(listaPacientes, hist2);

                if (p1 != nullptr && p2 != nullptr) {
                    cout << "\n--------- COMPARACION ---------\n";
                    
                    if (p1->dato < p2->dato)
                        cout << p1->dato.nombre << " es mas joven que " << p2->dato.nombre << endl;
                    else if (p1->dato > p2->dato)
                        cout << p1->dato.nombre << " es mayor que " << p2->dato.nombre << endl;
                    else
                        cout << "\nAmbos tienen la misma edad\n";
                    
                    if (p1->dato == p2->dato)
                        cout << "\nAmbos tienen la misma prioridad medica\n";
                    else
                        cout << "\nTienen diferente prioridad medica\n";
                } else {
                    cout << "\nUno o ambos pacientes no encontrados.\n";
                }
                break;
            }

            case 0:
                cout << "\nGracias por usar el sistema. Hasta pronto.\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 0);

    // Guardar lista final al salir (por seguridad de los datos)
    guardarPacientesCSV(listaPacientes, "data/pacientes.csv");
    guardarCitasCSV(colaCitas, "data/citas.csv");
    guardarHistorialCSV(pilaHistorial, "data/historial.csv");

    // Liberar memoria
    while (listaPacientes != nullptr) {
        NodoLista* temp = listaPacientes;
        listaPacientes = listaPacientes->siguiente;
        delete temp;
    }

    return 0;
}
