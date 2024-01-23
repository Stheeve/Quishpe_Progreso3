//librerias requeridas para el programa
#include <stdio.h>
#include <string.h>
//estructura utilizada para el programa 
struct alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
};
int main(){

    int opcion;//variable para el menu
    struct alumno alumnos[20];//variable para que se vayan guardando datos de los estudiantes
    int num;//variable para saber el numero de estudiantes ingresados
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
        //diferentes opciones que da el programa al usuario

        switch (opcion)//switch usado como menu
        {
        case 1://case en el cual se pedira los difetentes datos del estudiante
            for (int i = 0; i < num; i++)//for para ingresar los estudiantes solicitados
            {
                 
                printf("\nDatos del estudiante %d:\n", estudiantes + 1);

                printf("Ingrese la matricula: ");
                fflush(stdin);
                //limpia el espacio de la memoria
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


                archivo = fopen("alumnos.txt", "w");//aqui se abre el archivo y se va modificando metiante se ingrese un nuevo alumno en un archivo llamado alumnos.txt
                for (int i = 0; i < estudiantes; i++)
                {
                    fprintf(archivo, "\nEstudiante %d:\t", i + 1);
                    fprintf(archivo, "%d\t", alumnos[i].matricula);
                    fprintf(archivo, "%s\t", alumnos[i].nombre);
                    fprintf(archivo, "%s\t", alumnos[i].direccion);
                    fprintf(archivo, "%s\t", alumnos[i].materia);
                    fprintf(archivo, "%f\t", alumnos[i].nota);
                }

                fclose(archivo); //se cierra el archivo
                printf("Datos guardados en el archivo 'alumnos.txt'.\n");

                
            }
            
            break;
        
    
        case 2://case usado para imprimir en pantalla a los alumnos ingresados sin necesidad de abrir el archivo alumnos.txt
        for (int i = 0; i < estudiantes; i++)
                {
                    printf("\nEstudiante %d:\t", i + 1);
                    printf("%d\t", alumnos[i].matricula);
                    printf("%s\t", alumnos[i].nombre);
                    printf("%s\t", alumnos[i].direccion);
                    printf("%s\t", alumnos[i].materia);
                    printf("%f\t\n", alumnos[i].nota);
                }

        }

    } while (opcion != 3);//while para cerrar el programa
    
    
}

