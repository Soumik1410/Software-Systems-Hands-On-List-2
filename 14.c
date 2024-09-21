/*
============================================================================
Name : 14.c
Author : Soumik Pal
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 18th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int fd[2];
	pipe(fd);
	char buf[]="Hello\n";
	int pid=fork();
	if(pid == -1)
	{
		perror("Error");
		exit(0);
	}
	else if(pid > 0)
	{
		write(fd[1], buf, sizeof(buf));
	}
	else
	{
		char buf2[10];
		read(fd[0], buf2, sizeof(buf));
		write(1, buf2, sizeof(buf));
	}
}

/*
======================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 14.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Hello

======================================================================
*/
