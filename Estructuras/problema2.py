'''
/*
 * ESTRUCTURAS: Problema 2
 * Se desea realizar un programa para comprobar si una cadena es un palíndromo.
 * Para ello, se crea un nuevo tipo de dato Cadena para manejar cadenas de caracteres,
 * compuesto por un vector de char y un entero con el tamaño de la cadena
 * (el vector no necesita almacenar un cero al ﬁnal).
 * Desarrolle este programa usando el tipo de dato Cadena.
 * Nota: Recuerde que será necesario eliminar acentos,
 * convertir las mayúsculas a minúsculas,
 * y eliminar todos los caracteres que no corresponden a letras.
 * No se debe usar ctype y string
 */
'''

class Cadena:
    def init(self, arr, size):
        self.arr = arr
        self.size = size

def es_palindromo(c):
    for i in range(c.size//2):
        if c.arr[i] != c.arr[c.size-1-i]:
            return False
    return True

def main():
    arr = input("Ingrese la cadena: ")
    c = Cadena()
    c.init(arr, len(arr))
    if es_palindromo(c):
        print("Es palindromo")
    else:
        print("No es palindromo")

if __name__ == '__main__':
    main()