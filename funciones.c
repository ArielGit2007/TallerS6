#include <stdio.h>
#include <string.h>

void BorrarSaltolinea ( char a[]);
float IngresoDatos (char a[], float b );

float IngresoDatos (char a[], float b ){
    char c[1][50];
    
    fgets(c[1], sizeof(c), stdin);
    printf("Nombre del producto: ");
    fgets(a, 50, stdin);
    BorrarSaltolinea(a);
    printf("Precio del producto: ");
    scanf("%f",&b);
    return b;
}

void BorrarSaltolinea (char a[]){
int len = strlen(a) - 1;
a[len] = '\0';
}