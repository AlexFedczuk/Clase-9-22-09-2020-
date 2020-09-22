/*Hoy estaremos viendo un concepto mas
avanzado de las estuctuas.
Tambien estamos viendo como hadcodear un array de structuas.
Como relaciona un atributo de una estructura en otra, PK Y FK.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idDivision;
    char nombreDivision[25];
    int cuatimestre;
}eDivision;

typedef struct
{
    int idAlumno;
    char nombre[25];
    char apellido[25];
    int edad;
    int idDivision;//Foren key
    char nombreDivision[25];
}eAlumno;

void MostrarCursos(eDivision lista[], int tam);
void MostrarAlumnos(eDivision lista[], int tam);
void MostrarAlumnosYSuCurso(eDivision lista[], eAlumno lista[], int tam, int segTam);

int main()
{
    int i;

    eDivision divisiones[3] = {{1,"1C",1},{2,"3A",3},{3,"2B",2}};
    eAlumno alumnos[10] = {{100,"Juan","Gomez",20,1},
                           {101,"Jose","Hoz",23,2},
                           {102,"Carl","Gimenez",21,3},
                           {103,"Carlos","Flor",22,1},
                           {104,"Bozzo","Hierro",19,1},
                           {105,"Pepe","Argento",18,3},
                           {106,"Coco","Sanchez",20,3,
                           {107,"Paul","Millo",24,2},
                           {108,"Peter","Rafael",26,2},
                           {109,"Lucas","Guegue",23,2}};

    /*for(i = 0; i < 10; i++)
    {
        divisiones[i].idDivision = alumnos[i].idDivision;
    }*/

    MostrarCursos(divisiones, 3);

    MostrarAlumnos(alumnos, 10);

    MostrarAlumnosYSuCurso(alumnos, 10);

    return 0;
}


void MostrarCursos(eDivision lista[], int tam)
{
    printf("LISTADO CURSOS: \n");
    for(i = 0; i < tam; i++)
    {
        printf("%d %s %d\n", divisiones[i].idDivision,
                             divisiones[i].nombreDivision,
                             divisiones[i].cuatimestre);
    }
}

void MostrarAlumnos(eDivision lista[], int tam)
{
    printf("\n");
    printf("LISTADO DE ALUMNOS: \n");
    for(i = 0; i < tam; i++)
    {
        printf("%4d %15s %15s %3d %3d\n", alumnos[i].idAlumno,
                                          alumnos[i].nombre,
                                          alumnos[i].apellido,
                                          alumnos[i].edad,
                                          alumnos[i].idDivision);
    }
}

void MostrarAlumnosYSuCurso(eDivision lista[], eAlumno lista[], int tam, int segTam)
{
    int i;
    int j;

    printf("LISTADO DE ALUMNOS Y  SU DIVISION: \n");
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < segTam; j++)
        {
            if(alumnos[i].idDivision == divisiones[j].idDivision)
            {
                printf("%4d %15s %15s %3d %3d %3s\n", alumnos[i].idAlumno,
                                              alumnos[i].nombre,
                                              alumnos[i].apellido,
                                              alumnos[i].edad,
                                              alumnos[i].idDivision,
                                              divisiones[j].nombreDivision);
                break;
            }

        }

        //
    }
}
