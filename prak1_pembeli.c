#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
char str[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"},command[10];

int input,jumlahsenjata=0,shmid[6],*value[6];
key_t key[6];
key[1] =1234, key[2] =1235, key[3] =1236, key[4] =1237, key[5] =1238, key[6] =1239;


for(int i =1;i<=6;i++){
	shmid[i]= shmget(key[i], sizeof(int), IPC_CREAT | 0666); 
	value[i] = shmat(shmid[i], NULL, 0);
	*value[i]=20;
}

//pembeli
while(1){
	printf("\n1.Lihat senjata\n2.Beli senjata [Nama][Jumlah Barang]\n\n");
	scanf("%d", &input);

	if(input==1){ 
		for(int i =1;i<=6;i++){
	 		printf("%s %d\n",str[i-1],*value[i]);
		} 
	}
	else if(input==2){ 
		scanf("%s %d",command, &jumlahsenjata);
		
		for(int i=1;i<=6;i++)
		{
		  if(strcmp(command, str[i-1])==0){
		 	if ((strcmp(command, str[i-1])==0) && *value[i]-jumlahsenjata>=0){
				*value[i]-=jumlahsenjata;
				printf("Sisa stock %s = %d\n\n", command, *value[i]);
;			}
 			else {printf("Stock tidak cukup\n");}
		  } 
		}
	}		
	else{ 
		printf("Input yang dimasukkan salah\n");}
}
for(int i =1;i<=6;i++){
	 shmdt(value[i]);
	 shmctl(shmid[i], IPC_RMID, NULL);
}
return 0;
}

