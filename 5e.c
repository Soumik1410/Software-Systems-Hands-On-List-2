/*
============================================================================
Name : 5e.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
e. size of a page
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("Size of page = %ld bytes\n", sysconf(_SC_PAGESIZE));
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5e.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Size of page = 4096 bytes

============================================================================
*/
