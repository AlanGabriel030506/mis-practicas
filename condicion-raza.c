#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int Contador = 0;
pthread_mutex_t Cerradura;

void *Incrementar(void *arg) {
    for(int i=0; i<1000000; i++){
        pthread_mutex_lock(&Cerradura);
        Contador++;
        pthread_mutex_unlock(&Cerradura);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t h1, h2;
    pthread_mutex_init(&Cerradura, NULL);

    pthread_create(&h1, NULL, Incrementar, NULL);
    pthread_create(&h2, NULL, Incrementar, NULL);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);

    printf("Valor final del contador: %d\n", Contador);
    pthread_mutex_destroy(&Cerradura);
    return 0;
}