#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t mutex[N];

void* philosopher(void* arg) {
    int id = (int)(long)arg;
    
    printf("Philosopher %d thinking\n", id);
    sleep(1);

    int f1 = id;
    int f2 = (id + 1) % N;
    
    if (f1 > f2) { 
      int t = f1;
      f1 = f2;
      f2 = t;
    
    }
    
    pthread_mutex_lock(&mutex[f1]);
    pthread_mutex_lock(&mutex[f2]);
    
    printf("Philosopher %d eating\n", id);
    sleep(2);
    printf("Philosopher %d has finished eating\n", id);
    
    pthread_mutex_unlock(&mutex[f1]);
    pthread_mutex_unlock(&mutex[f2]);
    
    return NULL;
}

int main() {
    pthread_t t[N];
    
    for (int i = 0; i < N; i++) 
      pthread_mutex_init(&mutex[i], NULL);
    for (int i = 0; i < N; i++)
      pthread_create(&t[i], NULL, philosopher, (void*)(long)i);
    for (int i = 0; i < N; i++)
      pthread_join(t[i], NULL);
    
    return 0;
}
