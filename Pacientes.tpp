template<class N, class E, class D, class H>
        Paciente<N, E, D, H>::Paciente() : nombre(N()), edad(E()), diagnostico(D()), historia(H()){}
template<class N, class E, class D, class H>                
	Paciente<N, E, D, H>::Paciente(N n, E e, D d, H h): nombre(n), edad(e), diagnostico(d), historia(h){}
template<class N, class E, class D, class H>
	N Paciente<N,E,D,H>::getNombre() const {
                return nombre;
        }
template<class N, class E, class D, class H>
        E Paciente<N,E,D,H>::getEdad() const{ return edad;}
template<class N, class E, class D, class H>        
	D Paciente<N,E,D,H>::getDiagnostico() const { return diagnostico; }
template<class N, class E, class D, class H>
	H Paciente<N,E,D,H>::getHistoria() const { return historia; }
template<class N, class E, class D, class H>
        bool Paciente<N,E,D,H>::operator<(const Paciente& otro) const{
                return this->edad < otro.edad;
        }
template<class N, class E, class D, class H>
        bool Paciente<N,E,D,H>::operator>(const Paciente& otro) const{
                return this->edad > otro.edad;
        }
template<class N, class E, class D, class H>
        bool Paciente<N,E,D,H>::operator==(const Paciente& otro) const{
                return this->edad == otro.edad;
        }
