/*
============================================================================
Name : 9.c
Author : Soumik Pal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 18th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
int main()
{
	printf("Setting SIGINT signal to be ignored, then sleeping for 10 seconds\n");
	if(signal(SIGINT, SIG_IGN) == SIG_ERR)
	{
		perror("Error");
		exit(0);
	}
	sleep(10);
	printf("Setting SIGNINT signal back to default action, then sleeping for 10 seconds\n");
	if(signal(SIGINT, SIG_DFL) == SIG_ERR)
	{
		perror("Error");
		exit(0);
	}
	sleep(10);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 9.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Setting SIGINT signal to be ignored, then sleeping for 10 seconds
^C
Setting SIGNINT signal back to default action, then sleeping for 10 seconds
^C

===========================================================================
*/
