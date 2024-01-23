#include <stdio.h>
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
};
int main(){

    int opcion;
    struct alumno alumnos[20];
    int num;
    int estudiantes=0;
    FILE*archivo;

    printf ("Coloque le numero de alumnos que desee ingresar\n");
    printf ("Se puede ingresar maximo 20 estudiantes\n");
    scanf("%d",&num);


    do
    {
        printf("\nOpcion 1. Ingresar datos de un estudiante\n");
        printf("Opcion 2. Mostrar alumnos \n");
        printf("Opcion 3. Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            for (int i = 0; i < num; i++)
            {
                 
                printf("\nDatos del estudiante %d:\n", estudiantes + 1);

                printf("Ingrese la matricula: ");
                fflush(stdin);
                scanf("%d", &alumnos[estudiantes].matricula);

                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(alumnos[estudiantes].nombre);

                printf("Ingrese la direccion: ");
                fflush(stdin);
                gets(alumnos[estudiantes].direccion);

                printf("Ingrese la materia: ");
                fflush(stdin);
                gets(alumnos[estudiantes].materia);

                printf("Ingrese la nota: ");
                fflush(stdin);
                scanf("%f", &alumnos[estudiantes].nota);
                estudiantes++;

                printf("Estudiante ingresado exitosamente.\n");


                archivo = fopen("alumnos.txt", "w");
                for (int i = 0; i < estudiantes; i++)
                {
                    fprintf(archivo, "\nEstudiante %d:\t", i + 1);
                    fprintf(archivo, "%s\t", alumnos[i].nombre);
                    fprintf(archivo, "%s\t", alumnos[i].direccion);
                    fprintf(archivo, "%s\t", alumnos[i].materia);
                    fprintf(archivo, "%d\t", alumnos[i].matricula);
                    fprintf(archivo, "%f\t", alumnos[i].nota);
                }

                fclose(archivo); 
                printf("Datos guardados en el archivo 'alumnos.txt'.\n");

                
            }
            
            break;
        
    
        case 2:
        for (int i = 0; i < estudiantes; i++)
                {
                    printf("\nEstudiante %d:\t", i + 1);
                    printf("%s\t", alumnos[i].nombre);
                    printf("%s\t", alumnos[i].direccion);
                    printf("%s\t", alumnos[i].materia);
                    printf("%d\t", alumnos[i].matricula);
                    printf("%f\t\n", alumnos[i].nota);
                }

        }

    } while (opcion != 3);
    
    
}

