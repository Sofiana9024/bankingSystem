#include "librerias.h"

int main() {
	system(" mode con: cols=200 lines=45");
	SetConsoleCP(1252); 
	SetConsoleOutputCP(1252); 
	int sigue=1, op = 0;
	PListota=UListota = NULL;
	primero=ultimo=NULL;
	uprimero=uultimo=NULL;
	cprimero=cultimo=NULL;
	tprimero = tultimo = NULL;
	struct Usuario* us;
	srand(time(0));
	
	lecturaLista();
	Lectura();
	inicioTasas();
//presentacion-------
	int alto=20, ancho=100;
	cuadrito_presentacion(alto,ancho);
	contenido_presentacion();
	getch();
	system("cls");
//------------------		
	while(sigue == 1){
		us = validaUsuario();
		if(us == NULL){
			gotoxy(pxci+35,pyci+12);
			cout<<"Datos proporcionados erroneos";
		}else if(us->estado == 0){
			gotoxy(pxci+30,pyci+12);
			cout<<"Usuario es encuentra actualmente inactivo";
		}else{
			if(us->rol == 0){
				Ejecmenu();
			}else if(us->rol == 1){
				Adminmenu();
			}
		}
		sigue = validaEntero2("Ingrese 1 para seguir realizando acciones",pxci+30,pyci+14);
		system("cls");
	}
	escrituraLista();
	Escritura();
	return 0;
}
