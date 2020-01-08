/* 
 * Catturare 
 * QUERY STRING
 * REQUEST_METHOD
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampa_pagina()
{
	printf("Content-type: text/html");
	printf("!DOCTYPE html");
	printf("<html><title>Variabili Ambiente</title>");
	printf("<body><h1>Data di oggi</h1>");
	fflush(stdout);
	system("date");
	printf("<br/>");
	printf("<strong>Inserisci Nome</strong>");
	printf("<input type=""text"" name=""Nome"" value="" required>");
	printf("<br/>");
	printf("<strong>Inserisci Cognome</strong>");
	printf("<input type=""text"" name=""Cognome"" value="" required>");
	printf("</body>");
	printf("</html>");
}


int main(int argc, char **argv,char** env)
{
	char *s1="QUERY STRING";
	char *s2="REQUEST_METHOD";

	stampa_pagina();	
	/*while(*env)
	{
		printf("\n%s", *env++);
	}*/
	
	while(*env)
	{
		if((strcmp(*env,*s1) || strcmp(*env,*s2)) == 0)
		strtok
	}
	return 0;
}

