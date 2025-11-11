#include "../include/ListaPacientes.h"
#include "../include/ColaCitas.h"
#include "../include/PilaHistorial.h"
#include "../include/Utilidades.h"
#include "../include/Menu.h"

int main()
{
    NodoLista *listaPacientes = nullptr;
    Cola colaCitas;
    Pila pilaHistorial;

    inicializarLista(listaPacientes);
    inicializarCola(colaCitas);
    inicializarPila(pilaHistorial);

    int opcion, contadorHistorias = 1000;
    do
    {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        { // registrar paciente
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
            cout << "\nPaciente registrado exitosamente. Historia Clinica: " << contadorHistorias << endl;
            break;
        }
        case 2:
        {
            int h;
            cout << "\nHistoria: ";
            cin >> h;
            NodoLista *p = buscarPorHistoria(listaPacientes, h);
            if (p)
                cout << p->dato << endl;
            else
                cout << "\nNo encontrado.\n";
            break;
        }
        case 3:
        {
            string nombre;
            cout << "\nNombre: ";
            getline(cin, nombre);
            NodoLista *p = buscarPorNombre(listaPacientes, nombre);
            if (p)
                cout << p->dato << endl;
            else
                cout << "\nNo encontrado.\n";
            break;
        }
        case 4:
        {
            int h;
            cout << "\nHistoria a eliminar: ";
            cin >> h;
            cout << (eliminarPaciente(listaPacientes, h) ? "\nPaciente eliminado.\n" : "\nNo encontrado.\n");
            break;
        }
        case 5:
            mostrarPacientes(listaPacientes);
            break;
        case 6:
        {
            int h;
            cout << "\nHistoria: ";
            cin >> h;
            NodoLista *p = buscarPorHistoria(listaPacientes, h);
            if (p)
            {
                encolarCita(colaCitas, p->dato);
                cout << "\nCita registrada.\n";
            }
            else
                cout << "\nPaciente no encontrado.\n";
            break;
        }
        case 7:
        {
            Paciente p;
            if (desencolarCita(colaCitas, p))
            {
                apilar(pilaHistorial, p);
                cout << "\nAtencion realizada.\n";
            }
            else
                cout << "\nNo hay citas.\n";
            break;
        }
        case 8:
            mostrarCitas(colaCitas);
            break;
        case 9:
            mostrarHistorial(pilaHistorial);
            break;
        case 10:
        {
            Paciente p;
            if (desapilar(pilaHistorial, p))
            {
                encolarCita(colaCitas, p);
                cout << "\nDeshecha.\n";
            }
            else
                cout << "\nNada que deshacer.\n";
            break;
        }
        case 11:
        {
            if (!pilaVacia(pilaHistorial))
                cout << "\nPromedio edad: " << calcularPromedioEdadRecursivo(pilaHistorial.tope, 0, 0) << endl;
            else
                cout << "\nHistorial vacio.\n";
            break;
        }
        case 12:
        {
            string diag;
            cout << "\nDiagnostico: ";
            getline(cin, diag);
            cout << "\nPacientes con '" << diag << "': "
                 << contarDiagnosticoRecursivo(listaPacientes, diag) << endl;
            break;
        }
        case 13:
        {
            int h1, h2;
            cout << "\nPrimer historia: ";
            cin >> h1;
            cout << "Segunda: ";
            cin >> h2;
            NodoLista *p1 = buscarPorHistoria(listaPacientes, h1);
            NodoLista *p2 = buscarPorHistoria(listaPacientes, h2);
            if (p1 && p2)
            {
                if (p1->dato < p2->dato)
                    cout << p1->dato.nombre << " es mas joven.\n";
                else if (p1->dato > p2->dato)
                    cout << p1->dato.nombre << " es mayor.\n";
                else
                    cout << "Misma edad.\n";
                cout << ((p1->dato == p2->dato) ? "Misma prioridad.\n" : "Diferente prioridad.\n");
            }
            else
                cout << "\nNo encontrados.\n";
            break;
        }
        }
    } while (opcion != 0);

    return 0;
}
