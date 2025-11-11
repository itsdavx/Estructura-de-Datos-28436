#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==================== ESTRUCTURA PACIENTE ====================
struct Paciente {
    string nombre;
    int edad;
    string diagnostico;
    int numHistoria;
    int prioridad; // 1=alta, 2=media, 3=baja
};

// ==================== NODO PARA LISTA DE PACIENTES ====================
struct NodoLista {
    Paciente dato;
    NodoLista* siguiente;
};

// ==================== NODO PARA COLA DE CITAS ====================
struct NodoCola {
    Paciente dato;
    NodoCola* siguiente;
};

// ==================== ESTRUCTURA COLA ====================
struct Cola {
    NodoCola* front;
    NodoCola* rear;
};

// ==================== NODO PARA PILA DE HISTORIAL ====================
struct NodoPila {
    Paciente dato;
    NodoPila* siguiente;
};

// ==================== ESTRUCTURA PILA ====================
struct Pila {
    NodoPila* tope;
};

// ==================== FUNCIONES DE LISTA DE PACIENTES ====================
void inicializarLista(NodoLista* &cabeza) {
    cabeza = nullptr;
}

void insertarPaciente(NodoLista* &cabeza, string nombre, int edad, string diagnostico, int numHistoria, int prioridad) {
    NodoLista* nuevo = new NodoLista();
    nuevo->dato.nombre = nombre;
    nuevo->dato.edad = edad;
    nuevo->dato.diagnostico = diagnostico;
    nuevo->dato.numHistoria = numHistoria;
    nuevo->dato.prioridad = prioridad;
    nuevo->siguiente = nullptr;
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        NodoLista* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

NodoLista* buscarPorHistoria(NodoLista* cabeza, int numHistoria) {
    NodoLista* temp = cabeza;
    while (temp != nullptr) {
        if (temp->dato.numHistoria == numHistoria) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

NodoLista* buscarPorNombre(NodoLista* cabeza, string nombre) {
    NodoLista* temp = cabeza;
    while (temp != nullptr) {
        if (temp->dato.nombre == nombre) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

bool eliminarPaciente(NodoLista* &cabeza, int numHistoria) {
    if (cabeza == nullptr) return false;
    
    if (cabeza->dato.numHistoria == numHistoria) {
        NodoLista* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }
    
    NodoLista* temp = cabeza;
    while (temp->siguiente != nullptr) {
        if (temp->siguiente->dato.numHistoria == numHistoria) {
            NodoLista* eliminar = temp->siguiente;
            temp->siguiente = eliminar->siguiente;
            delete eliminar;
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

void mostrarPacientes(NodoLista* cabeza) {
    if (cabeza == nullptr) {
        cout << "\nNo hay pacientes registrados.\n";
        return;
    }
    
    cout << "\n========== LISTA DE PACIENTES ==========\n";
    NodoLista* temp = cabeza;
    while (temp != nullptr) {
        cout << temp->dato << endl;  // Usa sobrecarga de <<
        temp = temp->siguiente;
    }
}

// ==================== FUNCIONES DE COLA DE CITAS ====================
void inicializarCola(Cola &c) {
    c.front = nullptr;
    c.rear = nullptr;
}

bool colaVacia(const Cola &c) {
    return c.front == nullptr;
}

void encolarCita(Cola &c, Paciente paciente) {
    NodoCola* nuevo = new NodoCola();
    nuevo->dato = paciente;
    nuevo->siguiente = nullptr;
    
    if (colaVacia(c)) {
        c.front = c.rear = nuevo;
    } else {
        c.rear->siguiente = nuevo;
        c.rear = nuevo;
    }
}

bool desencolarCita(Cola &c, Paciente &paciente) {
    if (colaVacia(c)) {
        return false;
    }
    
    NodoCola* temp = c.front;
    paciente = temp->dato;
    c.front = c.front->siguiente;
    
    if (c.front == nullptr) {
        c.rear = nullptr;
    }
    
    delete temp;
    return true;
}

void mostrarCitas(const Cola &c) {
    if (colaVacia(c)) {
        cout << "\nNo hay citas pendientes.\n";
        return;
    }
    
    cout << "\n========== CITAS PENDIENTES ==========\n";
    NodoCola* temp = c.front;
    int pos = 1;
    while (temp != nullptr) {
        cout << pos++ << ". " << temp->dato.nombre 
             << " (Historia: " << temp->dato.numHistoria << ")" << endl;
        temp = temp->siguiente;
    }
}

// ==================== FUNCIONES DE PILA DE HISTORIAL ====================
void inicializarPila(Pila &p) {
    p.tope = nullptr;
}

bool pilaVacia(const Pila &p) {
    return p.tope == nullptr;
}

void apilar(Pila &p, Paciente paciente) {
    NodoPila* nuevo = new NodoPila();
    nuevo->dato = paciente;
    nuevo->siguiente = p.tope;
    p.tope = nuevo;
}

bool desapilar(Pila &p, Paciente &paciente) {
    if (pilaVacia(p)) {
        return false;
    }
    
    NodoPila* temp = p.tope;
    paciente = temp->dato;
    p.tope = p.tope->siguiente;
    delete temp;
    return true;
}

void mostrarHistorial(const Pila &p) {
    if (pilaVacia(p)) {
        cout << "\nNo hay atenciones en el historial.\n";
        return;
    }
    
    cout << "\n========== HISTORIAL DE ATENCIONES ==========\n";
    NodoPila* temp = p.tope;
    int pos = 1;
    while (temp != nullptr) {
        cout << pos++ << ". " << temp->dato.nombre 
             << " - " << temp->dato.diagnostico 
             << " (Historia: " << temp->dato.numHistoria << ")" << endl;
        temp = temp->siguiente;
    }
}

// ==================== TEMPLATES ====================

// Template para encontrar el máximo entre dos valores
template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

// Template para encontrar el mínimo entre dos valores
template <typename T>
T minimo(T a, T b) {
    return (a < b) ? a : b;
}

// Template para intercambiar dos valores
template <typename T>
void intercambiar(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template para contar elementos en una lista genérica
template <typename NodoTipo>
int contarNodos(NodoTipo* cabeza) {
    if (cabeza == nullptr) return 0;
    return 1 + contarNodos(cabeza->siguiente);
}

// Template para buscar un valor en un arreglo
template <typename T>
int buscarEnArreglo(T arr[], int tamanio, T valor) {
    for (int i = 0; i < tamanio; i++) {
        if (arr[i] == valor) return i;
    }
    return -1;
}

// ==================== FUNCIONES RECURSIVAS ====================
double calcularPromedioEdadRecursivo(NodoPila* nodo, int suma, int cont) {
    if (nodo == nullptr) {
        return cont > 0 ? (double)suma / cont : 0.0;
    }
    return calcularPromedioEdadRecursivo(nodo->siguiente, suma + nodo->dato.edad, cont + 1);
}

int contarDiagnosticoRecursivo(NodoLista* nodo, string diagnostico) {
    if (nodo == nullptr) return 0;
    
    int count = (nodo->dato.diagnostico == diagnostico) ? 1 : 0;
    return count + contarDiagnosticoRecursivo(nodo->siguiente, diagnostico);
}

// ==================== SOBRECARGA DE OPERADORES ====================

// Sobrecarga del operador < (compara por edad)
bool operator<(const Paciente &p1, const Paciente &p2) {
    return p1.edad < p2.edad;
}

// Sobrecarga del operador > (compara por edad)
bool operator>(const Paciente &p1, const Paciente &p2) {
    return p1.edad > p2.edad;
}

// Sobrecarga del operador == (compara por prioridad)
bool operator==(const Paciente &p1, const Paciente &p2) {
    return p1.prioridad == p2.prioridad;
}

// Sobrecarga del operador << para imprimir paciente
ostream& operator<<(ostream &os, const Paciente &p) {
    os << "Historia: " << p.numHistoria << " | ";
    os << "Nombre: " << p.nombre << " | ";
    os << "Edad: " << p.edad << " | ";
    os << "Diagnostico: " << p.diagnostico << " | ";
    os << "Prioridad: ";
    if (p.prioridad == 1) os << "ALTA";
    else if (p.prioridad == 2) os << "MEDIA";
    else os << "BAJA";
    return os;
}

// ==================== FUNCIÓN MENÚ ====================
void mostrarMenu() {
    cout << "\n";
    cout << "================================================\n";
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

// ==================== FUNCIÓN PRINCIPAL ====================
int main() {
    NodoLista* listaPacientes = nullptr;
    Cola colaCitas;
    Pila pilaHistorial;
    
    inicializarLista(listaPacientes);
    inicializarCola(colaCitas);
    inicializarPila(pilaHistorial);
    
    int opcion;
    int contadorHistorias = 1000;
    
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
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
                cout << "\nPaciente registrado exitosamente. Historia Clinica: " << contadorHistorias << endl;
                break;
            }
            
            case 2: {
                int numHistoria;
                cout << "\nNumero de historia clinica: ";
                cin >> numHistoria;
                
                NodoLista* p = buscarPorHistoria(listaPacientes, numHistoria);
                if (p != nullptr) {
                    cout << "\n--- PACIENTE ENCONTRADO ---\n";
                    cout << p->dato << endl;  // Usa sobrecarga de <<
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
                    cout << p->dato << endl;  // Usa sobrecarga de <<
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
                    cout << "Cita devuelta a la cola.\n";
                } else {
                    cout << "\nNo hay atenciones para deshacer.\n";
                }
                break;
            }
            
            case 11: {
                if (!pilaVacia(pilaHistorial)) {
                    double promedio = calcularPromedioEdadRecursivo(pilaHistorial.tope, 0, 0);
                    cout << "\nPromedio de edad de pacientes atendidos: " << promedio << " años\n";
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
                cout << "\nCantidad de pacientes con '" << diagnostico << "': " << count << endl;
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
                    cout << "\n--- COMPARACION ---\n";
                    
                    // Usa sobrecarga de operadores <, >, ==
                    if (p1->dato < p2->dato) {
                        cout << p1->dato.nombre << " es mas joven que " << p2->dato.nombre << endl;
                    } else if (p1->dato > p2->dato) {
                        cout << p1->dato.nombre << " es mayor que " << p2->dato.nombre << endl;
                    } else {
                        cout << "Ambos tienen la misma edad\n";
                    }
                    
                    if (p1->dato == p2->dato) {
                        cout << "Ambos tienen la misma prioridad medica\n";
                    } else {
                        cout << "Tienen diferente prioridad medica\n";
                    }
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
    
    // Liberar memoria de la lista
    while (listaPacientes != nullptr) {
        NodoLista* temp = listaPacientes;
        listaPacientes = listaPacientes->siguiente;
        delete temp;
    }
    
    // Liberar memoria de la cola
    while (!colaVacia(colaCitas)) {
        Paciente temp;
        desencolarCita(colaCitas, temp);
    }
    
    // Liberar memoria de la pila
    while (!pilaVacia(pilaHistorial)) {
        Paciente temp;
        desapilar(pilaHistorial, temp);
    }
    
    return 0;
}