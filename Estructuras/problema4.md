# Problema 4

Desarrolle un programa para estimar el número π. Para ello, se realiza un experimento de simulación. Suponga un círculo de radio 1 inscrito en un cuadrado. Podemos generar números aleatorios que caigan en cualquier lugar del cuadrado (generamos dos valores aleatorios en el intervalo 0-2). Si contamos el número de valores que caen dentro del círculo, podemos estimar el valor de π. Cuantos más números generemos, mejor aproximación de π tenemos. Escriba un programa para ejecutar este experimento.

Siga los siguientes pasos:

1. Inicializar una estructura Punto con dos valores `x` y `y`
2. Definir una función `distancia` que tome dos puntos como entrada y devuelva la distancia entre ellos
3. Inicializar una semilla para los números aleatorios con `srand(time(nullptr))`
4. Declarar una variable `n` con un valor inicial de 1000000
5. Declarar una variable `dentro` con valor inicial de 0
6. Declarar una variable `centro` de tipo Punto con valores iniciales `x` y `y` iguales a 1
7. Repetir `n` veces lo siguiente:
   7.1. Declarar una variable `p` de tipo Punto con valores `x` y `y` generados aleatoriamente
   7.2. Si la distancia entre `p` y `centro` es menor o igual a 1, incrementar el valor de `dentro` en 1
8. Imprimir el valor de Pi como 4.0 * `dentro` / `n`

Posibles salidas:

```bash
Pi: 3.14061
```


