/*
============================================================================
Name : 17b.c
Author : Soumik Pal
Description : Write a program to execute ls -l | wc.
b. use dup2
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
	int pid = fork();
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		char *argv[] = {"/bin/ls", "-l", NULL};
		char *env[] = {NULL};
		execve("/bin/ls",argv,env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);
		char *argv[] = {"/bin/wc", NULL};
		char *env[] = {NULL};
		execve("/bin/wc", argv, env);
	}
}

/*
==========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 17b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
     37     326    1880

==========================================================================
*/
