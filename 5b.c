/*
============================================================================
Name : 5b.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
b. maximum number of simultaneous process per user id.
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("Max no of simulatenous process per user id = %ld\n", sysconf(_SC_CHILD_MAX));
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Max no of simulatenous process per user id = 18383

============================================================================
*/
