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
    

    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            cont = registrarproductos(nombresProd, tiempoProd, recursosProd, demandaProd, cont);
            if (cont > 4){
                printf("Se excedió de datos. Solo 5 productos");
                break;
            }
            break;
        case 2:
            verdatos(nombresProd, tiempoProd, recursosProd, demandaProd, tiempototal, recursostotal,cont);
            break;
        case 3:

        break;
        default:
            break;
        }
        

        printf("Ingresar otra opción? 1.si || 2.no ");
        opc2 = validarenterosconrango(1, 2);
    } while (opc2 == 1);



    return 0;
}
