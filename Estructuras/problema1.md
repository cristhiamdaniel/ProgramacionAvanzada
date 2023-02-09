# Problema 1

Enunciado:

Desarrolle un programa que lea dos números complejos, presente un menú con las opciones sumar, restar y multiplicar, y escriba el resultado de la operación. Para ello, cree un tipo Complejo que almacene los dos componentes (real, imaginario).

Siga los siguientes pasos:

1. Declare una estructura llamada "Complejo" que tenga dos miembros reales y imaginarios.
2. Declare tres funciones llamadas "sumar", "restar" y "multiplicar" que tomen dos estructuras de tipo "Complejo" como argumentos y devuelvan una estructura de tipo "Complejo".
3. En la función "sumar", calcule la suma de las partes reales y imaginarias de los dos números complejos y asigne los valores a una nueva estructura de tipo "Complejo". 
4. En la función "restar", calcule la diferencia de las partes reales y imaginarias de los dos números complejos y asigne los valores a una nueva estructura de tipo "Complejo". 
5. En la función "multiplicar", calcule el producto de las partes reales y imaginarias de los dos números complejos y asigne los valores a una nueva estructura de tipo "Complejo". 
6. En la función main, declare tres estructuras de tipo "Complejo" llamadas "c1", "c2" y "c3". 
7. Lea los valores reales e imaginarios de los dos números complejos "c1" y "c2" del usuario. 
8. Imprima las opciones de operaciones disponibles (suma, resta y multiplicación) y lea la opción elegida por el usuario. 
9. Use un switch para elegir la operación a realizar basada en la opción elegida por el usuario y asigne el resultado a "c3". 
10. Imprima el resultado de la operación en el formato "El resultado es: X + Y i". 
11. Finalice el programa.

Un ejemplo de la salida sería:

```bash
Ingrese el primer numero complejo: 2 3
Ingrese el segundo numero complejo: 5 1
1. Sumar
2. Restar
3. Multiplicar
Ingrese la opcion: 1
El resultado es: 7 + 4i

```