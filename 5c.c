/*
============================================================================
Name : 5c.c
Author : Soumik Pal
Description : Write a program to print the system limitation of
c. number of clock ticks (jiffy) per second.
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	printf("Number of clock ticks per second = %ld\n", sysconf(_SC_CLK_TCK));
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 5c.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Number of clock ticks per second = 100

============================================================================
*/
