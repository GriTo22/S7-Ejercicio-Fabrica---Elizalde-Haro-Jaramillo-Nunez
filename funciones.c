#include <stdio.h>
#include <string.h>
#include "funciones.h"


void registrarlimites(float *tiempolim, int *recursoslim){
    printf("Ingrese la cantidad de tiempo disponible (horas): ");
    *tiempolim = validarFloatConRango(0, 1000000000);
    printf("Ingrese la cantidad de recursos disponibles: ");
    *recursoslim = validarenterosconrango(0, 10000000);
}

int registrarproductos(char nombres[5][30], float *tiempo, int *recursos, int *demanda, int *estado, int cont){
    printf("Ingrese el nombre del producto %d: ", cont);
    leerCadena(nombres[cont],30);
    printf("Ingrese el tiempo que toma elaborar el producto %d: ", cont);
    *(tiempo + cont) = validarFloatConRango(0, 150);
    printf("Ingrese la cantidad de recursos que toma elaborar el producto %d: ", cont);
    *(recursos + cont) = validarenterosconrango(0, 150);
    printf("Ingrese la demanda del producto %d: ", cont);
    *(demanda + cont) = validarenterosconrango(0, 150);
    estado[cont] = 1;
    return cont + 1;
}

void verdatos(char nombres[5][30], float *tiempo, int *recursos, int *demanda, float *tiempot, int *recursost, int cont, float *tiempolim, int *recursoslim, int *estado){

    printf("#\t\tNombre\t\tTiempo\t\tRecursos\tDemanda\t\tTiempo(demanda)\t\tRecursos(demanda)\n");
    float tiempototal = 0;
    int recursostotal = 0;
    

    for (int i = 0; i < cont; i++)
    {
        /* Filtro de Eliminación Lógica: Solo procesar si el estado es 1 (activo) */
        if (estado[i] == 1) 
        {
            /*Calcular tiempo y recursos segun la demanda*/
            tiempot[i] = tiempo[i] * demanda[i];
            recursost[i] = recursos[i] * demanda[i];

            /*Imprimir la tabla*/
            printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%d\t\t%.2f\t\t\t%d\n", i, nombres[i], tiempo[i], recursos[i], demanda[i], tiempot[i], recursost[i]);
            
            /* Acumular totales SOLO de los productos activos */
            tiempototal = tiempototal + tiempot[i];
            recursostotal = recursostotal + recursost[i];
        }
    }
    
    printf("\n");
    printf("Tiempo necesario total de la fabrica: %.2f\n", tiempototal);
    printf("Recursos necesarios total de la fabrica: %d\n", recursostotal);
    printf("-----------------------------------------------------\n");
    printf("Tiempo disponible: %.2f\n", *tiempolim);
    printf("Recursos disponibles: %d\n", *recursoslim);
    printf("-----------------------------------------------------\n");

    /*Verificar si el tiempo y recursos definidos son menores a los disponibles*/
    if(*tiempolim < tiempototal){
        printf("El tiempo requerido es mayor al tiempo disponible\n");
    }
    if (*recursoslim < recursostotal){
        printf("Los recursos requeridos son mayores a los recursos disponibles\n");
    } 
}
/*FUNCIONES GENERALEEEEEEEEEEEEEES*/


void leerCadena(char *cadena, int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

int menu(){
    int opc=0;
    printf("Seleccione una opcion\n");
    printf("1.Definir recursos y tiempo límites\n");
    printf("2.Registrar producto\n");
    printf("3.Ver datos\n");
    printf("4.Editar un producto\n");
    printf("5.Eliminar un producto\n");
    printf(">> ");
    opc = validarenterosconrango(1,5);
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
