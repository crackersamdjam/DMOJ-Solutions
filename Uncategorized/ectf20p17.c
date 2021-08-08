#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	srand(time(NULL));
	for(int i = 0; i < 15; i++)
		rand();
	printf("1\n15\n2\n%d\n", rand());
}