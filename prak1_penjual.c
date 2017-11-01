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

//penjual
while(1){ 
	printf("\n1.Lihat senjata \n2.Tambah senjata [Nama][Jumlah Barang]\n\n");
	scanf("%d",&input);
	if(input==1){ 
		for(int i =1;i<=6;i++){
	 		printf("%s %d\n",str[i-1],*value[i]);
		} 
	} 
	else if(input==2){
		scanf("%s %d",command, &jumlahsenjata); 
			
		for(int i=1;i<=6;i++){
		   if(strcmp(command,str[i-1])==0){		
			*value[i]+=jumlahsenjata;
			printf("Stock %s sekarang = %d\n\n", command, *value[i]);
		   }
		   /*else{printf("Senjata %s tidak ada\n", command);}*/
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
			
/*if ((strcmp(command,"MP4A1")==0)){
		*value[1]+=jumlahsenjata;
		printf("%s sekarang menjadi %d\n\n", command,*value[1]);
		}else if ((strcmp(command,"PM2-V1")==0)){
		*value[2]+=jumlahsenjata;
		printf("%s sekarang menjadi %d\n\n", command,*value[2]);
		}else if ((strcmp(command,"SPR-3")==0)){
		*value[3]+=jumlahsenjata;
		printf("%s sekarang menjadi %d\n\n", command,*value[3]);
		}else if ((strcmp(command,"SS2-V5")==0)){
		*value[4]+=jumlahsenjata;
		printf("%s sekarang menjadi %d\n\n", command,*value[4]);
		}else if ((strcmp(command,"SPG1-V3")==0)){
		*value[5]+=jumlahsenjata;
		printf("%s sekarang menjadi %d\n\n", command,*value[5]);
		}else if ((strcmp(command,"MINE")==0)){
		*value[6]+=jumlahsenjata;
		printf("%s sekarang menjadi %d\n\n", command,*value[6]);
		}
		else{ printf("Senjata yang dimasukkan salah\n");}
	} else printf("Menu yang dimasukkan salah\n");
}*/

