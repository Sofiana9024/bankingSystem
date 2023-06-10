void escrituraLista(){
	ListotaContrato *aux = PListota;
	
	ofstream archivo("ClientesContratos.xls");
	while(aux != NULL){
		archivo<<aux->idListota<<"\n";
		aux = aux->sig;
	}
	
	archivo.close();
}

void lecturaLista(){
	ListotaContrato *nuevo = NULL;
	
	ifstream arch("ClientesContratos.xls");
	string linea, c;
	
	if(arch.fail())cerr<<"No se encuentra ninguna lista(contrato)"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new ListotaContrato;
			stringstream lee(linea);
			
			lee>>nuevo->idListota;
			getline(lee, c, '\n');
			
			nuevo->lista = archivoLectura(nuevo->idListota);
			
			nuevo->sig = NULL;
			
			if(PListota == NULL){
				PListota = nuevo;
				UListota = nuevo;
			}else{
				nuevo->sig = PListota;
				PListota = nuevo;
			}
		}
	}
	arch.close();
}
