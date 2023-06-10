float validaFlotante(const char mensaje[]) {
	int continuar=0;
	float flotante=0;
	
	do {
		printf("\n%s",mensaje);
		continuar = scanf("%f", &flotante);
		fflush(stdin);
	} while (continuar != 1);
	
	return flotante; }
	
int validaEntero (const char mensaje[]) {
	int continuar=0;
	int entero=0;
	
	do {
		printf("\n%s",mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
	} while (continuar != 1);
	return entero; }
	
//LO BONITOOOOOOOOOOOO
int validaEntero2 (const char mensaje[], int x, int y) {			//PARA EL LOG IN
	int continuar=0;
	int entero=0;
	
	do {
		gotoxy(x,y);				//posicion donde se muestra el mensaje
		printf("%s",mensaje);
		gotoxy(x+5,y+2);						//posicion de la respuesta
		SetConsoleTextAttribute(hCon, color_frase);
		continuar = scanf("%d", &entero);
		SetConsoleTextAttribute(hCon, color_letr);
		fflush(stdin);
	} while (continuar != 1);
	return entero; 
}

float validaFlotante2(const char mensaje[], int x, int y) {
	int continuar=0;
	float flotante=0;
	
	do {
		gotoxy(x,y);
		printf("%s",mensaje);
		gotoxy(x+5,y+2);
		SetConsoleTextAttribute(hCon, color_frase);
		continuar = scanf("%f", &flotante);
		SetConsoleTextAttribute(hCon, color_letr);
		fflush(stdin);
	} while (continuar != 1);
	
	return flotante; 
}
