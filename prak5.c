#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


pthread_t tid[500];

void *search(void *argv)
{
	FILE *file;
	int count=0;
	char kata[1000];
	char nama[100];

	file = fopen("Novel.txt", "r");
	strcpy(nama, argv);

	while (!feof(file)){
		fscanf (file, "%s", kata);
		if (strstr(kata,argv) !=NULL) count++;
	}
		
	fclose(file);
	printf("%s=%d\n",nama,count);
}

int main(int argc, char **argv)
{
    int i=0;
	for(i=1; i<argc; i++){
		pthread_create(&tid[i], NULL, search, (void*)argv[i]);
		}
	for(i=0; i<argc; i++){
		pthread_join(tid[i], NULL);
		}	
return 0; 
}


