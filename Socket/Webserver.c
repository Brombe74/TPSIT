//Costruire un webserver in C che accetti connessioni multiple e che gestisca il metodo GET come da specifiche RFC2616.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/times.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>


#define PORTA 5555
#define SOCKET_ERROR   ((int)-1)

void chiusura(int signo)
{
	fprintf(stderr, "--Chiusura Webserver--\n");
	fflush(stderr);
	exit(EXIT_SUCCESS);
}

/*
#define	critical 5
#define	error 4	
#define	warning 3
#define	notice 2
#define	info 1
int dbcurrent=4;
* 
* void printdebug(char[] stringa,int error)
* {
* 	if(error>=debugcurrent)
* 	{
* 		printf();
* 	}
* 
* }
* 
* void setleveldebug()
* {
* 	do
* 	{
* 		scanf("%d",&dbcurrent);
* 	}while(dbcurrent<1 || dbcurren>5);
* }
* 
* void pushleveldebug()
* {
* 
* }
* 
* void resetleveldebug()
* {
* 
* }
*/
int main(int argc, char **argv)
{
	//gestione segnali
	struct sigaction segnale;
	segnale.sa_handler=chiusura;
	sigaction(SIGINT, &segnale, NULL); //SIGINT=CTRL+C
	sigaction(EOF, &segnale,NULL); //EOF=CTRL+D
	
	struct sockaddr_in server,client;
	char indirizzoServer[] = "127.0.0.1";     // indirizzo del server 
	int server_socketfd, clinet_socketfd;
	char Buffer[100];
	unsigned int client_len;
	pid_t pid;
	
	// impostazione del transport endpoint 
	printf("creazione del socket()\n");
	server_socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socketfd == SOCKET_ERROR)
	{
		printf ("fallito socket(), errore: %d \"%s\"\n", errno, strerror(errno));
		return(1);
	}
	
	//creazione socket
	memset(&server,0,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=htonl(INADDR_ANY);                      
	server.sin_port= htons(PORTA);


	//bind
	printf("bind()\n");
	if (bind(server_socketfd, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		printf ("fallito il bind(), errore: %d \"%s\"\n", errno, strerror(errno));
		fflush(stdout);  
		return(3);
	}
	
	//listen
	listen(server_socketfd,5);
	while(true)
	{
		client_len=sizeof (client);
		if((client_socketfd=accept(server_socketfd, (struct sockaddr*)&client, &client_len))<0)
			{
				fprintf(stderr, "ERRORE NELL'ACCETTA");
				fflush(stderr);
				exit(1);
			}
	pid=fork();
	}
	
	// richiesta di connessione al server   
	printf("connect()\n");
	if (connect(server_socketfd, (struct sockaddr*) &client, sizeof(client)) == SOCKET_ERROR)
	{
		printf("fallita la connect(), errore: %d \"%s\"\n", errno, strerror(errno));
		fflush(stdout);  
		return(4);
	}
	
	
	//gestione webserver
	return 0;
	
	
}

