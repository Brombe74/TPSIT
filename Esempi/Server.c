#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str;
	char *stringa;
	FILE *fp;
	 
	while(1) 
	{
		int ret = system("nc -l 2080 > prova.txt");
		scanf("%s",stringa);
		int ret1 =system("nc localhost 2080");
		printf("DOPO IL NETCAT");
		
		if((fp=fopen("prova.txt","r"))==NULL)
		{
			return 1;
		}
		
		printf("DOPO L'APERTURA FILE");
		
		fprintf(stdout,"Ricevuto");
		
		printf("SONO DOPO IL RICEVUTO");
		
		fprintf(stderr, "Il client ha scritto: ");
		while((str = fgetc(fp)) != EOF)
			printf("%c", str);
			
		fclose(fp);
    }	
    
    return 0;
}
