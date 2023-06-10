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

using namespace std;

int main(){
	string prueba;
	prueba = "Hola";
	cout<<prueba;
	string nombre;
	cout<<"Ingrese el nombre";
	cin>>nombre;
	prueba = nombre;
	cout<<prueba;
	return 0;
}
