/*
============================================================================
Name : 17c.c
Author : Soumik Pal
Description : Write a program to execute ls -l | wc.
c. use fcntl
Date: 18th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(pid == 0)
	{
		close(1);
		close(fd[0]);
		int writefd = fcntl(fd[1], F_DUPFD, 1);
		close(fd[1]);
		char *argv[] = {"/bin/ls", "-l", NULL};
		char *env[] = {NULL};
		execve("/bin/ls", argv, env);
	}
	else
	{
		close(0);
		close(fd[1]);
		int readfd = fcntl(fd[0], F_DUPFD, 0);
		close(fd[0]);
		char *argv[]={"/bin/wc", NULL};
		char *env[] = {NULL};
		execve("/bin/wc", argv, env);
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 17c.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
     38     335    1932

===========================================================================
*/
