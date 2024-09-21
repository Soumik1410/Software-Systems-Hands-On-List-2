/*
============================================================================
Name : 31a.c
Author : Soumik Pal
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
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
	int key = ftok(".",'a');
	int semid = semget(key, 1, IPC_CREAT | S_IRWXU);
	union semun arg;
	arg.val = 1;
	int retval = semctl(semid, 0, SETVAL, arg);
	if(retval == -1)
	{
		perror("Error initializing binary semaphore");
		exit(0);
	}
	printf("Successfully initialized binary semaphore\n");
	retval = semctl(semid, 0, GETVAL, arg);
	if(retval == -1)
	{
		perror("Error retrieving value of semaphore");
		exit(0);
	}
	printf("Semaphore initialized to value = %d\n",retval);
}

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 31a.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Successfully initialized binary semaphore
Semaphore initialized to value = 1
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x61020b87 4          soumik     700        1         


============================================================================
*/
