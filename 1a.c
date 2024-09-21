/*
============================================================================
Name : 1a.c
Author : Soumik Pal
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/time.h>
#include<signal.h>
void timer_handler(int signum)
{
	printf("Timer signal received, singal number = %d\n",signum);
	exit(0);
}
int main()
{
	struct itimerval timer;
	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=10;
	timer.it_interval.tv_sec=0;
	timer.it_interval.tv_usec=0;
	if(signal(SIGALRM, timer_handler) == SIG_ERR)
		perror("Error setting signal handler\n");
	if((setitimer(ITIMER_REAL, &timer, NULL)) == -1)
		perror("Error setting timer\n");
	printf("Process going to busy wait, timer interrupt signal will be handled by user defined function\n");
	while(1);
}

/*
==============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 1a.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Process going to busy wait, timer interrupt signal will be handled by user defined function
Timer signal received, singal number = 14
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ kill -l
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
63) SIGRTMAX-1	64) SIGRTMAX	

=============================================================================
*/
