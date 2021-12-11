#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double random_number();
double mod_power();

double main(void){
    double p, r, x, X, Y, K;
    p = 761;
    r = 6  ;
    x = random_number();
    /*Calculamos la clave pública del usuario*/
    X = fmod(powf(r, x), p);
    printf("Send the number X (public key): %d to your partner.\n", (int) X);
    
    /*Obtenemos la clave pública del usuario 2*/
    printf("Enter the Y number that your partner has sent you: "); 
    scanf("%f", &Y);
    
    /*Obtenemos la clave común para ambos usuarios*/
    K = fmod(powf(Y, x), p);
    printf("La llave común K es: %lf", K);
    
    printf("\n");
    return 0;
}

/*Generador de números aleatorios; 
limitado para evitar el desbordamiento de pila*/
double random_number(){
    double rand_num;
    srand(time(0));
    rand_num = rand() % (9-0) + 0;
    /*TODO: Se muestra clave privada x por control. Eliminar antes de enviar*/
    printf("El número aleatorio generado es: %f\n", rand_num);
    return rand_num;
}

double mod_power(double numero, double exponente){
    double numeroTemp;
    double i;
    numeroTemp = 1;
    for (i = 1; i <= exponente; ++i){
        numeroTemp = numeroTemp * numero;
        printf("El numero es %f\n", numeroTemp);
    }
    return numeroTemp;
}
