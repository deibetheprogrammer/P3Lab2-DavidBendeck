#include <iostream>
#include<time.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout
using std::cin

int Menu()
int Euler(int)
int MCD(int,int)

int main(int argc, char** argv) {
	
	int choice = Menu();
	
	return 0;
	
}

int Menu() {
	cout <<"              MENU" 	<< "\n"
		 <<"1) Euler" 				<< "\n"
		 <<"2) Triangulo de Pascal" << "\n"
		 <<"3) Juego del arreglo" 	<< "\n"
		 <<"4) Salir"				<< "\n"
		 <<"Escoja el ejercicio que desee: ";
		
	int opcion;
	cin >> opcion;

	// User types any char or string of length < 100

	// Because input stream is in a failed state, cin will be evaluated to false
	while ( !cin || (opcion < 1 || opcion > 4) )
	{
    	cin.clear ();    // Restore input stream to working state
    	cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
    	cout << "Por favor ingrese un numero entero entre 1 y 4: ";//cout << "I said enter an integer, Dumbass. Try again: ";
    	cin >> opcion;    // After cin is restored and any garbage in the stream has been cleared, store user input in number again
	} 
	
	return opcion;
}

int MCD(int a, int b) {
	if(b == 1) {
		return 1;
	}
	
	else if(b == 0) {
		return a;
	}
	
	else {
		if(a > b){
			return MCD(b,(a%b));	
		}
		else if (b > a) {
			return MCD(a,(b%a));	
		}
		else {
			return a;
		}
	}
}

