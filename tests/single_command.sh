#!/bin/sh

#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#int main(int argc, char *arg[])
#{
	printf("I am: %d", (int) getpid());
	
	pid_t pid = fork();
	printf("fork returned: %d\n", (int) pid);
	
	if (pid < 0) {
		perror("fork failed");
	}
	if(pid ==  0){
		printf("I am the child with pid %d\n", (int) getpid());
		exit(0);
	}
	printf("I am the parent with pid %d\n", (int) getpid());
	waitpid(NULL);
	printf("Parent ending.\n");
	
	return 0;
#}
