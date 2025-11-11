#include "../include/Utilidades.h"

double calcularPromedioEdadRecursivo(NodoPila *nodo, int suma, int cont)
{
    if (!nodo)
        return cont > 0 ? (double)suma / cont : 0.0;
    return calcularPromedioEdadRecursivo(nodo->siguiente, suma + nodo->dato.edad, cont + 1);
}

int contarDiagnosticoRecursivo(NodoLista *nodo, string diagnostico)
{
    if (!nodo)
        return 0;
    int count = (nodo->dato.diagnostico == diagnostico) ? 1 : 0;
    return count + contarDiagnosticoRecursivo(nodo->siguiente, diagnostico);
}
