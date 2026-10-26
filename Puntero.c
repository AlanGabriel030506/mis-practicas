#include <stdio.h>

int main(){
    int numero = 15;
    int *mi_puntero = &numero;

    printf("Valor de la variable: %d\n", numero);
    printf("Dirección de memoria: %p\n", mi_puntero);
    printf("Valor guardado en esa dirección: %d\n", *mi_puntero);

    return 0;
}