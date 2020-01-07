---
title: TPSIT
created: '2019-11-12T08:54:57.011Z'
modified: '2020-01-07T08:54:26.889Z'
---

# TPSIT

## Socket 
### 12/11/2019
Usare Wireshark per vedere sia il traffico generato dal client/server UDP che dalla semplice ricerca con il browser

|Messaggio originale|No.|Time|Source|Destination|Protocol|Length|
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|Buongiorno |1| 0.00000| 127.0.0.1| 127.0.0.1| UDP| 52| 
|Salve come va?|52| 8.000000| 127.0.0.1| 127.0.0.1| UDP| 48|


### 20/11/2019
<li>ps aux, guardo i processi</li>
<li>ps -def, guardo i processi e il pid/ppid</li>
<li>pstree, albero dei processi completi</li>
<li>pstree -i, mostra anche il pid
top, semiautomatico e mostra i processi che usano più memoria
<li>cartella /proc, cartella virtuale file (dal punto di vista formale) generati e gestiti automaticamente dal kernel</li>
<li> grep utente/"sigla", vedo solo i processi dell'utente</li>



### 26/11/2019
**Webserver in C**

Possibile libreria di debug personale

#define	critical 5
#define	error 4	
#define	warning 3
#define	notice 2
#define	info 1
int dbcurrent=4;
* 
* void printdebug(char[] stringa,int error)
  {
  	if(error>=debugcurrent)
  	{
  		printf();
   	}

   }

* void setleveldebug()
   {
   	do
  	{
  		scanf("%d",&dbcurrent);
  	}while(dbcurrent<1 || dbcurrent>5);
  }
 
* void pushleveldebug()
  {
 
  }

* void resetleveldebug()
  {

  }
* void push unsetdebuglv()
  {

  }



#### 11/12/2019

*ripasso*
Netcat si occupa dei livelli 1-2-3-4
Il nostro programma del 5-6-7 
Con apache arriveremo fino a metà livello 5

#### 7/01/2020

**Abilitare CGI**

sudo a2enmod cgi

cd /etc/apache2/sites-available
nano 000-default.conf

decommentare inclde cdi-bin
restartare: sudo service apache2 restart


in /usr/lib/cgi-bin
nano getdata.sh


#!/bin/bash

echo '<!DOCTYPE html>'
echo '<html><title>Data</title>'
echo '<body><h1>Today is: '
date
echo '</h1></body>'
echo '</html>'


