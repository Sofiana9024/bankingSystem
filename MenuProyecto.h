void Adminmenu(){
	int op = 0, cont = 0;
	
	do{
		system("cls");
		int alto=20, ancho=100;
		cuadrito_presentacion(alto,ancho);
		SetConsoleTextAttribute(hCon, color_letr);
		gotoxy(pxci,pyci);
		printf("MENÚ ADMINISTRADOR ");
		gotoxy(pxci+38,pyci+2); 
		printf("1. Registrar");
		gotoxy(pxci+38,pyci+4);
		printf("2. Modificar");
		gotoxy(pxci+38,pyci+6);
		printf("3. Dar de baja");
		gotoxy(pxci+38,pyci+8);
		printf("4. Consultar informacion de usuarios y ejecutivos");
		gotoxy(pxci+38,pyci+10);
		printf("5. Consultar informacion programacion");
		gotoxy(pxci+38,pyci+12);
		printf("0. Salir");

		op = validaEntero2("Ingrese su opcion: ",pxci+38,pyci+14);
		switch(op){
			case 0:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("LOG OUT ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Sesion Cerrada :D";
				break;
			}
			case 1:{
				do{
					system("cls");
					agregarInicioU();
					cont = validaEntero2("Ingrese 1 para agregar nuevo usuario: ",pxci+32,pyci+30);
				}while(cont == 1);
				break;
			}
			case 2:{
				do{
					system("cls");
					Modificar();
					cont = validaEntero2("Ingrese 1 para realizar nueva modificacion: ",pxci+34,pyci+12);
				}while(cont == 1);
				break;
			}
			case 3:{
				do{
					system("cls");
					Eliminar();
					cont = validaEntero2("Ingrese 1 para dar de baja otro usuario: ",pxci+30,pyci+16);
				}while(cont == 1);
				break;
			}
			case 4:{
				mostrar_usuario();
				break;
			}
			case 5:{
				infoPunteros();
				break;
			}
			default:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("ERROR ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Por favor ingrese una opcion valida";
				break;
			}
		}
		getch();		
	}while(op != 0);
}

void menuCliente(){
	int op = 0, cont = 0;
	do{
		system("cls");
		int alto=15, ancho=100;
		cuadrito_presentacion(alto,ancho);
		SetConsoleTextAttribute(hCon, color_letr);
		gotoxy(pxci,pyci);
		printf("OPERACIONES CON CLIENTES ");
		gotoxy(pxci+38,pyci+2);
		printf("1. Registrar nuevo cliente");
		gotoxy(pxci+38,pyci+4);
		printf("2. Modificar cliente");
		gotoxy(pxci+38,pyci+6);
		printf("3. Consultar cliente");
		gotoxy(pxci+38,pyci+8);
		printf("0. Salir");	
		op = validaEntero2("Ingrese su opcion: ",pxci+38,pyci+10);
		switch(op){
			case 0:{
				return;
			}
			case 1:{
				do{
					system("cls");
					agregarInicioC();
					cont = validaEntero2("Ingrese 1 para agrear nuevo cliente: ",pxci+35,pyci+18);
				}while(cont == 1);
				break;
			}
			case 2:{
				do{
					system("cls");
					actualizarC();
					cont = validaEntero2("Ingrese 1 para realizar otra modificacion: ",pxci+30,pyci+10);
				}while(cont == 1);
				break;
			}
			case 3:{
				mostrar_cliente();
				break;
			}
			default:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("ERROR ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Por favor ingrese una opcion valida";
				break;
			}
		}
		getch();
	}while(op != 0);
}



void menuContrato(){
	int op = 0, cont = 0;
	do{
		system("cls");
		int alto=15, ancho=100;
		cuadrito_presentacion(alto,ancho);
		SetConsoleTextAttribute(hCon, color_letr);
		gotoxy(pxci,pyci);
		printf("MENÚ CONTRATO ");
		
		gotoxy(pxci+38,pyci+2); 
		printf("1. Registrar nuevo contrato");
		gotoxy(pxci+38,pyci+4);
		printf("2. Modificar contrato");
		gotoxy(pxci+38,pyci+6);
		printf("3. Consultar contratos");
		gotoxy(pxci+38,pyci+8);
		printf("0. Salir");
		op = validaEntero2("Ingrese su opcion: ",pxci+38,pyci+10);
		switch(op){
			case 0:{
				break;
			}
			case 1:{
				agregarListotaC();
				escrituraLista();
				break;
			}
			case 2:{
				do{
					modificarContrato();
					cont = validaEntero2("Ingrese 1 para realizar otra modificacion: ",pxci+30,pyci+22);
				}while(cont == 1);
				break;
			}
			case 3:{
				mostrarListotaC();	
				getch();
				break;
			}
			default:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("ERROR ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Por favor ingrese una opcion valida";
				break;
			}
		}
	}while(op != 0);
}

void TasasInteres(){
	int op = 0, cont = 0;
	do{
		system("cls");
		int alto=20, ancho=100;
		cuadrito_presentacion(alto,ancho);
		SetConsoleTextAttribute(hCon, color_letr);
		gotoxy(pxci,pyci);
		printf("TASAS DE INTERÉS ");
		gotoxy(pxci+38,pyci+2); 
		printf("1. Registrar Tasa de interés");
		gotoxy(pxci+38,pyci+4);
		printf("2. Modificar tasas de interés");
		gotoxy(pxci+38,pyci+6);
		printf("3. Consultar tasas de interés");
		gotoxy(pxci+38,pyci+8);
		printf("0. Regresar");
		op = validaEntero2("Ingrese su opcion: ",pxci+38,pyci+12);
		switch(op){
			case 0:{
				
				break;
			}
			case 1:{
				do{
					agregarInicioT();
					cont = validaEntero2("Ingrese 1 para agregar otra Tasa de interes: ",pxci+30,pyci+18);
					
				}while(cont == 1);
				break;
			}
			case 2:{
				do{
					modificarTasas();
					cont = validaEntero2("Ingrese 1 para realizar otra modificacion: ",pxci+30,pyci+15);
				}while(cont == 1);
				break;
			}
			case 3:{
				mostrar_tasas();
				break;
			}
			default:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("ERROR ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Por favor ingrese una opcion valida";
				break;
			}
		}
	}while(op != 0);
}

void Ejecmenu(){												//PUESTO PA EL DESORDEN
	int op = 0, cont = 0;
	do{
		system("cls");	
		int alto=20, ancho=100;
		cuadrito_presentacion(alto,ancho);
		SetConsoleTextAttribute(hCon, color_letr);
		gotoxy(pxci,pyci);
		printf("MENÚ EJECUTIVO ");
		gotoxy(pxci+38,pyci+2); 
		printf("1. Registrar Usuario");
		gotoxy(pxci+38,pyci+4);
		printf("2. Modificar Usuario");
		gotoxy(pxci+38,pyci+6);
		printf("3. Eliminar Usuario");
		gotoxy(pxci+38,pyci+8);
		printf("4. Consultar tasa de interés");
		gotoxy(pxci+38,pyci+10);
		printf("5. Operaciones con clientes");
		gotoxy(pxci+38,pyci+12);
		printf("6. Contratos");
		gotoxy(pxci+38,pyci+14);
		printf("0. Salir");
		
		op = validaEntero2("Ingrese su opcion: ",pxci+38,pyci+16);
		system("cls");
		switch(op){
			case 0:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("LOG OUT ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Sesion Cerrada :D";
				break;
			}
			case 1:{
				do{
					agregarInicioU();
					SetConsoleTextAttribute(hCon, color_letr);
					cont = validaEntero2("Ingrese 1 para realizar nuevo registro: ",pxci+30,pyci+30);
					system("cls");
				}while(cont == 1);
				break;
			}
			case 2:{
				do{
					Modificar();
					cont = validaEntero2("Ingrese 1 para realizar nueva modificacion: ",pxci+30,pyci+12);
					system("cls");
				}while(cont == 1);
				break;
			}
			case 3:{
				do{
					Eliminar();		//DEBERIAMOS CONFIRMAR LA ELIMINACION Y SI ES QUE EXISTE EL USUARIO
					cont = validaEntero2("Ingrese 1 para dar de baja otro usuario: ",pxci+30,pyci+12);
					system("cls");
				}while(cont == 1);
				break;
			}
			case 4:{
				TasasInteres();
				break;
			}
			case 5:{
				menuCliente();
				break;
			}
			case 6:{
				menuContrato();
				break;
			}
			default:{
				system("cls");
				cuadrito_presentacion(alto,ancho);
				SetConsoleTextAttribute(hCon, color_letr);
				gotoxy(pxci,pyci);
				printf("ERROR ");
				gotoxy(pxci+38,pyci+2);
				cout<<"Por favor ingrese una opcion valida";
				break;
			}
		}
		getch();	
	}while(op != 0);
}
