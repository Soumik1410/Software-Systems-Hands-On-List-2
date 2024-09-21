/*
============================================================================
Name : 3.c
Author : Soumik Pal
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<errno.h>
#include<stdint.h>
int main()
{
	struct rlimit limits;
	if((getrlimit(RLIMIT_NICE, &limits)) == -1)
        {
                perror("Error in getting limits for Nice Value system resource");
                exit(0);
        }
	printf("NIce Value soft limit = %jd, hard limit = %jd\n", (intmax_t)limits.rlim_cur, (intmax_t)limits.rlim_max);
	limits.rlim_cur = 5;
	limits.rlim_max = 5;
	if((setrlimit(RLIMIT_NICE, &limits)) == -1)
	{
		perror("Error in setting limits for Nice Value system resource");
		exit(0);
	}
	printf("Successfully set new limits fir Noce Value system resource\n");
	if((getrlimit(RLIMIT_NICE, &limits)) == -1)
        {
                perror("Error in setting limits for Nice Value system resource");
                exit(0);
        }    
	printf("NIce Value soft limit = %jd, hard limit = %jd\n", (intmax_t)limits.rlim_cur, (intmax_t)limits.rlim_max);}

/*
==========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 3.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
NIce Value soft limit = 0, hard limit = 0
Error in setting limits for Nice Value system resource: Operation not permitted
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ sudo bash
[sudo] password for soumik:
root@soumik-VirtualBox:/home/soumik/SS_HandsOnList2# cc 3.c
root@soumik-VirtualBox:/home/soumik/SS_HandsOnList2# ./a.out
NIce Value soft limit = 0, hard limit = 0
Successfully set new limits fir Noce Value system resource
NIce Value soft limit = 5, hard limit = 5

=========================================================================
*/
