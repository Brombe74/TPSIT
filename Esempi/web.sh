#!/bin/bash

SERVER="www.e-fermi.it"

	echo -en "GET / HTTP/1.1\n\n\n"| nc -x 172.30.3.199:3128 "${SERVER}" 80 > temp.txt 
	cat temp.txt | grep Server
	
