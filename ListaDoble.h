#pragma once
#include <iostream>
#include "Pacientes.h"
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
		Paciente<string, int, string, int>* buscarNombre(const string& nom);
		Paciente<string, int, string, int>* buscarHistoria(int h);
		bool eliminar(int historia);
		double promedioEdad() const;
		int contarDiagnostico(const string& diag) const;
		Paciente<string, int, string, int>* pacienteMasJoven() const;
};
#include "ListaDoble.cpp"

