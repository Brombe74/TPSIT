
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv)
{

	char *nome_in=NULL;
	char *nome_out=NULL;
	char *contenuto_file=NULL;
	char c=0;
	FILE *fp;
	
	if(argc > 1) 
	{
        nome_in=argv[1];		//controllo input
    }
    if(argc > 2) 
    {
        nome_in=argv[1];
    }
    
	
	fp=fopen(nome_in, "r"); //apertura file
	
	if(fp==NULL)	//controllo dell'esistenza del file
	{
		printf("\nErrore, file inesistente\n");
		return 1;
	}
	
	while(c=fgetc(fp) != EOF)
	{
		
	}
	
	fprintf("Specifiche Macchina virtuale:");
	
	fclose(fp);	//chiusura file
	
	return 0;
}

