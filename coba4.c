#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[100];
unsigned long i=0;
int n;

void* factorial(int n)
{
    int j;
    int factorial = 1;
     
    for(j=1;j<=n;j++){
	    factorial *= j;
    }
	printf("Hasil %d! = %d\n\n", n, factorial);
	
    return NULL;
}

int main()
{
    while(scanf("%d", &n))
    {
	    pthread_create(&tid[i],NULL,&factorial,n);
	    
	    pthread_join(tid[i],NULL);
	    i++;
    }
}
