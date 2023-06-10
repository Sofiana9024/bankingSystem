#include <stdio.h> //FILE
#include <time.h>
#include <stdlib.h>
#include <ctype.h> //isdigit -> retorna cero si no es dígito
#include <string.h> //strlen -> tamaño de cadena
#include <locale.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <unistd.h>

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }

using namespace std;

struct Usuario {
	int usuario;			
	unsigned int pasword;
	int estado;         //0 inactivo 1 activo
	int id;
	int rol;			//0admin 1 ejecutivo
	string nombre;	
	string apellido;
	string fnac;
	string direccion;
	struct Usuario *sig; //siguiente
}*uprimero, *uultimo;

struct Contrato{	//Cual es el maximo d contratos? por eso es la lista d lista? pq no sabes cuantos tendras?
	int id_cliente;
	string sub_tipo;
	string fecha;
	int estado;	// 0 inactivo, 1 activo
	int tipoContrato; 	//ES DEL CONTRATO  = ahorrador, credito o hipoteca
	float cantidad;
	float saldof;
	string prenda; 
	int tipoCliente; //ES DEL CLIENTE = ahorrador o deudor 
	struct Contrato *sig;
}*primero, *ultimo;

struct ListotaContrato{    //para hacer la listota del usuario y sus contratos
	int idListota;
	Contrato *lista;
	ListotaContrato *sig;
}*PListota, *UListota;

struct Cliente{
	int id;
	int estado;    //0 inactivo 1 activo
	string nombre;	
	string apellido;
	string fnac;
	string direccion;
	struct Cliente *sig;	//Capaz q no es neccesario 
	struct ListotaContrato *pcontrato;
}*cprimero, *cultimo;

struct Tasas{	//Hacer una nueva lista para las prendas de avaluo??? 
	int tipo;	/*
	0 para ahorro
	1 para credito
	2 para hipoteca
	*/ 
	float tasa;
	float anualidad; //Solamente para deudores
	string nombre;
	struct Tasas *sig;
}*tprimero, *tultimo;

int tipoContr;

/*VISTA*/
int pyci=5;
int pxci=50;			//posicion inicial
int pxc=50;				//posicion x del cuadro
int pyc=5;				//posicion y del cuadro
int ac=100;				//ancho del cuadro
int alc=20;				//alto cuadrito
char fig=158;			//figura ascii
int color_marc=13;		//color morado
int color_letr=7;		//color gris oscuro
int color_frase= 9;		//color blanco
int color_titulo = 14; 	//color amarilla

#include "vista.h"
#include "validaciones.h"
#include "funciones.h"
#include "archivos.h"
#include "prueba.h"
#include "contratoListita.h"
#include "contratoListota.h"
#include "MenuProyecto.h"
#include "contratos.h"
