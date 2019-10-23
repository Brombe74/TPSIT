#!/bin/bash

#Il server stampera' 'Il client ha scritto +scrittura client'
#Il client scrivera'' ricevuto'

PORTA="2080"

while (true)
do
	echo Connessione tramite la porta "${PORTA}"
	nc -l "${PORTA}" > prova.txt
	echo Il client ha scritto: && cat prova.txt
done

