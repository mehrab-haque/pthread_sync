#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count=0;

void *threadfunction(void *arg)
{
    int i;
    for(i=0;i<1000;i++)
        count++;
}

int main(void)
{
    int i;
    pthread_t *threads=malloc(sizeof(pthread_t)*10);
    for(i=0;i<10;i++)
        pthread_create(&threads[i], NULL, threadfunction, NULL);
    for(i=0;i<10;i++)
        pthread_join(threads[i], NULL);
    printf("%d",count);
    return 0;
}