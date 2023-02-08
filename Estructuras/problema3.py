'''
/*
 * Desarrolle un programa para gestionar una lista de personas.
 * Para cada una es necesario almacenar el nombre, nif, fecha de nacimiento y teléfono.
 * El programa deberá presentar un menú con las opciones:
 * 1. Buscar. Se pide una cadena de caracteres
 * y el programa presenta todas las entradas de la lista que la contengan.
 * 2. Insertar. Se añade una nueva entrada.
 * Deberá comprobarse que no se repite el nif.
 * 3. Borrar. Se elimina la entrada con un determinado nif.
 * 4. Salir. Finaliza el programa.
 * Para resolver el problema, se deberá considerar una estructura Agenda,
 * que contiene el número de entradas y los datos para cada una de ellas.
 * Además, los datos de cada persona estarán representados con una
 * estructura Persona, con un campo añadido para el teléfono.
 * */
'''

class Persona:
    def __init__(self, nombre, nif, fecha, telefono):
        self.nombre = nombre
        self.nif = nif
        self.fecha = fecha
        self.telefono = telefono

class Agenda:
    def __init__(self):
        self.personas = []

    def buscar(self, cadena):
        for p in self.personas:
            if cadena in p.nombre:
                print(p.nombre)

    def insertar(self, nombre, nif, fecha, telefono):
        for p in self.personas:
            if p.nif == nif:
                print("NIF repetido")
                return
        self.personas.append(Persona(nombre, nif, fecha, telefono))

    def borrar(self, nif):
        for p in self.personas:
            if p.nif == nif:
                self.personas.remove(p)
                return
        print("NIF no encontrado")

    def mostrar(self):
        for p in self.personas:
            print(p.nombre, p.nif, p.fecha, p.telefono)

    def menu(self):
        while True:
            print("1. Buscar")
            print("2. Insertar")
            print("3. Borrar")
            print("4. Salir")
            opcion = input("Ingrese una opcion: ")
            if opcion == "1":
                cadena = input("Ingrese la cadena: ")
                self.buscar(cadena)
            elif opcion == "2":
                nombre = input("Ingrese el nombre: ")
                nif = input("Ingrese el NIF: ")
                fecha = input("Ingrese la fecha: ")
                telefono = input("Ingrese el telefono: ")
                self.insertar(nombre, nif, fecha, telefono)
            elif opcion == "3":
                nif = input("Ingrese el NIF: ")
                self.borrar(nif)
            elif opcion == "4":
                break
            else:
                print("Opcion invalida")

def main():
    agenda = Agenda()
    agenda.menu()

if __name__ == '__main__':
    main()