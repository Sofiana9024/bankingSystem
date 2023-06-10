/*REGISTROSS--------------------------------------------------------------*/
int ID(){
	struct Usuario *aux = uprimero;
	int id = 2+rand()%(500-2)+1;
	while(aux != NULL){
		if(aux->id == id){	
			id = 2+rand()%(500-2)+1;		
			aux = uprimero;			
		}else{
			aux = aux->sig;
		}
	}
	return id;
}

int IDCliente(){	
	struct Cliente *aux = cprimero;
	int id = 2+rand()%(500-2)+1;
	while(aux != NULL){
		if(aux->id == id){	
			id = 2+rand()%(500-2)+1;
			aux = cprimero;			
		}else{
			aux = aux->sig;
		}
	}
	return id;
}

int repetirUsuario(){
	int bandera = 1, nombre;
	struct Usuario *aux = uprimero; 
	nombre = validaEntero2("Ingrese el nuevo usuario: ",pxci+35,pyci+6);
	do{
		while(aux!=NULL){
			if(aux == NULL){
				bandera = 0;
				break;
			}else if(aux->usuario == nombre){
				nombre = validaEntero2("Usuario ya existe, ingrese otro: ",pxci+35,pyci+10);
				aux = uprimero;
				bandera = 1;
				break;
			}
			aux = aux->sig;
		}
	}while(bandera == 1);
	return nombre;
}


void infoPunteros(){
	struct Usuario *aux = uprimero;
	struct Cliente *client = cprimero;
	struct Tasas *tasas = tprimero;
	printf("\n\t\t\t\t\t\t\t\t\t\t");
	cout<<"Informacion de lista de Usuarios: "<<endl<<endl;
	if(uprimero == NULL){
		printf("\t\t\t\t\t\t\t\t\t\t");
		cout<<"No hay informacion que mostrar";
	}else{
		printf("\t\t\t\t\t\t\t\t\t\t");
		cout<<"Puntero actual"<<setw(20)<<"Puntero siguiente"<<endl;
		while(aux != NULL){
			printf("\t\t\t\t\t\t\t\t\t\t");
			cout<<aux<<setw(20);
			cout<<aux->sig<<endl;	
			aux = aux->sig;
		}
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t");
	cout<<"Informacion de lista de Clientes: "<<endl<<endl;
	if(cprimero == NULL){
		printf("\t\t\t\t\t\t\t\t\t\t");
		cout<<"No hay informacion que mostrar";
	}else{
		printf("\t\t\t\t\t\t\t\t\t\t");
		cout<<"Puntero actual"<<setw(20)<<"Puntero siguiente"<<endl;
		while(client != NULL){
			printf("\t\t\t\t\t\t\t\t\t\t");
			cout<<client<<setw(20);
			cout<<client->sig<<endl;	
			client = client->sig;
		}
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t");
	cout<<"Informacion de lista de Tasas de interes: "<<endl<<endl;
	if(tprimero == NULL){
		printf("\t\t\t\t\t\t\t\t\t\t");
		cout<<"No hay informacion que mostrar";
	}else{
		printf("\t\t\t\t\t\t\t\t\t\t");
		cout<<"Puntero actual"<<setw(20)<<"Puntero siguiente"<<endl;
		while(tasas != NULL){
			printf("\t\t\t\t\t\t\t\t\t\t");
			cout<<tasas<<setw(20);
			cout<<tasas->sig<<endl;	
			tasas = tasas->sig;
		}
	}
}

void Eliminar(){
	struct Usuario *aux = uprimero;
	int alto=20, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("BAJA USUARIO ");
	int id = validaEntero2("Ingrese el ID del usuario a desactivar: ",pxci+30,pyci+2);
	while(aux != NULL){
		if(aux == NULL){
			gotoxy(pxci+38,pyci+14);
			cout<<"ID ingresado no corresponde con ningun usuario";
			return;
		}else if(aux->id == id){
			aux->estado = 0;
			return;
		}
		aux = aux->sig;
	}
}

void Modificar(){	
	struct Usuario *aux = uprimero;
	int alto=20, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("MODIFICACIÓN DE USUARIO ");
	int id = validaEntero2("Ingrese el 'ID' del usuario a modificar: ",pxci+30,pyci+2), multi;
	unsigned int contra=0;
	while(aux!=NULL){
		if(aux == NULL){
			gotoxy(pxci+30,pyci+8);
			cout<<"ID ingresado no corresponde con ningun usuario";
			return;
		}else if(aux->id == id){
			break;
		}
		aux = aux->sig;
	}
	gotoxy(pxci+36,pyci+6);
	cout<<"1. Modificar nombre usuario";
	gotoxy(pxci+36,pyci+8);
	cout<<"2. Modificar contraseña";
	gotoxy(pxci+36,pyci+10);
	cout<<"3. Modificar rol";
	gotoxy(pxci+36,pyci+12);
	cout<<"4. Activar estado";
	int op = validaEntero2("Seleccione su opcion: ",pxci+36,pyci+15);
	switch(op){
		case 1:{ 
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACIÓN DE NOMBRE ");
			gotoxy(pxci+30,pyci+2);
			cout<<"Nombre de usuario actual: "<<aux->usuario;
			multi = repetirUsuario();
			aux->usuario = multi;
			break;
		}
		case 2:{
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACIÓN DE CONTRASEÑA ");
			gotoxy(pxci+37,pyci+2);
			cout<<"Contraseña actual: "<<aux->pasword;
			contra = validaEntero2("Ingrese su nueva contrasena: ",pxci+35,pyci+6);
			aux->pasword = contra;
			break;
		}
		case 3:{	
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACIÓN DE ROL ");
			gotoxy(pxci+37,pyci+2);
			cout<<"Rol actual: ";
			if(aux->rol = 0){
				cout<<"Administrador"<<endl;
			}else{
				cout<<"Ejecutivo"<<endl;
			}
			do{
				multi = validaEntero2("Ingrese 0 para Administrador y 1. Para Ejecutivo",pxci+30,pyci+4);
			}while(multi != 0 && multi != 1);
			aux->rol = multi;
			break;
		}
		case 4:{						
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACIÓN DE ESTADO ");
			gotoxy(pxci+42,pyci+6);
			cout<<"Estado: ACTIVO";
			aux->estado = 1;
			break;
		}
	}
}

Usuario* validaUsuario(){
	int bandera = 0, usuario;
	unsigned int pas;
	struct Usuario *aux = uprimero;
	
//LO BONITO
	int alto=20, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("LOG IN ");
	
	usuario = validaEntero2("Ingrese su usuario: ",pxci+38,pyci+4);
	pas = validaEntero2("Ingrese su password: ",pxci+38,pyci+8);
	
	while(aux != NULL){
		if((aux->pasword == pas) && (aux->usuario == usuario)){	//ACABAR ESTE CICLO
			bandera = 1;
			break;
		}
		else if(aux->sig == NULL){
			aux = NULL;
			break;
		}
		aux = aux->sig;
	}
//	if(bandera == 1){
//		gotoxy(pxci+20,pyci+15);
//		cout<<endl<<"Bienvenido/a, favor de seleccionar una opcion: ";
//	}
	return aux;
}


void actualizarC(){
	struct Cliente * aux = cprimero;
	string enunciado;
	int alto=15, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("MODIFICACIÓN CLIENTE ");
	int id = validaEntero2("Ingrese el 'ID' del usuario a modificar: ",pxci+25,pyci+2);
	
	while(177232){
		if(aux == NULL){
			gotoxy(pxci+25,pyci+6);
			cout<<"ID ingresado no corresponde con ningun usuario";
			return;
		}else if(aux->id == id){
			break;
		}
		aux = aux->sig;
	}
	
	system("cls");
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("MODIFICACIÓN CLIENTE ");
	
	gotoxy(pxci+38,pyci+2); 
	printf("1. Modificar nombre");
	gotoxy(pxci+38,pyci+4);
	printf("2.Modificar Apellido");
	gotoxy(pxci+38,pyci+6);
	printf("3. Modificar direccion");
	
	int op = validaEntero2("Seleccione su opcion: ",pxci+38,pyci+10);
	switch(op){
		case 1:{ 
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACIÓN NOMBRE ");   
			gotoxy(pxci+30,pyci+2);
			cout<<"Nombre de cliente actual: "<<aux->nombre;
			gotoxy(pxci+38,pyci+4);
			cout<<"Ingrese el nuevo nombre: ";
			gotoxy(pxci+40,pyci+6);SetConsoleTextAttribute(hCon, color_frase);
			cin>>enunciado;
			SetConsoleTextAttribute(hCon, color_letr);
			aux->nombre = enunciado;
			break;
		}
		case 2:{	
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACION APELLIDO ");
			
			gotoxy(pxci+30,pyci+2);
			cout<<"Apellido de cliente actual: "<<aux->apellido;
			gotoxy(pxci+38,pyci+4);
			cout<<"Ingrese el nuevo apellido: ";
			gotoxy(pxci+40,pyci+6);SetConsoleTextAttribute(hCon, color_frase);
			cin>>enunciado;
			SetConsoleTextAttribute(hCon, color_letr);
			aux->apellido = enunciado;
			break;
		}
		case 3:{	
			system("cls");
			cuadrito_presentacion(alto,ancho);
			SetConsoleTextAttribute(hCon, color_letr);
			gotoxy(pxci,pyci);
			printf("MODIFICACION DIRECCIÓN ");
			
			gotoxy(pxci+30,pyci+2);
			cout<<"Dirección actual: "<<aux->direccion;
			gotoxy(pxci+38,pyci+4);
			cout<<"Ingrese la nueva direccion: ";
			gotoxy(pxci+40,pyci+6);SetConsoleTextAttribute(hCon, color_frase);
			cin>>enunciado;
			SetConsoleTextAttribute(hCon, color_letr);
			aux->direccion = enunciado;
			break;
		}
		default:{
			cout<<"Favor de ingresar una opcion valida";
			break;
		}
	}
}

Usuario *registroU(){					//USUARIO
	Usuario *nuevo = new Usuario;
	struct Usuario *aux;
	aux = uprimero;
	int alto=35, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("REGISTRO USUARIO ");
	
	nuevo->usuario  = validaEntero2("Ingrese el usuario: ",pxci+40,pyci+2);
	nuevo->pasword = validaEntero2("Contraseña: ",pxci+40,pyci+6);
	nuevo->estado = 1;
	nuevo->id = ID();	
	do{
		nuevo->rol = validaEntero2("Ingrese 0-administrador  1-ejecutivo: ",pxci+30,pyci+10);
	}while(nuevo->rol != 0 && nuevo->rol != 1);
	
	gotoxy(pxci+40,pyci+14);SetConsoleTextAttribute(hCon, color_letr);
	printf("Nombre: ");
	gotoxy(pxci+45,pyci+16);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->nombre;
	
	gotoxy(pxci+40,pyci+18);SetConsoleTextAttribute(hCon, color_letr);
	printf("Apellido: ");
	gotoxy(pxci+45,pyci+20);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->apellido;
	
	gotoxy(pxci+40,pyci+22);SetConsoleTextAttribute(hCon, color_letr);
	printf("Fecha de nacimento: ");
	gotoxy(pxci+45,pyci+24);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->fnac;
	
	gotoxy(pxci+40,pyci+26);SetConsoleTextAttribute(hCon, color_letr);
	printf("Dirección: ");
	gotoxy(pxci+45,pyci+28);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->direccion;
	SetConsoleTextAttribute(hCon, color_letr);
	nuevo->sig = NULL;
		
	return nuevo;
}

Cliente *registroC(){					// CLIENTE
	Cliente *nuevo = new Cliente;
	struct Cliente *aux;
	aux = cprimero;
	nuevo->id = IDCliente();
	nuevo->estado = 1;
	int alto=25, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("REGISTRO CLIENTE ");
	
	gotoxy(pxci+35,pyci+2);SetConsoleTextAttribute(hCon, color_letr);
	printf("Nombre: ");
	gotoxy(pxci+42,pyci+4);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->nombre;
	
	gotoxy(pxci+35,pyci+6);SetConsoleTextAttribute(hCon, color_letr);
	cout << "Apellido: ";
	gotoxy(pxci+42,pyci+8);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->apellido;
	
	gotoxy(pxci+35,pyci+10);SetConsoleTextAttribute(hCon, color_letr);
	cout << "Fecha de nacimento: ";
	gotoxy(pxci+42,pyci+12);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->fnac;
	
	gotoxy(pxci+35,pyci+14);SetConsoleTextAttribute(hCon, color_letr);
	cout << "Dirección: ";
	gotoxy(pxci+42,pyci+16);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->direccion;
	nuevo->sig = NULL;
	SetConsoleTextAttribute(hCon, color_letr);
	
	return nuevo;
}

Tasas *registroT(){					
	Tasas *nuevo = new Tasas;
	struct Tasas *aux;
	aux = tprimero;
	system("cls");
	int alto=25, ancho=100;
	cuadrito_presentacion(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("REGITRO DE TASA ");
	do{
		nuevo->tipo = validaEntero2("Tipo de tasa: 0-Ahorro  1-Credito 2-Hipoteca ",pxci+25,pyci+2);
	}while(nuevo->tipo != 0 && nuevo->tipo != 1 && nuevo->tipo != 2);
	nuevo->anualidad = -1;
	if(nuevo->tipo == 1){
		nuevo->anualidad = validaFlotante2("Ingrese la anualidad: ",pxci+30,pyci+6);
	}
	nuevo->tasa = validaFlotante2("Ingrese la tasa de interes mensual: ",pxci+30,pyci+10);
	gotoxy(pxci+30,pyci+14);
	cout << "Subtipo: ";
	gotoxy(pxci+35,pyci+16);SetConsoleTextAttribute(hCon, color_frase);
	cin >> nuevo->nombre;
	nuevo->sig = NULL;
	SetConsoleTextAttribute(hCon, color_letr);
	return nuevo;
}

void agregarInicioT(){                  
	struct Tasas *nuevo = registroT();
	if(tprimero == NULL){
		nuevo->sig = NULL;
		tprimero = nuevo;
		tultimo = nuevo;
	}else{
		nuevo->sig=tprimero;
		tprimero=nuevo;
	}
}

void agregarInicioU(){                   		// USUARIO
	struct Usuario *nuevo = registroU();
	if(uprimero == NULL){
		nuevo->sig = NULL;
		uprimero = nuevo;
		uultimo = nuevo;
	}else{
		nuevo->sig=uprimero;
		uprimero=nuevo;
	}
}


void agregarInicioC(){							// CLIENTE
	struct Cliente *nuevo = registroC();
	if(cprimero == NULL){
		nuevo->sig = NULL;
		cprimero = nuevo;
		cultimo = nuevo;
	}else{
		nuevo->sig=cprimero;
		cprimero=nuevo;
	}
}

void mostrar_usuario() {					//USUARIO
	struct Usuario *auxiliar = NULL;
	auxiliar =  uprimero;
	system("cls");	//Opcion 7 en revision
	int alto=35, ancho=130;
	int x=pxci, y=pyci+4;
	cuadrito_presentacion2(alto,ancho);
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci-25,pyci);
	printf("USUARIOS REGISTRADOS ");
	gotoxy(pxci+38,pyci+2); 
	
	gotoxy(pxci-12,pyci+2);SetConsoleTextAttribute(hCon, color_titulo);
	cout<<"Usuario";
	gotoxy(pxci,pyci+2);
	cout<<"Contraseña";
	gotoxy(pxci+15,pyci+2);
	cout<<"Estado";
	gotoxy(pxci+27,pyci+2);
	cout<<"Id";
	gotoxy(pxci+39,pyci+2);
	cout<<"Rol";
	gotoxy(pxci+54,pyci+2);
	cout<<"Nombre";
	gotoxy(pxci+69,pyci+2);
	cout<<"Apellido";
	gotoxy(pxci+84,pyci+2);
	cout<<"Fecha de nacimento";
	gotoxy(pxci+109,pyci+2);
	cout<<"Dirección";
	SetConsoleTextAttribute(hCon, color_letr);

	while (auxiliar!=NULL) {
		gotoxy(pxci-12,y);	
		cout<<auxiliar->usuario;
		gotoxy(pxci,y); 
		cout<<auxiliar->pasword;
		
		if(auxiliar->estado == 0){
			gotoxy(pxci+15,y);
			cout<<"Inactivo";
		}else{
			gotoxy(pxci+15,y);
			cout<<"Activo";
		}
		
		gotoxy(pxci+27,y);
		cout<<auxiliar->id;
		
		if(auxiliar->rol == 1){
			gotoxy(pxci+36,y);
			cout<<"Administrador";
		}else{
			gotoxy(pxci+36,y);
			cout<<"Ejecutivo";
		}
		
		gotoxy(pxci+54,y);
		cout<<auxiliar->nombre;
		gotoxy(pxci+69,y);
		cout<<auxiliar->apellido;
		gotoxy(pxci+87,y);
		cout<<auxiliar->fnac;
		gotoxy(pxci+109,y);
		cout<<auxiliar->direccion;
		auxiliar = auxiliar->sig;
		y+=2;
	}
}

void mostrar_cliente() {					//CLIENTE
	struct Cliente *auxiliar = NULL;
	auxiliar =  cprimero;
	system("cls");
	int alto=35, ancho=100;
	int x=pxci, y=pyci+4;
	cuadrito_presentacion(alto,ancho);
	gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
	printf("DATOS CLIENTES ");
	
	gotoxy(50+10,5+2);SetConsoleTextAttribute(hCon, color_titulo);
	cout<<"Id";
	gotoxy(pxci+18,pyci+2);
	cout<<"Estado";
	gotoxy(pxci+30,pyci+2);
	cout<<"Nombre";
	gotoxy(pxci+43,pyci+2);
	cout<<"Apellido";
	gotoxy(pxci+57,pyci+2);
	cout<<"Fecha de nacimento";
	gotoxy(pxci+80,pyci+2);
	cout<<"Dirección";
	
	while (auxiliar!=NULL) {
		gotoxy(pxci+10,y);SetConsoleTextAttribute(hCon, color_letr);		
		cout<<auxiliar->id;
		
		if(auxiliar->estado == 0){
			gotoxy(pxci+20,y);
			cout<<"Inactivo";
		}else{
			gotoxy(pxci+20,y);
			cout<<"Activo";
		}
		gotoxy(pxci+30,y);
		cout<<auxiliar->nombre;
		gotoxy(pxci+44,y);
		cout<<auxiliar->apellido;
		gotoxy(pxci+60,y);
		cout<<auxiliar->fnac;
		gotoxy(pxci+81,y);
		cout<<auxiliar->direccion;
		auxiliar = auxiliar->sig;
		y+=2;
	}
}


void mostrar_tasas() {					//CLIENTE
	struct Tasas *auxiliar = tprimero;
	system("cls");
	int alto=30, ancho=100;
	int x=pxci, y=pyci+4;
	cuadrito_presentacion(alto,ancho);
	gotoxy(pxci,pyci);SetConsoleTextAttribute(hCon, color_letr);
	printf("DATOS DE LAS TASAS MENSUALES ");
	
	gotoxy(50+21,5+2);SetConsoleTextAttribute(hCon, color_titulo);
	cout<<"Tipo";
	gotoxy(pxci+40,pyci+2);
	cout<<"Tasa de interes";
	gotoxy(pxci+70,pyci+2);
	cout<<"Subtipo";
	
	SetConsoleTextAttribute(hCon, color_letr);
	while (auxiliar!=NULL) {
	if(auxiliar->tipo == 0){
		gotoxy(pxci+20,y);
		cout<<"Ahorro";
	}else if(auxiliar->tipo == 1){
		gotoxy(pxci+20,y);
		cout<<"Credito";
	}else{
		gotoxy(pxci+20,y);
		cout<<"Hipoteca";
	}
	gotoxy(pxci+40,y);
	cout<<auxiliar->tasa;
	gotoxy(pxci+70,y);
	cout<<auxiliar->nombre;
	cout<<endl;
	auxiliar = auxiliar->sig;
	y+=2;
	}
	getch();
}

