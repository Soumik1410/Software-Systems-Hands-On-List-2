/*
============================================================================
Name : 30c.c
Author : Soumik Pal
Description : Write a program to create a shared memory.
c. detach the shared memory
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	int key = ftok(".",'a');
	int shmid = shmget(key, 20, 0);
	void * ptr = shmat(shmid, NULL, 0);
	if(ptr == (void *)-1)
	{
		perror("Error in attaching");
		exit(0);
	}
	printf("Successfully attached shared memory to address space\n");
	printf("Sleeping for 10 seconds then it will detach\n");
	sleep(10);
	int ret = shmdt(ptr);
	if(ret == -1)
	{
		perror("Error in detaching");
		exit(0);
	}
	printf("Successfully detached shared memory to address space\n");
}

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 30c.c 
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 15490
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Successfully attached shared memory to address space
Sleeping for 10 seconds then it will detach

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x61020b87 1          soumik     700        20         1                       

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Successfully detached shared memory to address space

[1]+  Done                    ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x61020b87 1          soumik     700        20         0                       


=============================================================================
*/
