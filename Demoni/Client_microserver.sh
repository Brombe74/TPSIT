#!/bin/bash

PORTA=2080
RICEVUTO()
{
	echo Connesso con successo
}

    nc localhost "${PORTA}" > nuovo.html 
    RICEVUTO
    firefox nuovo.html
