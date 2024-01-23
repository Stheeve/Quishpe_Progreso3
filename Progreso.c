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


}

