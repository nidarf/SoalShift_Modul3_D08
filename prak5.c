#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *search(void *arg)
{	
	FILE *file;
	int count=0;
	char baris[1024];
	char *nama, *token;

	nama=(char *) arg;

	file = fopen("Novel.txt", "r");
	unsigned long i =0;
	
	while (fgets(baris,sizeof(baris),file)!=NULL){
		token=strtok(baris," ,.");
		while( token != NULL ) {
	      	    if(strcmp(token,nama)==0) count++;
		    token = strtok(NULL, " ,.");
	   	}
	}
	printf("%s=%d\n",nama,count);	
	fclose(file);
return NULL;
}

int main(int argc, char **argv)
{
    int i=0;char *x;
	pthread_t tid[argc];
	for(i=1; i<argc; i++){
		pthread_create(&tid[i], NULL, &search, (void*)argv[i]);
		pthread_join(tid[i], NULL);		
	}
return 0;
}


