#include <iostream>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <typeinfo>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{

	rlimit _new;

	if(!(argc == 3))
	{
		fprintf(stderr, "Usage: %s  <new soft limit>  <new hard limit>\n", argv[0] );
		exit(EXIT_FAILURE);
	}
	
	printf("Changing user nproc limits\n");
	
	_new.rlim_cur = atoi(argv[1]);
	_new.rlim_max = atoi(argv[2]);
	
	if(setrlimit(RLIMIT_NPROC, &_new) == -1)
	{
		fprintf(stderr, "%s ERROR setrlimit == -1 \n", argv[0] );
		exit(EXIT_FAILURE);
	}

	printf("Limits changed\n");

	while(1){
		if(fork() < 0)
		{
			printf("ERROR: %s\n",strerror(errno) );
		}
			
	} 



}
