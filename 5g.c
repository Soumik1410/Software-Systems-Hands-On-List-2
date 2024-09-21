/*
============================================================================
Name : 5g.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
g. number of currently available pages in the physical memory
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("No of available pages in memory = %ld\n", sysconf(_SC_AVPHYS_PAGES));
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5g.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
No of available pages in memory = 56291

============================================================================
*/
