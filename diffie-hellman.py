import random
#import math

def random_number(p):
    rand_num = random.randint(0,p-1)
    #print("El número aleatorio generado es " + str(rand_num))
    return rand_num

def calcula_potencia(r, x):
    num = 0
    for i in range(x+1):
        num = r**i
    return num

def mod_exp(r, x, p):
    #exp = math.pow(r, x)
    exp = calcula_potencia(r, x)
    #print("La potencia es " + str(exp))
    result = exp % p
    return result


p = 761
r = 6
x = random_number(p)

X = mod_exp(r, x, p)

print("Envía el número X (clave pública) a tu compañero " + str(X))


Y = int(input())
K = mod_exp(Y, x, p)

print("El secreto es " + str(K))


