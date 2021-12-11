import random
import math

def random_number():
    rand_num = random.randint(0,90)
    print("El número aleatorio generado es " + str(rand_num))
    return rand_num

def mod_exp(r, x, p):
    exp = math.pow(r, x)
    print("La potencia es " + str(exp))
    result = exp % p
    return result


p = 23
r = 5
x = 3

X = mod_exp(r, x, p)

print("Envía el número X (clave pública) a tu compañero " + str(X))


Y = int(input())

K = mod_exp(Y, x, p)

print("El secreto es " + str(K))


