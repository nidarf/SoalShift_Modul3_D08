#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[3];
int arr[3];
//int length=157;

void* factorial(void *arg)
{
    //unsigned long i=0;
    int n, i;
    int factorial = 1;
    
    pthread_t id=pthread_self();
    
    if(pthread_equal(id,tid[0])==0)//thread untuk menjalankan counter
    {
	n=arr[0];
        while(n>1){
		factorial *= n;
		n--;
	}
	printf("%d!= %d\n", arr[0], n);
    }
    
    else if(pthread_equal(id,tid[1])==0)
    {
       n=arr[1];
        while(n>1){
		factorial *= n;
		n--;
	}
	printf("%d!= %d\n", arr[1], n);
    }

    else if(pthread_equal(id,tid[2])==0)
    {
	n=arr[2];
        while(n>1){
		factorial *= n;
		n--;
	}
	printf("%d!= %d\n", arr[2], n);
	}
    return NULL;
}

int main(int a, int b, int c)
{
    int i=0;
    int err,n;
	
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    while(i<3)
    {
        err=pthread_create(&(tid[i]),NULL,&factorial,NULL);//membuat thread
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    return 0;
}
