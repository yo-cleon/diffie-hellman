/*
IMPLEMENTACI�N ALGORITMO DIFFIE-HELLMAN
Dada una aritm�tica modular en n�mero primo p=761 y ra�z primitiva r=6, implementa un programa
que genere un n�emro aleatorio x, calcule X=r^x mod p y lo imprima. A continuaci�n, el programa
recoge como entrada pro consola el n�mero Y que ha generado otro usuario y genera el n�mero K=Y^x=r^xy
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//Definici�n de las funciones utilizadas
int random_number();
int mod_exp(int b, int e, int p);

//M�dulo principal del programa
int main(int argc, char** argv){
    
	int p, r, y, X, Y, K; //declaramos las variables a utilizar
    
	/*Los valores de la ra�z r y del m�dulo p son los facilitados en el enunciado.*/
	p = 761;
    r = 6;
    
    y = random_number(); //Generamos un exponente aleatorio x
    
    printf("====== Servidor ======\n\n\n");
    
    Y = mod_exp(r, y, p); //Generamos el n�mero a intercambiar con la otra parte --> X = r^x mod p
    
	printf("Send the number Y (public key): %d to your partner.\n", Y);
    
	// Recogemos la clave p�blica generado por la otra parte
    printf("Enter the X number that your partner has sent you: "); 
    scanf("%d", &X);
    
    /*
	Obtenemos la clave com�n a ambos usuarios --> K = Y^x mod p
	El resultado de esta operaci�n debe ser igual para ambas partes puesto que:
	Y^x mod p = (r^y mod p)^x mod p = r^yx mod p = Y
	X^y mod p = (r^x mod p)^y mod p = r^xy mod p = K
	*/
	K = mod_exp(X, y, p);
    printf("La llave com�n K es: %d", K);
    
    printf("\n");
    system("pause");
    return 0;

}

//Funci�n para generar n�meros aleatorios
int random_number(){
    int rand_num;
    srand(time(0));
    rand_num = rand();
    return rand_num;
}

//Funci�n para realizar el c�lculo X = r^x mod p
int mod_exp(int b, int e, int p){
	int i, x, power;
	x = 1;
	power = b % p;
	for (i=0; i<8*sizeof(int);i++) {
		if (e & 1){
			x = (x*power) % p;
		}
		e >>= 1;
		power = (power * power) % p;
	}
	return x;
}
