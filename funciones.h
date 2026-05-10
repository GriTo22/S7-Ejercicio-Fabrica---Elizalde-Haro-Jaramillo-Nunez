int menu();
int validarenterosconrango(int a, int b);
void registrarlimites(float *tiempolim, int *recursoslim);
// Cambiamos a void porque la gestion del indice ahora es interna y mas eficiente
void registrarproductos(char nombres[5][30], float *tiempo, int *recursos, int *demanda, int *estado);
void verdatos(char nombres[5][30], float *tiempo, int *recursos, int *demanda, float *tiempot, int *recursost, float *tiempolim, int *recursoslim, int *estado);
void editarProducto(char nombres[5][30], float *tiempo, int *recursos, int *demanda, int *estado);
void eliminarProducto(char nombres[5][30], int *estado);
void leerCadena(char *cadena, int n);
float validarFloatConRango(float a, float b);