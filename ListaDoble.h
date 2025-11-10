#pragma once
#include <iostream>
#include <Paciente.h>
using namespace std;

class ListaDoble{
	private:
		class Nodo{
			public:
				Paciente<string, int, string, int> info;
				Nodo* sig;
				Nodo* ant;
				Nodo(const Paciente<string, int, string, int>& p) : info(p), sig(nullptr), ant(nullptr){}
		};
		Nodo* cabeza;
		Nodo* fin;
	public:
		ListaDoble();
		~ListaDoble();
		void insertarFinal(const Paciente<string, int, string, int>& p);
		void imprimir() const;
		int cantidad() const;
};
#include "ListaDoble.cpp"

