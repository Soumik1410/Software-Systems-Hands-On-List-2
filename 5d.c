/*
============================================================================
Name : 5d.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
d. maximum number of open files
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("Max no of open files = %ld\n", sysconf(_SC_OPEN_MAX));
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5d.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Max no of open files = 1024

===========================================================================
*/
