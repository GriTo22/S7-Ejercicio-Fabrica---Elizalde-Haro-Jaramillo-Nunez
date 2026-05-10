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

    int opc=0, opc2=0, cont=0;

    float ltiempo=0;
    int lrecursos=0;


    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            registrarlimites(&ltiempo, &lrecursos);
            break;
        case 2:
            if (cont >= 5){
                printf("Se excedió de datos. Solo 5 productos\n");
            } else {
                cont = registrarproductos(nombresProd, tiempoProd, recursosProd, demandaProd, cont);
            }
            break;
        case 3:
            verdatos(nombresProd, tiempoProd, recursosProd, demandaProd, tiempototal, recursostotal, cont, &ltiempo, &lrecursos, estadoProd);
            break;
        case 4:

        break;
        default:
            break;
        }
        

        printf("Ingresar otra opción? 1.si || 2.no ");
        opc2 = validarenterosconrango(1, 2);
    } while (opc2 == 1);



    return 0;
}
