#!/bin/bash
#. / nomefile
#nc ip porta

PORTA=9970
ESEGUIBILE="cowsay -f moofasa"
ESEGUIBILEV2="cowsay -f tux"
LETTURA="temp.txt"


    echo "Comunicazione con la mucca 3 nella porta $PORTA"
cat "$LETTURA" | nc localhost "$PORTA" 
