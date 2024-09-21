/*
============================================================================
Name : 32ab_firstwriter.c
Author : Soumik Pal
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
Date: 20th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	int key1 = ftok(".",'a');

	int shmid = shmget(key1, 200, IPC_CREAT | 0700);
	char *ptr = (char *)shmat(shmid, NULL, 0);
	if(ptr == (char *)-1)
	{
		perror("Error in attaching shared memory");
		exit(0);
	}
	int ticket = 1000;
	sprintf(ptr, "%d", ticket);
	printf("First ticket number stored in shared memory : %d\n", ticket);
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

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 32ab_firstwriter.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
First ticket number stored in shared memory : 1000

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x61020b87 4          soumik     700        200        0                       

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     


=============================================================================
*/
