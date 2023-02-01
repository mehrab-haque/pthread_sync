#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count=0;
pthread_mutex_t lock;

void *threadfunction(void *arg)
{
    int i;
    for(i=0;i<1000;i++){
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
}
int main(void)
{
    pthread_mutex_init(&lock,NULL);
    int i;
    pthread_t *threads=malloc(sizeof(pthread_t)*10);
    for(i=0;i<10;i++)
        pthread_create(&threads[i], NULL, threadfunction, NULL);
    for(i=0;i<10;i++)
        pthread_join(threads[i], NULL);
    printf("%d\n",count);
    return 0;
}