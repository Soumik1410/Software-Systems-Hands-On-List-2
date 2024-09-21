/*
============================================================================
Name : 2.c
Author : Soumik Pal
Description : Write a program to print the system resource limits. Use getrlimit system call
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
	if((getrlimit(RLIMIT_AS, &limits)) == -1)
	{
		perror("Error in getrlimit call for resource RLIMIT_AS");
		exit(0);
	}
	if(limits.rlim_cur == RLIM_INFINITY)
		printf("No soft limit on Address Space, RLIM_INFINITY\n");
	else
		printf("Soft limit of Address Space size in bytes = %jd\n", (intmax_t)limits.rlim_cur);
	if(limits.rlim_max == RLIM_INFINITY)
		printf("No hard limit on Address Space, RLIM_INFINITY\n");
	else
		printf("Hard limit of address space size in bytes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_CORE, &limits)) == -1)
	{
		perror("Error in getrlimit call for resource RLIMIT_CORE");
		exit(0);
	}
	if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Core file Max Size, RLIM_INFINITY\n");
        else
                printf("Soft limit of Core file Max Size in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Core file Max Size, RLIM_INFINITY\n");
        else
                printf("Hard limit of Core file Max Size in bytes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_CPU, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_CPU");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max CPU Time, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max CPU Time in seconds = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max CPU Time, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max CPU Time in seconds = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_DATA, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_DATA");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Data Segment Max Size, RLIM_INFINITY\n");
        else
                printf("Soft limit of Data Segment Max Size in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Data Segment Max Size, RLIM_INFINITY\n");
        else
                printf("Hard limit of Data Segment Max Size in bytes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_FSIZE, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_FSIZE");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max Size of Files Created, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max Size of Files Created in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max Size of Files Created, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max Size of FIles Created in bytes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_LOCKS, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_LOCKS");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Locks, RLIM_INFINITY\n");
        else
                printf("Soft limit of Locks = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Locks, RLIM_INFINITY\n");
        else
                printf("Hard limit of Locks = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_MEMLOCK, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_MEMLOCK");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on number of bytes of memory that can be locked, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max Size of Memory that can be locked in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on number of bytes of memory that can be locked, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max Size of Memory that can be locked in bytes = %jd\n", (intmax_t)limits.rlim_max);
	
	if((getrlimit(RLIMIT_MSGQUEUE, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_MSGQUEUE");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max Bytes for MQ, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max Bytes for MQ = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max Bytes for MQ, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max Bytes for MQ = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_NICE, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_NICE");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max Nice Value, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max Nice Value = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max Nice Value, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max Nice Value = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_NOFILE, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_NOFILE");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max FD Value, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max FD Value in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max FD Value, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max FD Value in bytes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_NPROC, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_NPROC");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max number of extant processes, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max number of extant processes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max number of extant processes, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max number of extant processes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_RSS, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_RSS");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on RSS Max Size, RLIM_INFINITY\n");
        else
                printf("Soft limit of RSS Max Size in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on RSS Max Size, RLIM_INFINITY\n");
        else
                printf("Hard limit of RSS Max Size in bytes = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_RTPRIO, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_RTPRIO");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on RTPRIO Value, RLIM_INFINITY\n");
        else
                printf("Soft limit of RTPRIO Value = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on RTPRIO Value, RLIM_INFINITY\n");
        else
                printf("Hard limit of RTPRIO Value = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_RTTIME, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_RTTIME");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max RTTIME, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max RTTIME in microseconds = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max RTTIME, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max RTTIME in microseconds = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_SIGPENDING, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_SIGPENDING");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max singals pending, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max signals pending = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max signals pending, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max signals pending = %jd\n", (intmax_t)limits.rlim_max);

	if((getrlimit(RLIMIT_STACK, &limits)) == -1)
        {
                perror("Error in getrlimit call for resource RLIMIT_STACK");
                exit(0);
        }
        if(limits.rlim_cur == RLIM_INFINITY)
                printf("No soft limit on Max Stack Size, RLIM_INFINITY\n");
        else
                printf("Soft limit of Max Stack Size in bytes = %jd\n", (intmax_t)limits.rlim_cur);
        if(limits.rlim_max == RLIM_INFINITY)
                printf("No hard limit on Max Stack Size, RLIM_INFINITY\n");
        else
                printf("Hard limit of Max Stack Size in bytes = %jd\n", (intmax_t)limits.rlim_max);

}

/*
======================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 2.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
No soft limit on Address Space, RLIM_INFINITY
No hard limit on Address Space, RLIM_INFINITY
Soft limit of Core file Max Size in bytes = 0
No hard limit on Core file Max Size, RLIM_INFINITY
No soft limit on Max CPU Time, RLIM_INFINITY
No hard limit on Max CPU Time, RLIM_INFINITY
No soft limit on Data Segment Max Size, RLIM_INFINITY
No hard limit on Data Segment Max Size, RLIM_INFINITY
No soft limit on Max Size of Files Created, RLIM_INFINITY
No hard limit on Max Size of Files Created, RLIM_INFINITY
No soft limit on Locks, RLIM_INFINITY
No hard limit on Locks, RLIM_INFINITY
Soft limit of Max Size of Memory that can be locked in bytes = 611504128
Hard limit of Max Size of Memory that can be locked in bytes = 611504128
Soft limit of Max Bytes for MQ = 819200
Hard limit of Max Bytes for MQ = 819200
Soft limit of Max Nice Value = 0
Hard limit of Max Nice Value = 0
Soft limit of Max FD Value in bytes = 1024
Hard limit of Max FD Value in bytes = 1048576
Soft limit of Max number of extant processes = 18383
Hard limit of Max number of extant processes = 18383
No soft limit on RSS Max Size, RLIM_INFINITY
No hard limit on RSS Max Size, RLIM_INFINITY
Soft limit of RTPRIO Value = 0
Hard limit of RTPRIO Value = 0
No soft limit on Max RTTIME, RLIM_INFINITY
No hard limit on Max RTTIME, RLIM_INFINITY
Soft limit of Max signals pending = 18383
Hard limit of Max signals pending = 18383
Soft limit of Max Stack Size in bytes = 8388608
No hard limit on Max Stack Size, RLIM_INFINITY

=========================================================================
*/
