#include <stdio.h>
#include <string.h>

void BorrarSaltolinea ( char a[]);
float IngresoDatos (char a[], float b[] , int cont);
float PrecioTotal(float Precio[], int cont);
void MasCaro(float Precio[],char producto[][50], int cont);


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

float PrecioTotal(float Precio[], int cont){
    float Total=0;
    for ( int i = 0; i < cont; i++)
    {
        Total+=Precio[i];
    }
    return Total;
}

void MasCaro(float Precio[],char producto[][50], int cont){
    int indice1=0, indice2=0;
    float MasCaro=0, MasBarato=1000;
    for (int i = 0; i < cont; i++)
    {
        if (Precio[i]>MasCaro)
        {
            MasCaro=Precio[i];
            indice1=i;
        }
        if (Precio[i]<MasBarato)
        {
            MasBarato=Precio[i];
            indice2=i;
        }
        
    }
    printf("El producto mas caro del inventario es %s de precio: %.02f\n", producto[indice1], Precio[indice1]);
    printf("El producto mas barato del inventario es %s de precio: %0.2f\n", producto[indice2], Precio[indice2]);
}

void BorrarSaltolinea (char a[]){
int len = strlen(a) - 1;
a[len] = '\0';
}