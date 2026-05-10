#include <stdio.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    char nombresProd[5][30];
    float tiempoProd[5];
    int recursosProd[5];
    //con demanda se refieren a la cantidad a fabricar
    int demandaProd[5];

    float tiempototal[5];
    int recursostotal[5];
    int estadoProd[5] = {0, 0, 0, 0, 0}; 
    int opc = 0, opc2 = 0;

    float ltiempo = 0;
    int lrecursos = 0;

    do
    {
        opc = menu();
        switch (opc)
        {
            case 1:
                registrarlimites(&ltiempo, &lrecursos);
                break;
            case 2:
                // La funcion ahora gestiona sola el espacio disponible
                registrarproductos(nombresProd, tiempoProd, recursosProd, demandaProd, estadoProd);
                break;
            case 3:
                verdatos(nombresProd, tiempoProd, recursosProd, demandaProd, tiempototal, recursostotal, &ltiempo, &lrecursos, estadoProd);
                break;
            case 4:
                editarProducto(nombresProd, tiempoProd, recursosProd, demandaProd, estadoProd);
                break;
            case 5:
                eliminarProducto(nombresProd, estadoProd);
                break;
            default:
                break;
        }

        printf("\nIngresar otra opcion? 1.si || 2.no:\n>>");
        opc2 = validarenterosconrango(1, 2);
    } while (opc2 == 1);
    return 0;
}
