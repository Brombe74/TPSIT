//client in udp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_PORT 1313                      // numero di porta del server
#define SOCKET_ERROR   ((int)-1)

int main(int argc, char *argv[])
{
  struct sockaddr_in locale, remoto;
  char indirizzoServer[]="127.0.0.1";         // indirizzo del server 
  int socketfd, optVal, len;
  int ris;

  // configurazione parametri porta locale 
  locale.sin_family		 = AF_INET;
  locale.sin_addr.s_addr = htonl(INADDR_ANY);   
  locale.sin_port		 = htons(0);         
  // assegnazione parametri del destinatario 
  remoto.sin_family	     = AF_INET;
  remoto.sin_addr.s_addr = inet_addr(indirizzoServer);  // indirizzoServer  
  remoto.sin_port		 = htons(SERVER_PORT);          // porta remota 
 
  printf ("avvio esecuzione client \n" );
  fflush(stdout);

  // creazione del socket 
  socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd == SOCKET_ERROR){
    printf ("socket() fallita, err: %d \"%s\"\n", errno, strerror(errno));
    exit(1);
  }
  printf ("socket() ok \n");
  fflush(stdout);
 
  // bind del socket  
  ris = bind(socketfd, (struct sockaddr*) &locale, sizeof(locale));
  if (ris == SOCKET_ERROR){
    printf ("bind() fallita, err: %d \"%s\"\n", errno, strerror(errno));
    exit(1);
  }
  printf ("bind() ok \n");
  fflush(stdout);

  // invia una parola a destinazione 
  len = sizeof(struct sockaddr_in);
  ris = sendto(socketfd,argv[1],strlen(argv[1]),0,(struct sockaddr*)&remoto, len);
  if (ris < 0)  {
    printf ("errore sendto(): %d \"%s\"\n", errno,strerror(errno));
    exit(1);
  }
  else
    printf("datagram UDP \"%s\" inviato a %s:%d\n",argv[1],indirizzoServer,SERVER_PORT);

  // chiusura socket 
  close(socketfd);
}



/* inviaUDP.c   CLIENT che spedisce parametro datagram UDP unicast */
/* ./inviaUDP.exe <parola>  */
