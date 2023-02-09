# Problema 3

Desarrolle un programa para gestionar una lista de personas. 
Para cada una es necesario almacenar el nombre, nif, fecha de nacimiento y teléfono. 
El programa deberá presentar un menú con las opciones:
1. Buscar. Se pide una cadena de caracteres y el programa presenta todas las entradas de la lista que la contengan. 
2. Insertar. Se añade una nueva entrada. Deberá comprobarse que no se repite el nif. 
3. Borrar. Se elimina la entrada con un determinado nif. 
4. Salir. Finaliza el programa. 

Para resolver el problema, se deberá considerar una estructura Agenda, que contiene el número de entradas y los datos para cada una de ellas. 
Además, los datos de cada persona estarán representados con una estructura Persona, con un campo añadido para el teléfono.


Pasos a seguir:

1. Se define una estructura ```Persona``` que contiene cuatro elementos: nombre, nif, fecha de nacimiento y teléfono.
2. Se define una estructura ```Agenda``` que contiene dos elementos: size y un arreglo de estructuras Persona con un tamaño máximo de 100.
3. Se define una función ```buscar``` que toma una agenda a como entrada y busca una cadena de caracteres en los nombres de las personas en la agenda. Si se encuentra una coincidencia, se imprime el nombre de la persona.
4. Se define una función ```insertar``` que toma una agenda a como entrada y agrega una nueva persona a la agenda. Se pide al usuario que ingrese un nif, y se verifica si ya existe en la agenda. Si ya existe, se muestra un mensaje de error. Si no existe, se pide al usuario que ingrese el nombre, fecha de nacimiento y teléfono de la persona, y se agrega a la agenda.
5. Se define una función ```borrar``` que toma una agenda a como entrada y elimina una persona de la agenda dado su nif. Si el nif no existe, se muestra un mensaje de error.
6. En la función ```main```, se define una agenda a y se inicializa a.size a 0. Se presenta un menú con las opciones de buscar, insertar, borrar o salir, y se pide al usuario que ingrese una opción. Se ejecuta la opción seleccionada mediante un switch y se repite hasta que el usuario seleccione la opción de salir.
7. Se finaliza el programa.

Tener en cuenta la siguiente salida:

```bash
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 2
Ingrese el nif: 1001
Ingrese el nombre: Fernanda
Ingrese la fecha de nacimiento: 31/08/1995
Ingrese el telefono: 3245678909
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 2
Ingrese el nif: 1001
El nif ya existe
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 2
Ingrese el nif: 1002
Ingrese el nombre: Carlos
Ingrese la fecha de nacimiento: 14/03/1998
Ingrese el telefono: 3245678309
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 1
Ingrese una cadena de caracteres: c
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 1
Ingrese una cadena de caracteres: C  
Carlos
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 3
Ingrese el nif: 1001
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 1
Ingrese una cadena de caracteres: Fernanda
1. Buscar
2. Insertar
3. Borrar
4. Salir
Ingrese una opcion: 4
```