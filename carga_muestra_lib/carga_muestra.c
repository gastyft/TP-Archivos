#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 10
#define ESC 27
#include "carga_muestra.h"


///funciones

stAlumno cargar_1_alumno(){


stAlumno alumno1;

printf("Ingrese nombre y apellido \n");
fflush(stdin);
gets(alumno1.nombreYapellido);
printf("Ingrese legajo \n");
scanf("%d",&alumno1.legajo);
printf("Ingrese edad \n");
scanf("%d",&alumno1.edad);
printf("Ingrese anio \n");
scanf("%d",&alumno1.anio);




return alumno1;
}

int cargar_alumnos(stAlumno alumno[DIM]){


char o=0;
int i=0;
while(i<DIM && o!=ESC){

alumno[i]=cargar_1_alumno();
i++;
printf("Presione ESCAPE para finalizar con la carga o cualquier tecla para continuar \n");
fflush(stdin);
o=getch();

}
return i;
}

void mostrar_alumnos(stAlumno alumnos[DIM],int validos){
int i=0;
while(i<validos){
printf("Nombre y apellido: %s \n",alumnos[i].nombreYapellido);
printf("Legajo: %d \n",alumnos[i].legajo);
printf("La edad es: %d \n",alumnos[i].edad);
printf("El anio es: %d \n",alumnos[i].anio);
i++;
}
printf("------------------\n");

}



