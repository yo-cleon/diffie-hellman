#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int random_number();
int mod_power();

int main(void){
    int p, r, x, X, Y, K;
    p = 761;
    r = 6  ;
    x = random_number();
    /*Calculamos la clave pÃºblica del usuario*/
    X = fmod(mod_power(r, x), p);
    printf("Send the number X (public key): %d to your partner.\n", (int) X);
    
    /*Obtenemos la clave pÃºblica del usuario 2*/
    printf("Enter the Y number that your partner has sent you: "); 
    scanf("%d", &Y);
    
    /*Obtenemos la clave común para ambos usuarios*/
    K = fmod(powf(Y, x), p);
    printf("La llave común K es: %d", K);
    
    printf("\n");
    return 0;
}

/*Generador de nÃºmeros aleatorios; 
limitado para evitar el desbordamiento de pila*/
int random_number(){
    int rand_num;
    srand(time(0));
    rand_num = rand() % (100-0) + 0;
    /*TODO: Se muestra clave privada x por control. Eliminar antes de enviar*/
    printf("El numero aleatorio generado es: %d\n", rand_num);
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
