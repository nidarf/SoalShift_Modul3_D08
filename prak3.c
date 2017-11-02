#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1;
pthread_t tid2;

int status=0;
int lohan=100;
int kepiting=100;

void *loh(void *arg)
{
  while(lohan<=100){
  sleep(10);
  lohan-=15;
  }
}

void *kep(void *arg)
{
  while(kepiting<=100){
  sleep(20);
  kepiting-=10;
  }
}

int main()
{ 
  pthread_create(&(tid1), NULL, &loh, NULL);
  pthread_create(&(tid2), NULL, &kep, NULL);

  while(status!=1){
  int choose;
  printf("Status Lohan %d\n", lohan);
  printf("Status Kepiting %d\n", kepiting);
  printf("1. Beri Makan Lohan\n");
  printf("2. Beri Makan Kepiting\n");
  scanf("%d", &choose);
  if(choose==1)
  lohan+=10;
  else if(choose==2)
  kepiting+=10;

   if(status == 1 || lohan > 100 || kepiting > 100 || lohan <= 0 || kepiting <= 0){
  	printf("Gagal\n");
	return 0;
   }
  }
return 0;
}
