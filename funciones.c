#include <stdio.h>
#include <string.h>

void BorrarSaltolinea ( char a[]);
float IngresoDatos (char a[], float b[] , int cont);

float IngresoDatos (char a[], float b[], int cont ){
    do
    {
    char c[1][50];
    
    fgets(c[1], sizeof(c), stdin);
    printf("Nombre del producto: ");
    fgets(a, 50, stdin);
    BorrarSaltolinea(a);
    printf("Precio del producto: ");
    scanf("%f",&b[cont]);
    cont++;
    return cont;
    } while (cont<10);
    
}



void BorrarSaltolinea (char a[]){
int len = strlen(a) - 1;
a[len] = '\0';
}