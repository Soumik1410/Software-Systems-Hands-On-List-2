/*
============================================================================
Name : 32d.c
Author : Soumik Pal
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<errno.h>
int main()
{
	int key = ftok(".",'b');
	int semid = semget(key, 1, 0);
	int retval = semctl(semid, 0, IPC_RMID, NULL);
	if(retval == -1)
	{
		perror("Error removing semaphore");
		exit(0);
	}
}

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x62020b87 7          soumik     700        1

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 32d.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status

------ Semaphore Arrays --------
key        semid      owner      perms      nsems

soumik@soumik-VirtualBox:~/SS_HandsOnList2$

================================================================================
*/
