#include <stdio.h> 
#include <pthread.h> 
pthread_mutex_t lock; 
int count = 0; 
void* thread_function(void* arg) { 
    pthread_mutex_lock(&lock); 
    count++; 
    printf("Count value: %d\n", count); 
    pthread_mutex_unlock(&lock); 
    return NULL; 
} 
int main() { 
    pthread_t t1, t2; 
    pthread_mutex_init(&lock, NULL); // Initialize the mutex 
    pthread_create(&t1, NULL, thread_function, NULL);  // Create two threads 
    pthread_create(&t2, NULL, thread_function, NULL); 
    pthread_join(t1, NULL); 
    pthread_join(t2, NULL);   // Wait for both threads to finish 
    pthread_mutex_destroy(&lock);     // Destroy the mutex 
    return 0; 
}
