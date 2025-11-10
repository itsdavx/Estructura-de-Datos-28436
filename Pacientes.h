#pragma once
#include <iostream>
#include <string>

template<class N, class E, class D, class H>
class Paciente{
	private: 
		N nombre;
		E edad;
		D diagnostico;
		H historia;
	public:
		Paciente();
		Paciente(N n, E e, D d, H h);
	N getNombre() const;
	E getEdad() const;
	D getDiagnostico() const;
	H getHistoria() const;

	friend std::ostream& operator<<(std::ostream& os, const Paciente& p){
                os<< " Nombre " << p.nombre
                  << ", Edad " << p.edad
                  << ", Diagnostico" << p.diagnostico
                  << ", Historia" << p.historia;
                return os;
        }
	bool operator<(const Paciente& otro) const;
	bool operator>(const Paciente& otro) const;
	bool operator==(const Paciente& otro) const;
};
#include "Pacientes.tpp"


