/*
============================================================================
Name : 30d.c
Author : Soumik Pal
Description : Write a program to create a shared memory.
d. remove the shared memory
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
	int ret = shmctl(shmid, IPC_RMID, NULL);
	if(ret == -1)
	{
		perror("Error in removing the shared memory");
		exit(0);
	}
}

/*
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 30d.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x61020b87 1          soumik     700        20         0

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status

==============================================================================
*/
