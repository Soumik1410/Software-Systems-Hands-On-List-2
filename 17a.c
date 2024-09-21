/*
============================================================================
Name : 17a.c
Author : Soumik Pal
Description : Write a program to execute ls -l | wc.
a. use dup
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
	int pid1=fork();
	if(pid1 == 0)
	{
		close(1);
		close(fd[0]);
		int writefd = dup(fd[1]);
		close(fd[1]);
		char *argv[] = {"/bin/ls", "-l", NULL};
		char *env[]= {NULL};
		execve("/bin/ls",argv,env);
		perror("Error");
		exit(0);
	}
	else
	{
		waitpid(pid1, NULL, 0);	
		close(0);
		close(fd[1]);
		int readfd = dup(fd[0]);
		close(fd[0]);
		char *argv[] = {"/bin/wc", NULL};
		char *env[] = {NULL};
		execve("/bin/wc",argv,env);
		perror("Error");
	}
}

/*
===================================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 17a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
     36     317    1828

===================================================================================
*/
