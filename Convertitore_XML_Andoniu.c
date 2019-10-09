#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv)
{

	char *nome_in=NULL;
	char *nome_out=NULL;
	char *contenuto_file=NULL;
	char *temp=NULL;
	int dimensione=0;
	int i=0;
	int j=0;
	int controllo=0;
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
	
	fseek(fp,0,SEEK_END);
	dimensione=ftell(fp);		//lettura grandezza file
	fseek(fp,0,SEEK_SET);
	
	fgets(contenuto_file,dimensione,(FILE*)fp);
	
	for(i=0;i<dimensione;i++)
	{
		if(contenuto_file[i]!=' ')
		{
			temp[i]=contenuto_file[i];
			
			if(contenuto_file[i]='"')
			{
				controllo=strcmp(temp,"name=\"");
				
				if(controllo==0)
				{
					for(j=0;contenuto_file[]
				}
				else
					temp=NULL;
			}
		}
		
	}
	
	fprintf(fp,"Specifiche Macchina virtuale:");
	
	fclose(fp);	//chiusura file
	
	return 0;
}

