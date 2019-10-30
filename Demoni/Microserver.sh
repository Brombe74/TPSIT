#!/bin/bash

PORTA=2080
ESEGUIBILE="web.html"


     echo "Comunicazione con il client nella porta $PORTA"
    nc.traditional -l -p $PORTA
    firefox "${ESEGUIBILE}"
