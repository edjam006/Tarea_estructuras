#include <stdio.h>

struct alumno {
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

void mostrarDatos(struct alumno dato) {
    printf("Matricula: %d\n", dato.matricula);
    printf("Nombre: %s\n", dato.nombre);
    printf("Direccion: %s\n", dato.direccion);
    printf("Carrera: %s\n", dato.carrera);
    printf("Promedio: %.2f\n", dato.promedio);
}

int main(int argc, char const *argv[]) {
    struct alumno alumnos[100]; 
    int opc, n, i;

    do {
        printf("1. Ingresar datos de los alumnos\n");
        printf("2. Imprimir los datos de estudiantes\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1: {
                printf("Ingrese el numero de alumnos de los cuales desea ingresar datos\n");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("\nDatos del alumno %d\n", i + 1);
                    printf("Ingrese matricula: ");
                    scanf("%d", &alumnos[i].matricula);

                    printf("Ingrese nombre: ");
                    scanf("%s", alumnos[i].nombre);

                    printf("Ingrese direccion: ");
                    scanf("%s", alumnos[i].direccion);

                    printf("Ingrese carrera: ");
                    scanf("%s", alumnos[i].carrera);

                    printf("Ingrese promedio: ");
                    scanf("%f", &alumnos[i].promedio);
                }
                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) {
                    printf("Datos del alumno %d", i + 1);
                    mostrarDatos(alumnos[i]);
                }
                break;
            }
            case 3: {
                puts ("Saliendo\n");
            }
        }
    } while (opc < 3);

    return 0;
}