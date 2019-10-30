#!/bin/bash
PORTA=2080
ESEGUIBILE="pagina.htmlhttp"
MESSAGGIO="Comunicazione con il client tramite la porta $PORTA"

    echo "${MESSAGGIO}" 
    nc -l "${PORTA}" < "${ESEGUIBILE}" > serverout.txt && cat serverout.txt 	

    
