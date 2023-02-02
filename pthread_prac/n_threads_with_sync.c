#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;
pthread_cond_t  *cond;
int currCount=1,N,i;

void *threadfunction(void *p)
{
    int n=*((int *)p);
    while(1) {
      pthread_mutex_lock(&lock);
      while(currCount != n)
         pthread_cond_wait(&cond[n], &lock);
      printf("%d",currCount+1);
      currCount++;
      if(currCount>=N)currCount=0;
      pthread_cond_signal(&cond[currCount]);
      pthread_mutex_unlock(&lock);  
   }
}

int main(void)
{
    pthread_mutex_init(&lock,NULL);
    printf("Enter the number of threads: ");
    scanf("%d",&N);
    pthread_t *threads=malloc(sizeof(pthread_t)*N);
    cond=malloc(sizeof(pthread_cond_t)*N);
    for(i=0;i<N;i++)
        pthread_cond_init(&cond[i], NULL);
    for(i=0;i<N;i++){
        int *arg=malloc(sizeof(int));
        *arg=i;
        pthread_create(&threads[i], NULL, threadfunction, (void *)arg);
    }
    for(i=0;i<N;i++)
        pthread_join(threads[i], NULL);
    return 0;
}