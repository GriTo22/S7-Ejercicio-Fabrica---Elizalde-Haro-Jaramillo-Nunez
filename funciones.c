#include <stdio.h>
#include <string.h>
#include "funciones.h"


int registrarproductos(char nombres[5][30], float *tiempo, int *recursos, int *demanda, int cont){
    printf("Ingrese el nombre del producto %d: ", cont);
    leerCadena(nombres[cont],30);
    printf("Ingrese el tiempo que toma elaborar el producto %d: ", cont);
    *(tiempo + cont) = validarFloatConRango(0, 150);
    printf("Ingrese la cantidad de recursos que toma elaborar el producto %d: ", cont);
    *(recursos + cont) = validarenterosconrango(0, 150);
    printf("Ingrese la demanda del producto %d: ", cont);
    *(demanda + cont) = validarenterosconrango(0, 150);
    return cont + 1;
}

void verdatos(char nombres[5][30], float *tiempo, int *recursos, int *demanda, float *tiempot, int *recursost, int cont){

    printf("#\t\tNombre\t\tTiempo\t\tRecursos\tDemanda\t\tTiempo(demanda)\t\tRecursos(demanda)\n");
    float tiempototal = 0;
    int recursostotal = 0;

    for (int i = 0; i < cont; i++)
    {
        tiempot[i] = tiempo[i] * demanda[i];
        recursost[i] = recursos[i] * demanda[i];
        printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%d\t\t%.2f\t\t\t%d\n",i,nombres[i],tiempo[i],recursos[i],demanda[i],tiempot[i], recursost[i]);
        tiempototal = tiempototal + tiempot[i];
        recursostotal = recursostotal + recursost[i];
    }
    
    printf("Tiempo necesario total de la fabrica: %.2f\n", tiempototal);
    printf("Recursos necesarios total de la fabrica: %d\n", recursostotal);
}







void leerCadena(char *cadena, int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}


int menu(){
    int opc=0;
    printf("Seleccione una opcion\n");
    printf("1.Registrar producto\n");
    printf("2.Ver datos\n");
    printf("3.Editar un producto\n");
    printf("4.Eliminar un producto\n");
    printf(">> ");
    opc = validarenterosconrango(1,3);
    return opc;
}

int validarenterosconrango(int a, int b){
    int aux;
    int num;
    do
    {
        aux = scanf("%d", &num);
        getchar();
        if (aux != 1 || num<a || num>b){
        printf("el valor ingresado es incorrecto. Ingrese nuevamente: ");
        }
    } while (aux != 1 || num<a || num>b);
    return num;
    
}

float validarFloatConRango(float a, float b){
    int aux;
    float num;
    do
    {
        aux = scanf("%f", &num);
        getchar();
        if (aux != 1 || num<a || num>b){
        printf("el valor ingresado es incorrecto. Ingrese nuevamente: ");
        }
    } while (aux != 1 || num<a || num>b);
    return num;
    
}