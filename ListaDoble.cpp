ListaDoble::ListaDoble(){
        cabeza = nullptr;
        fin = nullptr;
}
ListaDoble::~ListaDoble(){
        Nodo* actual = cabeza;
	while(actual){
		Nodo* tmp = actual;
		actual = actual -> sig;
		delete tmp;
	}
	cabeza = fin = nullptr;
}
void ListaDoble::insertarFinal(const Paciente<string, int, string, int>& p){
	Nodo* nuevo = new Nodo(p);
	if(!cabeza){
		cabeza = fin = nuevo;
	} else {
		fin->sig = nuevo;
		nuevo->ant = fin;
		fin = nuevo; 
	}
}
void ListaDoble::imprimir() const{
	Nodo* actual = cabeza;
	while(actual != nullptr){
		cout<< actual->info << endl;
		actual = actual->sig;
	}
}
int ListaDoble::cantidad() const{
	int cont = 0;
	Nodo* actual = cabeza;
	while(actual != nullptr){
		cont++;
		actual = actual->sig;
	}
	return cont;
}
Paciente<string, int, string, int>* ListaDoble::buscarNombre(const string& nom){
	Nodo* actual = cabeza;
	while(actual){
		if(actual->info.getNombre() == nom){
			return &(actual->info);
		}
		actual = actual->sig;
	} return nullptr;
}
Paciente<string, int, string, int>* ListaDoble::buscarHistoria(int h){
	Nodo* actual = cabeza;
	while(actual){
		if(actual->info.getHistoria()== h){
			return &(actual->info);
		} actual = actual->sig;
	} return nullptr;
}
bool ListaDoble::eliminar(int historia){
	Nodo* actual = cabeza;
	while(actual){
		if(actual->info.getHistoria() == historia){
			if(actual == cabeza){
				cabeza = cabeza ->sig;
				if(cabeza) cabeza->ant = nullptr;
			}
			if(actual == fin){
				fin = fin->ant;
				if(fin) fin->sig = nullptr;
			}
			if(actual->ant) actual->ant->sig = actual->sig;
			if(actual->sig) actual->sig->ant = actual->ant;
			delete actual;
			return true;
		}actual = actual->sig;
	} return false;
}
double ListaDoble::promedioEdad() const{
	if(!cabeza) return 0.0;
	double suma = 0;
	int cont = 0;
	Nodo* actual = cabeza;
	while(actual){
		suma += actual->info.getEdad();
		cont++;
		actual = actual->sig;
	} return cont > 0 ? suma/cont : 0;
}
int ListaDoble::contarDiagnostico(const string& diag) const{
	int cont = 0;
	Nodo* actual = cabeza;
	while(actual){
		if(actual->info.getDiagnostico() == diag) {
			cont++;
		}actual = actual->sig;
	}return cont;
}
Paciente<string, int, string,int>* ListaDoble::pacienteMasJoven() const {
	if(!cabeza) return nullptr;
	Nodo* actual = cabeza;
	Nodo* menor = cabeza;
	while(actual){
		if(actual->info <menor->info){
			menor = actual;
		} actual = actual->sig;
	}return &(menor->info);
}
