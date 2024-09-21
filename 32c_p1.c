/*
============================================================================
Name : 32c_p1.c
Author : Soumik Pal
Description : Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
int main()
{
	int key1 = ftok(".",'a');
	int key2 = ftok(".",'b');

	int shmid = shmget(key1, 200, IPC_CREAT | 0700);
	char *ptr = (char *)shmat(shmid, NULL, 0);
	
	int semid = semget(key2, 1, IPC_CREAT | 0700);
	union semun arg;
	arg.val = 2;
	int retval = semctl(semid, 0, SETVAL, arg);
	if(retval == -1)
	{
		perror("Error in semaphore initialization");
		exit(0);
	}

	printf("Process 1 created shared memory as pseudo resource, and semaphore initialized to 2\n");
	printf("It will access Critical Section and go to sleep for 60 seconds, allowing 1 more process to go into CS, 3rd process will be stopped\n");
	
	struct sembuf buf = {0, -1, 0};
	retval = semop(semid, &buf, 1);
	if(retval == -1)
	{
		perror("Error in locking CS");
		exit(0);
	}
	printf("Process 1 entering CS after reducing sem value\n");
	sleep(60);
	buf.sem_op = 1;
	retval = semop(semid, &buf, 1);
	if(retval == -1)
	{
		perror("Error in unlocking CS");
	       	exit(0);	
	}
	printf("Process 1 exiting CS\n");
}

/*
==========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 32c_p1.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 19431
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Process 1 created shared memory as pseudo resource, and semaphore initialized to 2
It will access Critical Section and go to sleep for 60 seconds, allowing 1 more process to go into CS, 3rd process will be stopped
Process 1 entering CS after reducing sem value

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 32c_p2.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[2] 19442
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Process 2 will attempt to access Critical Section and go to sleep for 60 seconds
Semaphore value is greater than 0 now, so program 2 is allowed to enter
Process 2 entering CS after reducing sem value

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 32c_p3.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Program 3 will attempt to access Critical Section and go to sleep for 60 seconds
Semaphore value is 0, so process 3 is blocked from entering
Process 1 exiting CS
Semaphore value is greater than 0 now, so process 3 is allowed to enter
Process 3 entering CS after reducing sem value
Process 2 exiting CS
Process 3 exiting CS
[1]-  Done                    ./a.out
[2]+  Done                    ./a.out

===============================================================================
*/
