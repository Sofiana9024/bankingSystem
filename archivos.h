void Escritura(){
	struct Usuario *aux = uprimero;
	ofstream archivo("usuario.xls");
	while(aux != NULL){
		archivo<<aux->usuario<<"\t";
		archivo<<aux->pasword<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->id<<"\t";
		archivo<<aux->rol<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->apellido<<"\t";
		archivo<<aux->fnac<<"\t";
		archivo<<aux->direccion<<endl;
		aux = aux->sig;
	}
	archivo.close();
	
	struct Cliente *auxiliar = cprimero;
	ofstream arch("cliente.xls");
	while(auxiliar != NULL){
		arch<<auxiliar->id<<"\t";
		arch<<auxiliar->estado<<"\t";
		arch<<auxiliar->nombre<<"\t";
		arch<<auxiliar->apellido<<"\t";
		arch<<auxiliar->fnac<<"\t";
		arch<<auxiliar->direccion<<endl;
		auxiliar = auxiliar->sig;
	}
	arch.close();
	
	struct Tasas *temp = tprimero;
	ofstream archarch("tasas.xls");
	while(temp != NULL){
		archarch<<temp->tipo<<"\t";
		archarch<<temp->anualidad<<"\t";
		archarch<<temp->tasa<<"\t";
		archarch<<temp->nombre<<endl;
		temp = temp->sig;
	}
	archarch.close();
}

void Lectura(){
	ifstream arch("usuario.xls");
	string linea, c;
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch, linea)){
			struct Usuario *nuevo = new Usuario;
			stringstream lee(linea);
			
			lee>>nuevo->usuario;
			getline(lee, c, '\t');
			lee>>nuevo->pasword;
			getline(lee, c, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			lee>>nuevo->id;
			getline(lee, c, '\t');
			lee>>nuevo->rol;
			getline(lee, c, '\t');
			getline(lee, nuevo->nombre, '\t');
			getline(lee, nuevo->apellido, '\t');
			getline(lee, nuevo->fnac, '\t');
			getline(lee, nuevo->direccion, '\n');
			
			nuevo->sig = NULL;
			if(uprimero == NULL){
				uprimero = nuevo;
				uultimo = nuevo;
			}else{
				nuevo->sig = uprimero;
				uprimero = nuevo;
			}
		}
	}
	arch.close();
	
	ifstream archivo("cliente.xls");
	if(archivo.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(archivo, linea)){
			struct Cliente *nuevo = new Cliente;
			stringstream lee(linea);
			
			lee>>nuevo->id;
			getline(lee, c, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			getline(lee, nuevo->nombre, '\t');
			getline(lee, nuevo->apellido, '\t');
			getline(lee, nuevo->fnac, '\t');
			getline(lee, nuevo->direccion, '\n');
			nuevo->sig = NULL;
			if(cprimero == NULL){
				cprimero = nuevo;
				cultimo = nuevo;
			}else{
				nuevo->sig = cprimero;
				cprimero = nuevo;
			}
		}
	}
	archivo.close();
	
	
	ifstream archarch("tasas.xls");
	if(archarch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(archarch, linea)){
			struct Tasas *temp = new Tasas;
			stringstream lee(linea);
			
			lee>>temp->tipo;
			getline(lee, c, '\t');
			lee>>temp->anualidad;
			getline(lee, c, '\t');
			lee>>temp->tasa;
			getline(lee, c, '\t');
			getline(lee, temp->nombre, '\n');
			temp->sig = NULL;
			if(tprimero == NULL){
				tprimero = temp;
				tultimo = temp;
			}else{
				temp->sig = tprimero;
				tprimero = temp;
			}
		}
	}
	archarch.close();
}
