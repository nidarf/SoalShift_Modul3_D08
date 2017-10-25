#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];
int status[2];
void* playandcount(void *arg)
{
    pthread_t id=pthread_self();
   if(tid[1]==0){
	int ikan;
	while(status[1]>=1 && status[2]>=1 && status[1]<=100 && status[2]<=100){
	printf("Beri Makan Ikan : \n1. Lohan %d\n2. Kepiting %d\n", status[1], status[2]);
	scanf("%d", &ikan);
	if(ikan == 1) status[1]+=10;
	else status[2]+=10;
	sleep(1);
        status[1]-=15;
}
printf("Gagal\n");
} 
else if(tid[2]==0){
  while(status[1]>=1 && status[2] >= 1 && status[1]<=100 && status[2]<=100){ 
        sleep(1);
        status[1]-=10;
  }
}

return NULL;
}
 
int main(void)
{
   status[1]=100;
   status[2]=100;
   int i=0;
   int err;
   while(i<=2){
   	err=pthread_create(&(tid[i]),NULL,&playandcount, NULL);
	i++;
   }
pthread_join(tid[1],NULL);
pthread_join(tid[2],NULL);
return 0;
}
