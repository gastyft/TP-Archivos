#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define prueba C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 1\\pruebita.bin
#define ESC 27


/**
1. Hacer una función que agregue un elemento al final de un archivo.
2.Hacer una función que muestre por pantalla el contenido de un archivo.
3. Hacer una función que retorne la cantidad de registros que contiene un archivo.*/


///prototipado

void carga_archivo(FILE *archivo);  ///ej 1
void mostrar_archivo(FILE *archivo);///ej 2
int contar_elementos(FILE *archivo);///ej 3


int main()
{
    system("COLOR B");
    FILE *bin=NULL;

carga_archivo(bin);

mostrar_archivo(bin);
printf("La cantidad de datos es: %d",contar_elementos(bin));
    return 0;
}

void carga_archivo(FILE *archivo){

int num;
    archivo = fopen("prueba", "a+b" );
if ( archivo != NULL) {
do {

printf ("Ingrese un numero: \n");
scanf ( "%d", &num);
fflush (stdin);
fwrite (&num, sizeof (int), 1, archivo);

printf ( "Presione ESC para terminar \n" );
} while ((getche () ) != ESC );
}
else{
printf("ERROR de datos");
}
fclose (archivo);

}

void mostrar_archivo(FILE *archivo){ ///Muestra datos y devuelve cantidad de datos
    int num,cant;
archivo = fopen("prueba", "rb");
if ( archivo!= NULL) {
while ( !feof (archivo)) {
cant= fread ( &num, sizeof (int), 1, archivo);

for(int i=0;i<cant;i++){
    printf("El numero es %d \n",num);
}
}


fclose (archivo);

/// para realizar instrucciones si se debe    getch();
}
else{
printf("ERROR de datos");
}

}

int contar_elementos(FILE *archivo){
    int cant,num,j=0;
archivo = fopen("prueba", "rb");
if ( archivo!= NULL) {
while ( !feof (archivo)) {
cant= fread ( &num, sizeof (int), 1, archivo);

for(int i=0;i<cant;i++){
    j++;
}
}


fclose (archivo);

/// para realizar instrucciones si se debe    getch();
}
else{
printf("ERROR de datos");
}
return j;
}
