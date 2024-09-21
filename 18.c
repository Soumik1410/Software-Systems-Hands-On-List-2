/*
============================================================================
Name : 18.c
Author : Soumik Pal
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
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
	int fd1[2];
	pipe(fd1);

	int pid1 = fork();
	if(pid1 == 0)
	{
		int fd2[2];
		pipe(fd2);

		int pid2 = fork();
		if(pid2 == 0)
		{
			close(fd2[0]);
			dup2(fd2[1], 1);
			close(fd2[1]);
			char *argv[]={"/bin/ls","-l",NULL};
			char *env[]={NULL};
			execve("/bin/ls",argv,env);
		}
		else
		{
			waitpid(pid2, NULL, 0);
			close(fd2[1]);
			dup2(fd2[0],0);
			close(fd2[0]);

			close(fd1[0]);
			dup2(fd1[1],1);
			close(fd1[1]);

			char *argv[]={"/bin/grep", "^d", NULL};
			char *env[]={NULL};
			execve("/bin/grep", argv, env);
		}
	}
	else
	{
		waitpid(pid1, NULL, 0);
		close(fd1[1]);
		dup2(fd1[0], 0);
		close(fd1[0]);
		char *argv[]={"/bin/wc", NULL};
		char *env[]={NULL};
		execve("/bin/wc", argv, env);
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ls -l | grep ^d | wc
      0       0       0
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 18.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
      0       0       0
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ mkdir DummyDirForQ18
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ls -l | grep ^d | wc
      1       9      61
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
      1       9      61

===========================================================================
*/
