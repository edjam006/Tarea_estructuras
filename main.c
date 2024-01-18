#include <stdio.h>

struct alumno { //Se crea una estructura para cualquier alumno
    int matricula;
    char nombre[50]; //Se establece una dimension de 50 en la cadena de caracteres
    char direccion[50];
    char carrera[50];
    float promedio;
};

void mostrarDatos(struct alumno dato) { // Aqui se crea una funcion de la misma forma de la estructura para mostrar los datos 
    printf("Matricula: %d\n", dato.matricula);
    printf("Nombre: %s\n", dato.nombre);
    printf("Direccion: %s\n", dato.direccion);
    printf("Carrera: %s\n", dato.carrera);
    printf("Promedio: %.2f\n", dato.promedio);
} //Esto ayuda a que se vea mejor el codigo y poder invocarla en la opcion numero 2 del menu 

int main(int argc, char const *argv[]) {
    struct alumno alumnos[100]; //Se establece un maximo de 150 alumnos para ingresar los datos 
    int opc, n, i;

    do {
        printf("1. Ingresar datos de los alumnos\n"); //Se imprime las opciones del menu en pantalla 
        printf("2. Imprimir los datos de estudiantes\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opc); //Leemos la opcion del usuario 


        switch (opc) {//Estructura que permite la elaboracion de un menu 
            case 1: {
                printf("Ingrese el numero de alumnos de los cuales desea ingresar datos\n"); //Se solicita al usuario el numero de alumnos a analizar 
                scanf("%d", &n);
                fflush(stdin); // Esta funcion permite limpiar el espacio de memoria luego de haber ingresado un dato, para evitar que se lean datos ingresados anteriormente
                for (i = 0; i < n; i++) { //La estructura for permite asignar los datos de cada alumno hasta que se llenen todos los campos de todos los alumno
                    printf("\nDatos del alumno %d\n", i + 1);
                    printf("Ingrese el precio de matricula: "); //En estas lineas de codigo dentro del for, preguntamos los datos y se le asigna a cada valor de la estructura
                    scanf("%d", &alumnos[i].matricula);

                    printf("Ingrese nombre: ");
                    scanf("%s", alumnos[i].nombre);

                    printf("Ingrese direccion: ");
                    scanf("%s", alumnos[i].direccion);

                    printf("Ingrese la carrera del alumno: ");
                    scanf("%s", alumnos[i].carrera);

                    printf("Ingrese promedio: ");
                    scanf("%f", &alumnos[i].promedio);
                    fflush(stdin);
                }
                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) { //Estructura for para imprimir los datos de todos los alumnos ingresados 
                    printf("Datos del alumno %d\n", i + 1);//Se notifica de quien son los datos a mencionar
                    mostrarDatos(alumnos[i]); //Se llama a la funcion mostrar datos para que imprima los valores ingresados en la opcion 1
                    puts("\n");
                }
                break;
            }
            case 3: {
                puts ("Saliendo\n"); // Imprime Saliendo si ya no quiere realizar mas operaciones el usuario 
            }
            default: { //Muestra lo que esta dentro del puts si ingresa una opcion que no esta dentro del menu
                if (opc>3) {
                    puts("La opcion ingresada no es correcta\n");
                }
            }
        }
    } while (opc < 3); // Esta estructura permite mostrar el menu de operaciones hasta que el usuario desee salir 

    return 0;
}