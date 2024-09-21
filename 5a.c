/*
============================================================================
Name : 5a.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("Max length of args to exec family of functions = %ld\n", sysconf(_SC_ARG_MAX));
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Max length of args to exec family of functions = 2097152

============================================================================
*/
