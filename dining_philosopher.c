#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t fork[N];

void* philosopher(void* arg) {
    int id = (int)(long)arg;
    printf("P%d thinking\n", id);
    sleep(1);
    
    int f1 = id, f2 = (id+1) % N;
    if(f1 > f2) { int t=f1; f1=f2; f2=t; }
    
    pthread_mutex_lock(&fork[f1]);
    pthread_mutex_lock(&fork[f2]);
    printf("P%d eating\n", id);
    sleep(2);
    pthread_mutex_unlock(&fork[f1]);
    pthread_mutex_unlock(&fork[f2]);
    return NULL;
}

int main() {
    pthread_t t[N];
    for(int i=0; i<N; i++) pthread_mutex_init(&fork[i], NULL);
    for(int i=0; i<N; i++) pthread_create(&t[i], NULL, philosopher, (void*)(long)i);
    for(int i=0; i<N; i++) pthread_join(t[i], NULL);
    return 0;
}
