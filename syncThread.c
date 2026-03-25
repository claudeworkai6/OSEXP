#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int count = 0;


void* thread_fun(void* args){
  pthread_mutex_lock(&lock);
  count ++;
  printf("count value: %d\n", count);
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main(){
  pthread_t t1, t2;
  pthread_mutex_init(&lock, NULL);
  pthread_create(&t1, NULL, thread_fun, NULL);
  pthread_create(&t2, NULL, thread_fun, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_mutex_destroy(&lock);
}
