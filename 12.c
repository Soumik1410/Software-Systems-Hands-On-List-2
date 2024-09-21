/*
============================================================================
Name : 12.c
Author : Soumik Pal
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
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
	int pid = fork();
	if(pid == -1)
	{
		perror("Error");
		exit(0);
	}
	else if(pid > 0)
	{
		printf("Parent sleeping for 30 seconds waiting for kill signal\n");
		sleep(30);
	}
	else
	{
		printf("Child sending kill signal to parent after 5 seconds\n");
		sleep(5);
		kill(getppid(), SIGKILL);
		sleep(2);
		printf("Child is now an orphan\n");
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 12.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Parent sleeping for 30 seconds waiting for kill signal
Child sending kill signal to parent after 5 seconds
Killed
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Child is now an orphan

===========================================================================
*/
