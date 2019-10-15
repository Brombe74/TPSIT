#!/bin/bash
#. / nomefile
#nc ip porta

PORTA=9970
ESEGUIBILE="cowsay -f moofasa"
ESEGUIBILEV2="cowsay -f tux"
LETTURA="cat temp.txt"

while true
do
    echo "Comunicazione con la mucca 1 nella porta $PORTA"
    nc.traditional -l -p $PORTA -c "${ESEGUIBILE}"
    echo "Comunicazione con la mucca 2 nella porta $PORTA"
    nc.traditional -l -p $PORTA -c "${ESEGUIBILEV2}"

    echo "Comunicazione con la mucca 3 nella porta $PORTA"
    cat - > /home/local/FERMI/s01525/Documenti/Demoni/temp.txt
    nc.traditional -l -p $PORTA -c "${ESEGUIBILE}"

    echo "Comunicazione con la mucca 4 nella porta $PORTA"
    cat /home/local/FERMI/s01525/Documenti/Demoni/temp.txt | "$ESEGUIBILE"
    

done
