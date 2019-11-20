
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void stampa()
{
	fprintf(stdout,"\n--Il mio Pid: %d--", getpid());
	fflush(stdout);	//risolve problema del "sonno" prima della stampa
}

void termina()
{
	codice=100+WEXITSTATUS(status);
	fprintf(stdout,"Fine %d",codice);
	fflush(stdout);
}

int main(int argc, char **argv)
{
	
	pid_t f1,f2,f3;
	
	f1=fork();
	f2=fork();
	f3=fork();
	usleep(50);
	
	stampa();
	
	usleep(500);
	
	termina();
	
	return 0;
}

