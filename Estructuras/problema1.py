'''
/*
 * Desarrolle un programa que lea dos números complejos,
 * presente un menú con las opciones sumar, restar y multiplicar,
 * y escriba el resultado de la operación.
 * Para ello, cree un tipo Complejo que almacene los dos componentes (real, imaginario).
 */
'''

class Complejo:
    def __init__(self, real, imaginario):
        self.real = real
        self.imaginario = imaginario

def sumar(c1,c2):
    c3 = Complejo(0,0)
    c3.real = c1.real + c2.real
    c3.imaginario = c1.imaginario + c2.imaginario
    return c3

def restar(c1,c2):
    c3 = Complejo(0,0)
    c3.real = c1.real - c2.real
    c3.imaginario = c1.imaginario - c2.imaginario
    return c3

def multiplicar(c1,c2):
    c3 = Complejo(0,0)
    c3.real = c1.real * c2.real - c1.imaginario * c2.imaginario
    c3.imaginario = c1.real * c2.imaginario + c1.imaginario * c2.real
    return c3

def main():
    c1_real, c1_imaginario = [float(x) for x in input("Ingrese el primer numero complejo separado por espacio: ").split()]
    c2_real, c2_imaginario = [float(x) for x in input("Ingrese el segundo numero complejo separado por espacio: ").split()]
    c1 = Complejo(c1_real, c1_imaginario)
    c2 = Complejo(c2_real, c2_imaginario)
    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicar")
    opcion = input("Ingrese la opcion: ")
    if opcion == "1":
        c3 = sumar(c1,c2)
        print("La suma es: ", c3.real, "+", c3.imaginario, "i")
    elif opcion == "2":
        c3 = restar(c1,c2)
        print("La resta es: ", c3.real, "+", c3.imaginario, "i")
    elif opcion == "3":
        c3 = multiplicar(c1,c2)
        print("La multiplicacion es: ", c3.real, "+", c3.imaginario, "i")
    else:
        print("Opcion invalida")

if __name__ == '__main__':
    main()
