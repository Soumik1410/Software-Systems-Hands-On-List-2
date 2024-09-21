/*
============================================================================
Name : 23.c
Author : Soumik Pal
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	long PIPE_BUF, OPEN_MAX;
	PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
	OPEN_MAX = sysconf(_SC_OPEN_MAX);
	printf("Size of a pipe = %ld\nMax no of open files in a process = %ld\n", PIPE_BUF, OPEN_MAX);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 23.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Size of a pipe = 4096
Max no of open files in a process = 1024

=============================================================================
*/
