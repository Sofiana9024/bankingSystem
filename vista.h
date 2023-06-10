void cuadrito_presentacion(int alto, int ancho){
	SetConsoleTextAttribute(hCon, color_marc);
	for(int x=pxci;x<pxci+ancho;x++){
		gotoxy(x,pyc);
		printf("%c",fig);
	}
	
	for(int y=pyci;y<pyci+alto;y++){
		gotoxy(pxc,y);
		printf("%c",fig);
	}
	
	for(int y=pyci;y<pyci+alto;y++){
		gotoxy(pxc+ancho,y);
		printf("%c",fig);
	}
	
	for(int x=pxci;x<=pxci+ancho;x++){
		gotoxy(x,pyc+alto);
		printf("%c",fig);
	}
}

void contenido_presentacion(){
	SetConsoleTextAttribute(hCon, color_letr);
	gotoxy(pxci,pyci);
	printf("Proyecto Progrmacion II ");
	pxc=pxci;	pyc=pyci;
	gotoxy(pxc+7,pyc+4);
	printf("Diego Hernandez Ortiz 177232");
	gotoxy(pxc+7,pyc+6);
	printf("Ana Sofia Rodriguez Castillo 178815");
	gotoxy(pxc+7,pyc+10);
	printf("SISTEMA BANCARIO - DINER");
	gotoxy(pxc+7,pyc+12);
	printf("Programación II");
	gotoxy(pxc+7,pyc+14);
	printf("Maestra: Guadalupe Ledesma Ramos");
	gotoxy(pxc+20,pyc+35);
	printf(" ");
}

void cuadrito_presentacion2(int alto, int ancho){
	SetConsoleTextAttribute(hCon, color_marc);
	for(int x=pxci-25;x<pxci+ancho;x++){
		gotoxy(x,pyc);
		printf("%c",fig);
	}
	
	for(int y=pyci;y<pyci+alto;y++){
		gotoxy(pxc-25,y);
		printf("%c",fig);
	}
	
	for(int y=pyci;y<pyci+alto;y++){
		gotoxy(pxc+ancho,y);
		printf("%c",fig);
	}
	
	for(int x=pxci-25;x<=pxci+ancho;x++){
		gotoxy(x,pyc+alto);
		printf("%c",fig);
	}
}
