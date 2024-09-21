/*
============================================================================
Name : 13_sending_signal.c
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
int main(int argc, char *argv[])
{
	printf("Sending signal to Process with PID : %s\n",argv[1]);
	int pid;
	sscanf(argv[1], "%d", &pid);
	kill(pid, SIGSTOP);
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 13_waiting_for_signal.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 39883
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Assigned handler to catch SIGSTOP signal, busy waiting for this signal

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 13_sending_signal.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out 39883
Sending signal to Process with PID : 39883

[1]+  Stopped                 ./a.out

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cd /proc/39883/
soumik@soumik-VirtualBox:/proc/39883$ more status
Name:	a.out
Umask:	0002
State:	T (stopped)
Tgid:	39883
Ngid:	0
Pid:	39883
PPid:	25380

==========================================================================
*/
