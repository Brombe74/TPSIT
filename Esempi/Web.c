#include <stdio.h>
#include <stdlib.h>

int main()
{
		system("echo -en 'GET / HTTP/1.1\n\n\n'| nc -x 172.30.3.199:3128 www.e-fermi.it 80 > temp.txt 
	cat temp.txt | grep Server");
		return 0;
}
