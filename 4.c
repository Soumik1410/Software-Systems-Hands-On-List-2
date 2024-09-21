/*
============================================================================
Name : 4.c
Author : Soumik Pal
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<errno.h>
unsigned long long rdtsc()
{
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A" (dst));
	return dst;
}	
int main()
{
	int i;
	long long unsigned int start, end;
	start=rdtsc();
	for(i=1;i<=100;i++)
		getppid();
	end=rdtsc();
	printf("Time taken = %llu cycles\n", end - start);
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 4.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Time taken = 25224 cycles

===========================================================================
*/
