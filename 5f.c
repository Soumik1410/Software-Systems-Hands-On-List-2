/*
============================================================================
Name : 5f.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
f. total number of pages in the physical memory
Date: 17th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("Total number of pages in the physical memory = %ld\n", sysconf(_SC_PHYS_PAGES));
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5f.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Total number of pages in the physical memory = 1194348

===========================================================================
*/
