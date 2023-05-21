#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Libreria Pila/Pila.h"
#include <unistd.h>
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 7

/**
7. Crear una función que pase a una pila los números de legajo de los alumnos mayores de
edad.
*/


typedef struct {
int legajo;
char nombreYapellido [30];
int edad;
int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;


///prototipado
void mostrar_archivo(FILE *archivo);
void cargar_archivo(FILE *archivo);
void carga_puntos();
void mayor_edad(FILE *archivo,Pila *dada);
int main()
{
    system("COLOR B");
    Pila dada;
     inicpila(&dada);


    FILE *bin=NULL;
bin=fopen("ARCH","rb");





if(bin ==NULL){
printf("Creando nuevo archivo, espere");
carga_puntos();

cargar_archivo(bin);
mostrar_archivo(bin);
mayor_edad(bin,&dada);
}
else{
    mayor_edad(bin,&dada);
}

fclose(bin);
    return 0;
}


///funciones


void cargar_archivo(FILE *archivo){

stAlumno alumno;
archivo= fopen("ARCH","ab");

do{
      printf("\nIngrese nombre y apellido \n");
        fflush(stdin);
        gets(alumno.nombreYapellido);
        printf("Ingrese edad\n");
        scanf("%d",&alumno.edad);
        printf("Ingrese legajo\n");
        scanf("%d",&alumno.legajo);
        printf("Ingrese año\n");
        scanf("%d",&alumno.anio);
        fwrite(&alumno,sizeof(alumno),1,archivo);

    printf("Presione ESCAPE para finalizar o cualquier tecla para continuar \n");
}while(getche() !=ESC);

fclose(archivo);


}

void mostrar_archivo(FILE *archivo)
{

    stAlumno alumno;
    int cant;
    archivo= fopen("ARCH", "rb");
    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            cant=fread(&alumno,sizeof(alumno),1,archivo);

            for(int i=0; i<cant; i++)
            {

                printf("Nombre y Apellido: %s \n",alumno.nombreYapellido);
                printf("Edad: %d \n",alumno.edad);
                printf("Legajo: %d \n",alumno.legajo);
                printf("Anio: %d \n",alumno.anio);
                printf("-----------------\n");
            }
        }


        fclose(archivo);
    }
}

void carga_puntos(){

int i,j;
int num_puntos = 2;
    for (i = 0; i < 8; i++) {
        // Imprimir los puntos con movimiento

        for (j = 0; j < num_puntos; j++) {

            printf("..");

            fflush(stdout); // Forzar la impresión inmediata del punto
            usleep(300000); // Retraso de 100 milisegundos (0.1 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }

}

system("cls");
}


void mayor_edad(FILE *archivo,Pila *dada){

 stAlumno alumno;
int cant;
    archivo= fopen("ARCH", "rb");
    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            cant= fread(&alumno,sizeof(alumno),1,archivo);
  for(int i=0;i<cant;i++){
  if(alumno.edad >= 18){

            apilar(dada,alumno.legajo);
            }
        }

    }
    }
    else{
        printf("ERROR AL CARGAR ARCHIVO \n");
    }


mostrar(dada);
fclose(archivo);
}








