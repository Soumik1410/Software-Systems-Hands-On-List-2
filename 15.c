/*
============================================================================
Name : 15.c
Author : Soumik Pal
Description : Write a simple program to send some data from parent to the child process.
Date: 18th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
int main()
{
	int fd[2];
	pipe(fd);
	char buf[] = "Hello Child";
	int pid = fork();
	if(pid == -1)
	{
		perror("Error");
		exit(0);
	}
	else if(pid > 0)
	{
		printf("Sending message \"%s\" from parent with process id : %d\n", buf, getpid());
		write(fd[1], buf, sizeof(buf));
		wait(NULL);
	}
	else
	{
		sleep(1);
		char buf2[20];
		printf("Received message in child with process id : %d\n", getpid());
		read(fd[0], buf2, sizeof(buf));
		printf("The message received : %s\n", buf2);
	}
}

/*
===========================================================================

Program Output :

oumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 15.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Sending message "Hello Child" from parent with process id : 41435
Received message in child with process id : 41436
The message received : Hello Child

===========================================================================
*/
