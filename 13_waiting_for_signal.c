/*
============================================================================
Name : 13_waiting_for_signal.c
Author : Soumik Pal
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 18th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
void signal_handler(int signum)
{
	printf("Successfully caught signal with number = %d\n", signum);
}
int main()
{
	signal(SIGSTOP, signal_handler);
	printf("Assigned handler to catch SIGSTOP signal, busy waiting for this signal\n");
	while(1);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 13_waiting_for_signal.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Assigned handler to catch SIGSTOP signal, busy waiting for this signal

===========================================================================
*/
