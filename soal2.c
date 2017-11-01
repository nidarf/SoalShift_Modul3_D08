#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1,tid2,tid3;

char land[2][16];
int skor1=0,skor2=0,stat=0;
char player1[100],player2[100];

void* start(void* arg){
	
	memset(land,'o',sizeof(land));
	printf("Nama pemain 1 : ");
	scanf("%s", player1);
	printf("Nama pemain 2 : ");
	scanf("%s", player2);
	
	int a,i,m,t;

	while(1){

		printf("\nSKOR :\n1. %s = %d\n2. %s = %d\n\n", player1,skor1,player2,skor2);
		printf("%s ini land milikmu,  silahkan tanam 1-4 ranjau!\n", player1);
		
			for(i=0;i<16;i++) 
				printf("%c  ",land[0][i]); 
				printf("\n");

				printf("Menanam berapa ranjau? ");
				scanf("%d",&a);
				printf("Silahkan pilih lubang yang akan ditanami ranjau : ");		

				while(a--){
					scanf("%d",&m);
					land[0][m]='x';
					}
		

			for(i=0;i<16;i++) 
				printf("%c  ",land[0][i]); 
				printf("\n\n");
		
		printf("%s ini giliranmu, tebak 4 lubang yg tidak ada ranjau!\n", player2);

			for(i=0;i<4;i++){
				scanf("%d", &t);
				if(land[0][t]=='o') skor2++;
				else skor1++;
				}
		
		stat=1;
		while(stat!=0){}
		printf("\n");
		printf("\nSKOR :\n1. %s = %d\n2. %s = %d\n\n", player1,skor1,player2,skor2);		
		printf("%s ini land milikmu, silahkan tanam 1-4 ranjau!\n", player2);
		
			for(i=0;i<16;i++) 
				printf("%c  ",land[1][i]); 
				printf("\n");
		
				printf("Menanam berapa ranjau? ");
				scanf("%d",&a);
				printf("Silahkan pilih lubang yang akan ditanami ranjau : ");
		
					while(a--){
						scanf("%d",&m);
						land[1][m]='x';
					}
		
				
			for(i=0;i<16;i++) 
				printf("%c  ",land[1][i]); 
				printf("\n\n");
		
		printf("%s ini giliranmu, tebak 4 lubang yg tidak ada ranjau!\n", player1);
		for(i=0;i<4;i++){
			scanf("%d", &t);
			if(land[1][t]=='o') skor1++;
			else skor2++;
		}
		
		stat=1;
		while(stat!=0){}
		printf("\n");
	}	
}

