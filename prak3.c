#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[3];

void* playandcount(void *arg)
{
    pthread_t id=pthread_self();
   if(pthread_equal (id,tid[0])==0){
	int ikan;
	while(status[0]>=1 && status[1]>=1 && status[0]<=100 && status[1]<=100){
	printf("Beri Makan Ikan\n1. Lohan %d\n2. Kepiting &d\n", status[0], status[1]);
	scanf("%d", &ikan);
	if(ikan == 1) status[0]+=10;
	else status[1]+=10;
}
printf("Gagal\n");
} 
else if(){

}
else if(){

}
return NULL;
}
 
int main(void)
{
    int i=0;
    int err;
	scanf("%d", &n);
    while(i<n)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
