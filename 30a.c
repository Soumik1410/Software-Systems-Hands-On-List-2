/*
============================================================================
Name : 30a.c
Author : Soumik Pal
Description : Write a program to create a shared memory.
a. write some data to the shared memory
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
	int key = ftok(",",'a');
	int shmid = shmget(key, 20, IPC_CREAT | S_IRWXU);
	void * ptr = shmat(shmid, NULL, 0);
	if(ptr == (void *)-1)
	{
		perror("Error in attaching shared mem segment");
		exit(0);
	}
	char *str = (char *)ptr;
	printf("Enter a string\n");
	scanf("%[^\n]s", str);
	printf("String written into shared memory segment.\n");
}

/*
=============================================================================

Program Content :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 30a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Enter a string
Hello
String written into shared memory segment.
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0xffffffff 0          soumik     700        20         0

===============================================================================
*/
