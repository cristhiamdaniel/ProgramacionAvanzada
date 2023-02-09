# Problema 2

Enunciado:

Se desea realizar un programa para comprobar si una cadena es un pa- líndromo. Para ello, se crea un nuevo tipo de dato Cadena para manejar cadenas de caracteres, compuesto por un vector de char y un entero con el tamaño de la cadena (el vector no necesita almacenar un cero al ﬁnal). Desarrolle este programa usando el tipo de dato Cadena. Nota: Recuerde que será necesario eliminar acentos, convertir las mayúsculas a minúsculas, y eliminar todos los caracteres que no corresponden a letras.

Siga los siguientes pasos:

1. Definir la estructura "Cadena" con los atributos "arr" de tipo char y "size" de tipo entero. 
2. Definir la función "esPalindromo" que toma una cadena como entrada y retorna un booleano. 
3. En la función "esPalindromo", recorrer el arreglo "arr" hasta la mitad comparando el primer carácter con el último, el segundo con el penúltimo, y así sucesivamente. 
4. Si alguna de estas comparaciones falla, retornar falso. 
5. Si todas las comparaciones son verdaderas, retornar verdadero. 
6. En la función main, definir una variable de tipo "Cadena". 
7. Pedir al usuario que ingrese una cadena y almacenarla en "arr". 
8. Contar el tamaño de la cadena y almacenarlo en "size". 
9. Llamar a la función "esPalindromo" y pasar la variable "c" como argumento. 
10. Imprimir el resultado retornado por "esPalindromo".

Posibles salidas:

```bash
Ingrese una cadena: hola
0
```

```bash
Ingrese una cadena: abcba
1
```