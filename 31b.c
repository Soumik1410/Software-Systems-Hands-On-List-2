/*
============================================================================
Name : 31b.c
Author : Soumik Pal
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
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
	union semun arg;
	int semid = semget(key, 1, IPC_CREAT | S_IRWXU);
	arg.val = 5;
	int retval = semctl(semid, 0, SETVAL, arg);
	if(retval == -1)
	{
		perror("Error during semaphore initialization");
		exit(0);
	}
	printf("Successfully created counting semaphore\n");
	retval = semctl(semid, 0, GETVAL, arg);
	if(retval == -1)
	{
		perror("Error during retrieving semaphore value");
		exit(0);
	}
	printf("Semaphore initialized with value = %d\n",retval);
}

/*
================================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 31b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Successfully created counting semaphore
Semaphore initialized with value = 5
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x61020b87 5          soumik     700        1

================================================================================
*/
