Listadoble::ListaDoble(){
        cabeza = nullptr;
        fin = nullptr;
}
ListaDoble::~ListaDoble(){
        if(!cabeza) return;
        Nodo* actual = cabeza->sig;
        while(actual = cabeza){
                Nodo* tmp = actual;
                actual = actual->sig;
                delete tmp;
        }
        delete cabeza
}
void ListaDoble::insertarFinal(const Paciente<>string, int, string, int){
	Nodo* nuevo = new nodo(p);
	if(!cabeza){
		cabeza = fin = nuevo;
		cabeza->sig = cabeza -> ant = cabeza;
	} else {
		fin->sig = nuevo;
		nuevo -> ant = fin;
		nuevo -> sig = cabeza;
		nuevo -> ant = nuevo;
		fin = nuevo;
	}
}
void ListaDoble::imprimir() const{
	if(!cabeza)return;
		Nodo* actual = cabeza;
		do{
			cout<< actual->info << endl;
			actual = actual->sig;
		} while (actual != cabeza);
}
int ListaDoble::cantidad() const{
	if(!cabeza) return 0;
	int cont = 0;
	Nodo* actual = cabeza;
	do{
		cont++;
		actual = actual->sig;
	} while( actual != cabeza);
	return cont;
}
