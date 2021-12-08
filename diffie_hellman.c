#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double random_number();

double main()
{
    double p, r, e, X;
    p = 761;
    r = 6;
    e = random_number();
    printf("El número aleatorio generado es: %lf\n", e);
    X = fmod(powf(r, e), p);
    printf("Send the number X: %d to your partner.\n", (int) X);
    /**/
    printf("Enter the Y number that your partner has sent you:"); 
    return 0;
}

double random_number(){
    double rand_num;
    srand(time(0));
    rand_num = rand() % (49-0) + 0;
    return rand_num;
}