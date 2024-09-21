/*
============================================================================
Name : 11.c
Author : Soumik Pal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 18th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
int main()
{
	struct sigaction action;
	action.sa_handler = SIG_IGN;
	printf("Setting SIGINT to be ignored with sigaction, then sleeping for 10 seconds\n");
	if(sigaction(SIGINT, &action, NULL) == -1)
	{
		perror("Error");
		exit(0);
	}
	sleep(10);
	action.sa_handler = SIG_DFL;
	printf("Setting SIGINT back to default action with sigaction, then sleeping for 10 seconds\n");
	if(sigaction(SIGINT , &action, NULL) == -1)
	{
		perror("Error");
		exit(0);
	}
	sleep(10);
}

/*
==============================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 11.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a..out
bash: ./a..out: No such file or directory
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Setting SIGINT to be ignored with sigaction, then sleeping for 10 seconds
^C
^C
Setting SIGINT back to default action with sigaction, then sleeping for 10 seconds
^C

==============================================================================
*/
