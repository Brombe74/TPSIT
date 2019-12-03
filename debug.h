/*
Libreria di Debug
*/

#include <stdio.h>

#define critical 5
#define error 4
#define warning 3
#define notice 2
#define info 1

int dbcurrent=4;

typedef struct errore errorstack;

struct errore
{
	int livello;
	errorstack* next;
};

void printdebug(errorstack* head)
{
	if(head->livello>=dbcurrent)
	{
		printf("%d",head->livello);
	}
}

void setleveldebug()
{
	do
	{
		scanf("%d",&dbcurrent);
	}
	while(dbcurrent<1 || dbcurrent>5);
}

void pushleveldebug(errorstack* head)
{
	errorstack* temp=NULL;
	temp->next=head;
	
}

void popleveldebug(errorstack* head)
{
	errorstack* temp=NULL;
	
}

void restoreleveldebug()
{
	dbcurrent=4;
}

void pushunsetdebuglv(errorstack* head)
{
	head->livello=dbcurrent;
	setleveldebug();
}
