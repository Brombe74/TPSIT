#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define SOCKET_ERROR ((int)-1)
#define SERVER_PORT 1314
#define MAXSIZE 10

int main(int argc, char **argv)
{
	char *indirizzoServer="127.0.0.1";
	char buffer[MAXSIZE];	//messaggio ricevuto
	char ch, chMaiu;		//singolo carattere inviato e ricevuto
	int ris, nwrite, len;
	
	int socketfd;
	struct sockaddr_in locale, remoto; //dati del socket
	
	//set del socket locale
	locale.sin_family=AF_INET;
	locale.sin_addr.s_addr=htonl(INADDR_ANY);
	locale.sin_port=htons(0);
		
	//assegnazione parametri del server
	remoto.sin_family=AF_INET;
	remoto.sin_addr.s_addr=inet_addr(indirizzoServer);
	remoto.sin_port=htons(SERVER_PORT);

	//impostazione del transport endpoint
	printf("Creazione del socket()\n");
	socketfd=socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd==SOCKET_ERROR)
	{
		printf("fallito socket(), errore %d \"%s\"\n",errno, strerror(errno));
		return(1);
	}
	
	//binding
	printf("bind()\n");
	ris=bind(socketfd, (struct sockaddr*) &locale, sizeof(locale));
	if(ris==SOCKET_ERROR)
	{
		printf("fallito il bind(), errore: %d \"%s\"\n",errno, strerror(errno));
		return(3);
	}
	
	//richiesta di connessione
	printf("connessione()\n");
	ris= connect(socketfd, (struct sockaddr*) &remoto, sizeof(remoto));
	if(ris==SOCKET_ERROR)
	{
		printf("fallita la connessione(), errore: %d \"%s\"\n",errno, strerror(errno));
		return(4);
	}
	
	//chiusura socket
	close(socketfd);
	return (0);
}

