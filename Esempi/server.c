#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str;
	FILE *fp;
	 
	while(1) 
	{
		int ret = system("nc -l 2080 > prova.txt");
		printf("DOPO IL NETCAT");
		
		if((fp=fopen("prova.txt","r"))==NULL)
		{
			return 1;
		}
		
		printf("DOPO L'APERTURA FILE");

		/*printf("Il client ha scritto: ");
		
		fprintf(stdout,"Ricevuto");
		fprintf(stderr, "Il client ha scritto: %s", str);
		while((str = fgetc(fp)) != EOF)
			printf("%c", str);
		*/
		fprintf(stdout,"Ricevuto");
		printf("SONO DOPO IL RICEVUTO");
		fprintf(stderr, "Il client ha scritto: %s", str);
		while((str = fgetc(fp)) != EOF)
			printf("%c", str);
			
		fclose(fp);
    }	
}

