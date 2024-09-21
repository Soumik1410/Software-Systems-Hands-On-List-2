/*
============================================================================
Name : 32ab_readwriter.c
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
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
/*struct sembuf
{
        short sem_num;
        short sem_op;
        short sem_flg;
};*/
int main()
{
	int key1 = ftok(".",'a');
	int key2 = ftok(".",'b');
	int shmid = shmget(key1, 200, IPC_CREAT | 0700);
	char *ptr = (char *)shmat(shmid, NULL, 0);
	if(ptr == (char *)-1)
	{
		perror("Error in attaching shared memory to process");
		exit(0);	
	}
	
	union semun arg;
	arg.val = 1;
	int semid = semget(key2, 1, IPC_CREAT | 0700);
	int retval = semctl(semid, 0, SETVAL, arg);
	if(retval == -1)
	{
		perror("Error in initializin semaphores");
		exit(0);
	}
	
	struct sembuf buf = {0, -1, 0};
	int ticket;

	//Busy waiting till it is unlocked
	while((semctl(semid, 0, GETVAL, arg)) < 1)
		;

	
	//Locking Critical Section
	retval = semop(semid, &buf, 1);
	if(retval == -1)
	{
		perror("Error in locking Critical section");
		exit(0);
	}
	printf("Critical section locked\n");
	sscanf(ptr, "%d", &ticket);
	printf("Old Ticket Number : %d\n", ticket);
	ticket++;
	sprintf(ptr, "%d", ticket);
	printf("New Ticket Number : %d\n", ticket);
	
	//Unlocking Critical Section
	buf.sem_op = 1;
	retval = semop(semid, &buf, 1);
	if(retval == -1)
	{
		perror("Error in unlocking Critical Section");
		exit(0);
	}
	printf("Unlocked Critical Section\n");
}

/*
============================================================================

Program Output :

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
                                                            

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 32ab_readwriter.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x61020b87 4          soumik     700        200        0

------ Semaphore Arrays --------
key        semid      owner      perms      nsems

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Critical section locked
Old Ticket Number : 1000
New Ticket Number : 1001
Unlocked Critical Section
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x61020b87 4          soumik     700        200        0

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x62020b87 7          soumik     700        1

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Critical section locked
Old Ticket Number : 1001
New Ticket Number : 1002
Unlocked Critical Section
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Critical section locked
Old Ticket Number : 1002
New Ticket Number : 1003
Unlocked Critical Section
soumik@soumik-VirtualBox:~/SS_HandsOnList2$

============================================================================
*/
