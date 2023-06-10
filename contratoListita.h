int ID_Contrato(){
	struct Cliente *aux = cprimero;
	system("cls");	
	int alto=20, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("CONTRATO ");
		
	int id = validaEntero2("Ingrese el ID del cliente para generarle el contrato: ",pxci+20,pyci+2);
	do{
		aux = cprimero;
		while(aux != NULL){
			if(id == aux->id){
				break;
			}
			aux = aux->sig;
		}if(aux == NULL){
			id = validaEntero2("ID ingresado no corresponde con ningun cliente, ingrese otro: ",pxci+20,pyci+6);
		}
	}while(aux == NULL);
	return id;	
}

Contrato *registro(struct Contrato *temporal){
	int igual, cont, bandera = 0, id;
	Contrato *nuevo = new Contrato;
	
	struct Contrato *temp = temporal;
	
	system("cls");
	int alto=30, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("REGISTRO CONTRATO ");
	if(temporal == NULL){
		
	}else{
			system("cls");
		while(temp != NULL){
			if(id == temp->id_cliente){
				cout<<"No se puede realizar el contrato, porque el ID ya existe para este cliente";
				id = validaEntero2("Ingresa ID que no se repita: ",pxci+30,pyci+2);
				temp = temporal;
			}else{
				temp = temp->sig;
			}
		}
	}
	id = validaEntero2("Ingresa el ID del contrato (listita): ",pxci+30,pyci+2);
		
	nuevo->id_cliente = id;
	gotoxy(pxci+30,pyci+6);
	cout << "Fecha: ";
	gotoxy(pxci+34,pyci+8);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->fecha;
	SetConsoleTextAttribute(hCon, color_letr);
	nuevo->prenda = "x";
	do{
		nuevo->tipoContrato = validaEntero2("Ingrese 0. Para contrato AHORRADOR, 1. DEUDOR y 2. HIPOTECARIO: ",pxci+20,pyci+10);	
	}while(nuevo->tipoContrato != 0 && nuevo->tipoContrato != 1 && nuevo->tipoContrato != 2);
	
	nuevo->estado = 1;

	if(nuevo->tipoContrato == 0){
		nuevo->cantidad = validaFlotante2("Ingrese la cantidad inicial a ahorrar: ",pxci+30,pyci+14);
	}else if(nuevo->tipoContrato == 1){
		nuevo->cantidad = validaFlotante2("Ingrese la cantidad solicitada: ",pxci+30,pyci+14);
		nuevo->cantidad = nuevo->cantidad * -1;
	}else{
		gotoxy(pxci+30,pyci+14);
		cout<<"Ingrese la prenda en avaluo: ";
		gotoxy(pxci+35,pyci+16);SetConsoleTextAttribute(hCon, color_frase);
		cin>>nuevo->prenda;
		nuevo->cantidad = validaFlotante2("Ingrese la cantidad que el banco tras examinar la prenda en avaluo: ",pxci+30,pyci+18);
		nuevo->cantidad = nuevo->cantidad * -1;
		SetConsoleTextAttribute(hCon, color_letr);
	}
	mostrar_tasas();
	
	struct Tasas *aux = tprimero;
		string nueva_tasa;	
		do{
			system("cls");
			alto=15;
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("REGISTRO CONTRATO ");
			gotoxy(pxci+5,pyci+2); 
			cout<<"Ingrese el nombre de una Tasa de interes valida (respetando el tipo de contrato actual): ";
			gotoxy(pxci+9,pyci+4);SetConsoleTextAttribute(hCon, color_frase);
			cin>>nueva_tasa;
			SetConsoleTextAttribute(hCon, color_letr);
			aux = tprimero;
			while(aux != NULL){
				igual = 9;
				igual = nueva_tasa.compare(aux->nombre);
				if(igual == 0 && (nuevo->tipoContrato == aux->tipo)){
					nuevo->sub_tipo = nueva_tasa;	
					nuevo->tipoContrato = aux->tipo;
					cont = 1;
					break;
				}	
				aux = aux->sig;
			}
		}while(cont == 0);
		nuevo->saldof = (nuevo->cantidad + (nuevo->cantidad * aux->tasa *0.1));
	if(aux->tipo == 0){
		nuevo->tipoCliente = 1;
	}else{
		nuevo->tipoCliente = 2;
	}
	nuevo->sig = NULL;	
	return nuevo;
}

void agregarInicio(struct Contrato *prueba){							
	struct Contrato *nuevo = registro(prueba);
	
	if(primero == NULL){
		nuevo->sig = NULL;
		primero = nuevo;
		ultimo = nuevo;
	}else{
		nuevo->sig=primero;
		primero=nuevo;
	}
}

void salida(){
	gotoxy(pxci+3,pyci+5);SetConsoleTextAttribute(hCon, color_titulo);
	cout<<"CONTRATO";
	gotoxy(pxci+3,pyci+7);
	cout<<"Id Contrato";
	gotoxy(pxci+19,pyci+7);
	cout<<"Fecha";
	gotoxy(pxci+30,pyci+7);
	cout<<"Estado";
	gotoxy(pxci+44,pyci+7);
	cout<<"Tipo";
	gotoxy(pxci+56,pyci+7);
	cout<<"Cantidad";
	gotoxy(pxci+68,pyci+7);
	cout<<"Saldo Final";
	gotoxy(pxci+85,pyci+7);
	cout<<"Subtipo";
	SetConsoleTextAttribute(hCon, color_letr);
}

void mini(struct Contrato *auxiliar, int y){
	gotoxy(pxci+5,y);
	cout<<auxiliar->id_cliente;
	gotoxy(pxci+17,y);
	cout<<auxiliar->fecha;
	
	if(auxiliar->estado == 0){
		gotoxy(pxci+30,y);
		cout<<"Cancelado";
	}else{
		gotoxy(pxci+30,y);
		cout<<"Activo";
	}
	
	if(auxiliar->tipoContrato == 0){
		gotoxy(pxci+42,y);
		cout<<"Ahorrador";
	}else if(auxiliar->tipoContrato == 1){
		gotoxy(pxci+42,y);
		cout<<"Deudor";
	}else{
		gotoxy(pxci+42,y);
		cout<<"Hipotecario";
	}

	gotoxy(pxci+56,y);	
	cout<<auxiliar->cantidad;
	gotoxy(pxci+68,y);
	cout<<auxiliar->saldof;
	gotoxy(pxci+85,y);
	cout<<auxiliar->sub_tipo;
}

void salida2(){
	cout<<endl;
	printf("\t\t\t\t\t\t\t");
	cout<<"Id Cliente"<<setw(15);
	cout<<"Fecha"<<setw(15);
	cout<<"Estado"<<setw(15);
	cout<<"Tipo"<<setw(15);
	cout<<"Cantidad"<<setw(15);
	cout<<"Saldo Final"<<setw(15);
	cout<<"Sub Tipo"<<endl;
}

void mini2(struct Contrato *auxiliar){	
	printf("\t\t\t\t\t\t\t");
	cout<<auxiliar->id_cliente<<setw(25);
	cout<<auxiliar->fecha<<setw(15); 

	if(auxiliar->estado == 0){
		cout<<"Cancelado"<<setw(18);
	}else{
		cout<<"Activo"<<setw(18);
	}
	
	if(auxiliar->tipoContrato == 0){
		cout<<"Ahorrador"<<setw(10);
	}else if(auxiliar->tipoContrato == 1){
		cout<<"Deudor"<<setw(10);
	}else{
		cout<<"Hipotecario"<<setw(10);
	}
	
	cout<<auxiliar->cantidad<<setw(15);
	cout<<auxiliar->saldof<<setw(15);
	cout<<auxiliar->sub_tipo<<endl;
}

void mostrar_contrato2(struct Contrato *primero, int op, int tipo) {					
	struct Contrato *auxiliar = NULL;
	auxiliar =  primero;
	if(op==1){
		salida2();
		while (auxiliar!=NULL) {	
		mini2(auxiliar);
		auxiliar = auxiliar->sig;
	}}
	else if(op == 2){	
		salida2();
		while (auxiliar!=NULL) {
		if(auxiliar->tipoContrato == tipo){	
			mini2(auxiliar);
			ultimo = auxiliar;
		}	
		auxiliar = auxiliar->sig;
	}
	}else if(op == 3){	
		salida2();
		while (auxiliar!=NULL) {
		if(auxiliar->tipoCliente == tipo){	
			mini2(auxiliar);
			ultimo = auxiliar;
		}	
		auxiliar = auxiliar->sig;
		}
	}else if(op == 4){
		salida2();
		while (auxiliar!=NULL) {
		if(auxiliar->estado == tipo){	
			mini2(auxiliar);
			ultimo = auxiliar;
		}	
		auxiliar = auxiliar->sig;
		}
	}	
}


void mostrar_contrato(struct Contrato *primero, int op, int tipo) {					
	struct Contrato *auxiliar = NULL;
	auxiliar =  primero;
	int y=pyci+9, x1=0;
	if(op==1){
		y=pyci+9;
		salida();
		while (auxiliar!=NULL) {	
			mini(auxiliar,y);
			auxiliar = auxiliar->sig;
			y+=2;
		}
	}
	else if(op == 2){
		salida();				
		y=pyci+9;
		while (auxiliar!=NULL) {
			
			if(auxiliar->tipoContrato == tipo){
				mini(auxiliar,y);
//				ultimo = auxiliar;
				y+=2;
			}
			auxiliar = auxiliar->sig;
			y+=2;
		}
	}else if(op == 3){	
		y=pyci+9;
		salida();
		while (auxiliar!=NULL) {
			if(auxiliar->tipoCliente == tipo){	
				mini(auxiliar,y);
				ultimo = auxiliar;
				y+=2;
			}	
			auxiliar = auxiliar->sig;
			y+=2;
		}
	}else if(op == 4){
		y=pyci+9;
		salida();
		while (auxiliar!=NULL) {
			if(auxiliar->estado == tipo){	
				mini(auxiliar,y);
				ultimo = auxiliar;	
				y+=2;
			}	
			auxiliar = auxiliar->sig;
			y+=2;
		}
	}	
}

void mostrarListotaC(){ 
	struct ListotaContrato *aux = PListota;
	
	system("cls");
	int alto=30, ancho=110;
	cuadrito_presentacion(alto,ancho);
	gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
	printf("CONSULTA CONTRATOS ");
	
	gotoxy(pxci+38,pyci+2); 
	printf("1. Por id Cliente");
	gotoxy(pxci+38,pyci+4);
	printf("2. Tipos de contratos");
	gotoxy(pxci+38,pyci+6);
	printf("3. Tipo de cliente");
	gotoxy(pxci+38,pyci+8);
	printf("4.Por estado de contrato");
	int op = validaEntero2("Ingrese su opcion: ",pxci+38,pyci+10);
	mostrar_cliente();
	getch();
	
	aux = PListota;
	if(op == 1){
		system("cls");
		cuadrito_presentacion(alto,ancho);
		gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
		printf("CONSULTA POR ID ");
		int id = validaEntero2("Ingrese el ID del cliente: ",pxci+38,pyci+2);
		while(aux!=NULL){
			if(id == aux->idListota){
				mostrar_contrato(aux->lista, op, id);
				return;
			}  
			aux = aux->sig;
		}
		gotoxy(pxci+38,pyci+6);
		cout<<"No existe el ID ingresado";
		return;
	}	
	
	if(op == 2){
		do{
			system("cls");
			cuadrito_presentacion(alto,ancho);
			gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
			printf("CONSULTA POR TIPO DE CONTRATO ");
			tipoContr = validaEntero2("Ingrese 0.Para consultar ahorrador, 1.Deudor y 2. Hipotecario: ",pxci+8,pyci+2);	
		}while(tipoContr != 0 && tipoContr != 1 && tipoContr != 2);
	}else if(op == 3){
		do{
			system("cls");
			cuadrito_presentacion(alto,ancho);
			gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
			printf("CONSULTA POR TIPO DE CLIENTE ");
			tipoContr = validaEntero2("Ingrese 1.Para cliente ahorrador o 2.Para deudor : ",pxci+8,pyci+2);	
		}while(tipoContr != 1 && tipoContr != 2);
	}else if(op == 4){
		do{
			system("cls");
			cuadrito_presentacion(alto,ancho);
			gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
			printf("CONSULTA POR ESTADO ");
			tipoContr = validaEntero2("Ingrese 0. Para contratos cancelados y 1. Para contratos activos: ",pxci+8,pyci+2);
		}while(tipoContr != 0 && tipoContr != 1);
	}
	while(aux!=NULL){
		mostrar_contrato2(aux->lista, op, tipoContr);  
		aux = aux->sig;
	}
}

void archivoEscritura(Contrato *primero, int id){
	Contrato *aux = primero;
	char arch[20];
	itoa(id,arch,10);
	strcat(arch,".xls");
	
	ofstream archivo(arch);
	
	while(aux!=NULL){
		archivo<<aux->id_cliente<<"\t";
		archivo<<aux->sub_tipo<<"\t";
		archivo<<aux->fecha<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->tipoContrato<<"\t";
		archivo<<aux->cantidad<<"\t";
		archivo<<aux->prenda<<"\t";
		archivo<<aux->tipoCliente<<"\n";
		ultimo = aux;
		aux = aux->sig;
	}
	archivo.close();
}

Contrato *archivoLectura(int id){
	Contrato *primero = NULL;
	Contrato *ultimo = NULL;
	Contrato *nuevo = NULL;
	
	char archivo[20];
	itoa(id,archivo,10);
	strcat(archivo,".xls");
	
	ifstream arch(archivo);
	string linea, c;
	
	if(arch.fail())	cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch, linea)){   //vamos obteniendo linea por linea y lo guardamos en la variable linea
			nuevo = new Contrato; 
			stringstream lee(linea); //creamos variable tipo stringstream lee y le almacenamos lo que tiene linea?
			
			lee>>nuevo->id_cliente;       //si no jala cambiar todos a esto
			getline(lee, c, '\t');
			getline(lee, nuevo->sub_tipo, '\t');
			getline(lee, nuevo->fecha, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			lee>>nuevo->tipoContrato;
			getline(lee, c, '\t');
			lee>>nuevo->cantidad;
			getline(lee, c, '\t');
			getline(lee, nuevo->prenda, '\t');
			lee>>nuevo->tipoCliente;
			getline(lee, c, '\n');			
			nuevo->sig = NULL;
			
			if(primero == NULL){
				primero = nuevo;
				ultimo = nuevo;
			}else{
				ultimo->sig = nuevo;
				ultimo = nuevo;
			}
		}
	}
	arch.close();
	return primero;
	
}

void agregarListotaC(){
	struct ListotaContrato *urg = PListota;
	struct Contrato *prueba= NULL, *mandar;
	int sigue = 1, bandera = 0;
	mostrar_cliente();
	getch();
	int id = ID_Contrato();
	
	
	primero = NULL;
	ultimo = NULL;
	
	while(urg != NULL){
		if(id == urg->idListota){
			bandera = 1;
			primero = urg->lista;
			mandar = urg->lista;
			break;
		}
		urg = urg->sig; 
	}
	
	while(sigue == 1){
		system("cls");	
		int alto=15, ancho=100;
		cuadrito_presentacion(alto,ancho);
		SetConsoleTextAttribute(hCon, color_letr);
		gotoxy(pxci,pyci);
		if(bandera == 0){
			mandar = NULL;
		}
		agregarInicio(mandar);
		sigue = validaEntero2("1 - Para agregar otro Contrato: ",pxci+30,pyci+9);//nodito
	}

	if(bandera == 1){
		urg->lista = primero;
		archivoEscritura(primero, urg->idListota);
	}	
	if(bandera == 0){
		ListotaContrato *nuevo = new ListotaContrato;
		nuevo->sig = NULL;
		nuevo->idListota = id;
		if(PListota == NULL){
			PListota = nuevo;
			UListota = nuevo;
		}else{
			nuevo->sig = PListota;
			PListota = nuevo;
		}
		nuevo->lista = primero;	
		archivoEscritura(primero, nuevo->idListota);	
	}
}

void modificarContrato(){	
	struct ListotaContrato *aux = PListota;
	struct ListotaContrato *funciona = PListota;
	struct Contrato *listita;
	int igual = 9;
	system("cls");
	int alto=35, ancho=100;
	int y=pyci, x=pxci;

	mostrar_cliente();
	getch();	
	system("cls");
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("MODIFICAR CONTRATO ");
	int id = validaEntero2("Ingrese el ID del CLIENTE que se le modificará contrato: ",pxci+20,pyci+2), cont = 0;	//(listota)
	while(funciona != NULL){	
		if(id == funciona->idListota){//AQUI
			mostrar_contrato(funciona->lista, 1, funciona->idListota);
			getch();
			do{
				listita = funciona->lista;
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("MODIFICAR CONTRATO ");
				int id_contrato = validaEntero2("Ingrese el ID del CONTRATO a modificar: ",pxci+30,pyci+2);		//(listita)
				while(listita != NULL){
					if(id_contrato == listita->id_cliente){
						break;
					}
					listita = listita->sig;
				}
			}while(listita == NULL);
			break;
		}
		funciona = funciona->sig;
	}
	if(funciona == NULL){
		cout<<"ID ingresado no corresponde con ningun contrato";
		return;
	}
	gotoxy(pxci+38,pyci+6);
	printf("1. Modificar Tasa de interés");
	gotoxy(pxci+38,pyci+8);
	printf("2. Dar de baja contrato");
	gotoxy(pxci+38,pyci+10);
	printf("3. Modificar cantidad inicial");
	int op = validaEntero2("4. Modificar fecha: ",pxci+38,pyci+12);
	if(op == 1){
		struct Tasas *aux = tprimero;
		string nueva_tasa;	
		cout<<"Tasas disponibles a modificar: "<<endl;
		mostrar_tasas();
		
		do{
			gotoxy(pxci+10,pyci+14);
			cout<<"Ingrese el nombre de una Tasa de interes valida (respetando el tipo de contrato actual): ";
			gotoxy(pxci+25,pyci+16);
			cin>>nueva_tasa;
			aux = tprimero;
			while(aux != NULL){
				igual = 9;
				igual = nueva_tasa.compare(aux->nombre);
				if(igual == 0 && (listita->tipoContrato == aux->tipo)){
					listita->sub_tipo = nueva_tasa;	
					listita->tipoContrato = aux->tipo;
					cont = 1;
					break;
				}	
				aux = aux->sig;
			}
		}while(cont == 0);
		listita->saldof = (listita->cantidad + (listita->cantidad * aux->tasa *0.1));
	}else if(op == 2){
		if(listita->saldof < 0){
			gotoxy(pxci+20,pyci+16);
			cout<<"Contrato no se puede dar de baja porque se tiene una deuda no pagada";
		}else{
			gotoxy(pxci+30,pyci+16);
			cout<<"Contrato dado de baja con exito";
			listita->estado = 0;
		}
	}else if(op == 3){
		struct Tasas * temp = tprimero;
		float nueva_cantidad = validaFlotante2("Ingrese la nueva cantidad inicial: ",pxci+30,pyci+16);
		if(nueva_cantidad < 1){
			gotoxy(pxci+30,pyci+20);
			cout<<"Cantidad inicial muy pequeña, necesitas mas dinero: ";
			return;
		}
		while(temp != NULL){
			igual = 9; 
			igual = listita->sub_tipo.compare(temp->nombre);
			if(igual == 0){
				if(temp->tipo == 0){
					
				}else{
					nueva_cantidad = nueva_cantidad * -1;
				}
				break;
			}temp = temp->sig;
		}	
		listita->cantidad = nueva_cantidad;
		listita->saldof = (listita->cantidad + (listita->cantidad * temp->tasa *0.1));
	}else if(op == 4){
		string fecha;
		gotoxy(pxci+30,pyci+16);
		cout<<"Ingrese la nueva fecha";
		gotoxy(pxci+35,pyci+18);SetConsoleTextAttribute(hCon, color_frase);
		cin>>fecha;
		listita->fecha = fecha;
		SetConsoleTextAttribute(hCon, color_letr);
	}else{
		gotoxy(pxci+38,pyci+18);
		cout<<"Opcion ingresada no valida";
	}
	archivoEscritura(funciona->lista ,funciona->idListota);
}

void llenadoTasas(struct Contrato *lista){	
	struct Tasas *interes = tprimero;
	int igual;
	while(lista != NULL){
		igual = 9;
		interes = tprimero;
		while(interes != NULL){
			igual = lista->sub_tipo.compare(interes->nombre);
			if(igual == 0){
				lista->tipoCliente = interes->tipo;
				lista->saldof = (lista->cantidad + (lista->cantidad * interes->tasa *0.1));
				break;
			}
			interes = interes->sig;
		}
		lista = lista->sig;
	}
}

void inicioTasas(){
	struct ListotaContrato *aux = PListota;
	while(aux != NULL){
		llenadoTasas(aux->lista);
		aux = aux->sig;
	}
}

void modificarTasas(){
	struct Tasas *aux = tprimero;
	int igual=9;
	string nom_tasa;
	system("cls");
	int alto=20, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("MODIFICAR TASA ");
	gotoxy(pxci+30,pyci+2);
	cout<<"Ingrese el nombre de la tasa a modificar: ";
	gotoxy(pxci+43,pyci+4); SetConsoleTextAttribute(hCon, color_frase);
	cin>>nom_tasa;
	SetConsoleTextAttribute(hCon, color_letr);
	while(aux != NULL){
		igual = nom_tasa.compare(aux->nombre);
		if(igual == 0){
			aux->tasa = validaFlotante2("Ingresa la nueva tasa de interes: ",pxci+38,pyci+6);
			inicioTasas();
			return;
		}
		aux = aux->sig;
	}
	gotoxy(pxci+16,pyci+10);
	cout<<"Ninguna coincidencia, ingresa el nombre respetando Minusculas y Mayusculas";
}

