#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int random_number();
int mod_power();

double main(){
    int p, r, x, X, Y, K;
    p = 71;
    r = 7;
    x = 40;
    /*Calculamos la clave pública del usuario
    X = fmod(powf(r, x), p);
    printf("Send the number X (public key): %d to your partner.\n", (int) X);*/
    
    int kk = mod_power(r, x);
    printf("Resultado de la potencia %d\n", kk);
    int kkk =  kk % p;
    printf("El cálculo del resto es %d\n", kkk);

    /*Obtenemos la clave pública del usuario 2*/
    printf("Enter the Y number that your partner has sent you: "); 
    scanf("%d", &Y);

    /*Obtenemos la clave común para ambos usuarios
    K = fmod(powf(Y, x), p);
    printf("\nLa llave común K es: %lf", K);*/
    
    printf("\n");
    return 0;
}

/*Generador de números aleatorios; 
limitado para evitar el desbordamiento de pila*/
int random_number(){
    int rand_num;
    srand(time(0));
    rand_num = rand() % (9-0) + 0;
    /*TODO: Se muestra clave privada x por control. Eliminar antes de enviar*/
    printf("El número aleatorio generado es: %d\n", rand_num);
    return rand_num;
}

int mod_power(int numero, int exponente){
    int numeroTemp;
    int i;
    numeroTemp = 1;
    for (i = 1; i <= exponente; ++i){
        numeroTemp = numeroTemp * numero;
        printf("El numero es %d\n", numeroTemp);
    }
    return numeroTemp;
}
