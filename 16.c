/*
============================================================================
Name : 16.c
Author : Soumik Pal
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
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
	int fd1[2], fd2[2];
	pipe(fd1);
	pipe(fd2);

	int pid = fork();
	if(pid == -1)
	{
		perror("Error");
		exit(0);
	}
	else if(pid > 0)
	{
		char buf1[]="Hello Child";
		char buf2[20];
		write(fd1[1], buf1, sizeof(buf1));
		read(fd2[0], buf2, sizeof(buf2));
		printf("In Parent, the message received from the child : %s\n", buf2);
	}
	else
	{
		char buf1[]="Hello Parent";
		char buf2[20];
		read(fd1[0], buf2, sizeof(buf2));
		printf("In Child, the message received from the child : %s\n", buf2);
		write(fd2[1], buf1, sizeof(buf1));
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 16.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
In Child, the message received from the child : Hello Child
In Parent, the message received from the child : Hello Parent

===========================================================================
*/
