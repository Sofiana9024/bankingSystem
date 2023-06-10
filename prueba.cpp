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
	string cadena("Compi");
	cout<<"Prueba 1";
	cin>>prueba;
	int res = prueba.compare(cadena);
	if(res == 0){
		cout<<"Son iguales";
	}else{
		cout<<"No son iguales";
	}
	return 0;
}
