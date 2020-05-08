#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout;
using std::cin;

//Menu
int Menu();

//Retorna "Fi" 
int Euler(int);

//Retorna el MCD de a y b
int MCD(int,int);

//Funcion para generar el triangulo de Pascal
void Pascal(int);

int main(int argc, char** argv) {
	
	//Llamada al menu
	int choice = Menu();
	
	switch(choice) {
		case 1: {
			cout << "Ingrese un numero entero mayor a 0 por favor: ";
			int number;
			cin >> number;

			// User types any char or string of length < 100

			// Because input stream is in a failed state, cin will be evaluated to false
			while ( !cin || number < 1 )
			{
    			cin.clear ();    // Restore input stream to working state
    			cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
    			cout << "Ingrese un numero entero mayor a 0 por favor: ";
    			cin >> number;    // After cin is restored and any garbage in the stream has been cleared, store user input in number again
			}
			
			//Imprimimos el resultado
			int euler = Euler(number);
			cout << "El resultado de llamar la funcion indicatriz de Euler con "
				 << number <<" es : "
				 << euler;
			break;
		}
		case 2: {
			cout << "Ingrese un numero de filas por favor: ";
			int number;
			cin >> number;

			// User types any char or string of length < 100

			// Because input stream is in a failed state, cin will be evaluated to false
			while ( !cin || number < 1 )
			{
    			cin.clear ();    // Restore input stream to working state
    			cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
    			cout << "Ingrese un numero entero mayor a 0 por favor: ";
    			cin >> number;    // After cin is restored and any garbage in the stream has been cleared, store user input in number again
			}
			
			//imprimimos el resultado
			Pascal(number);
			break;
		}
		case 3: {
			
			break;
		}
		
		case 4: {
			cout << "Saliendo de la aplicacion ...";
			break;
		}
	}
	
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

int Euler(int m) {
	
	int fi = 0;
	
	//Obtenemos el resultado de fi
	for(int n = 1; n <= m; n++) {
		if(MCD(m,n) == 1) {
			fi++;
		}
	}
	
	return fi;
}

void Pascal(int n) {

	//Vectores para contener la linea actual y la linea anterior
	std::vector<int> anterior;
	std::vector<int> actual;
	
	//Para imprimir el triangulo
	for (int i = 0; i < n; i++) {
		
		std::string linea = "";
		anterior = actual;
		actual.clear();
		
		//Para determinar la linea actual
		for (int j = 0; j <= i; j++) {
			
			if (j == 0 || j == i) {
				actual.push_back(1);
			}
			else {
				actual.push_back((anterior[j-1] + anterior[j]));
			}
			
			linea = linea + std::to_string(actual [j]) + ",";
		}
		
		//Elimino la "," sobrante
		//cout << actual.size() << " size actual \n";
		//cout << linea.size() << " size linea \n";
		linea.pop_back();
		linea = linea + "\n";
		cout << linea;
	}
	
	cout << "\n";
}

