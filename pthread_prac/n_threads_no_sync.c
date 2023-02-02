#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *threadfunction(void *p)
{
    int *n=(int *)p;
    while(1)printf("%d",*n);
}

int main(void)
{
    int N,i;
    printf("Enter the number of threads: ");
    scanf("%d",&N);
    pthread_t *threads=malloc(sizeof(pthread_t)*N);
    for(i=1;i<=N;i++){
        int *arg=malloc(sizeof(int));
        *arg=i;
        pthread_create(&threads[i], NULL, threadfunction, (void *)arg);
    }
    for(i=0;i<10;i++)
        pthread_join(threads[i], NULL);
    return 0;
}