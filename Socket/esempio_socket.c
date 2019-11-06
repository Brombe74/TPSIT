#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

/*
 * struct contenuta in netinet/in.h
struct socket_addr
{
	short sin_family; //valore AF INET, dominio di internet
	u_short sin_port; //numero porta tcp/udp
	struct in_addr sin_addr; // IP
	char sin_zero[8]; // riempimento
};
*/

int main(int argc, char *argv[])
{
	
	int clientLen; //dimensione del client address
	struct sockaddr_in client; //client address
	
	//dati server
	struct sockaddr_in datisocket;
	
	datisocket.sin_family = AF_INET;
	datisocket.sin_addr.s_addr = inet_addr("127.0.0.1"); //da mettere localhost
	datisocket.sin_port = htons(2080);
	
	//creazione socket con TCP
	int prova=socket(AF_INET, SOCKE_STREAM,0);
	
	//indirizzo del socket
	int ip=bind(prova,(struct *sockaddr) &datisocket,sizeof(datisocket));
	
	//ascolto
	int ascolto=listen(prova,1);	//1=massimo di client che si possono accordare in attesa della connessione
	
	//accetto connessione
	int accetta=accept(prova, (struct sockaddr*)&client, &clientLen);
	
	//chiusura 
	close(prova);
	
	return 0;
}

