  GNU nano 8.3                                       moduloPacientes.h                                        Modified
        #pragma once
#include <iostream>

class ListaCircular {
        private:
                class Nodo{
                        public :
                                int info:
                                Nodo *sig;
                                Nodo *ant:
                };
                Nodo *raiz;
        public:
                ListCircular();
                ~listaCircular();
                void insertarPrimero(int x);
                void insertarUltimo(int x);
                bool vacia();
                void imprimir();
                int cantidad();
                void borrar(int pos);
};
  GNU nano 8.3                                      moduloPacientes.tpp
        }
}

void ListaCircular::insertarPrimero(int x){
        Nodo *nuevo = new Nodo();
        nuevo->info = x;
        if (raiz == NULL){
                nuevo->sig = nuevo;
                nuevo->ant = nuevo;
                raiz = nuevo;
        } else {
                Nodo *ultimo = raiz->ant;
                nuevo->sig = raiz;
                nuevo->ant = ultimo;
                raiz->ant = nuevo;
                ultimo->sig = nuevo;
                raiz = nuevo;
        }
}

void ListaCircular::insertarUltimo(int x){
        Nodo *nuevo = new Nodo();
        nuevo->info = x;
        if (raiz == NULL)
}
