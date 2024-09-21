/*
============================================================================
Name : 30b.c
Author : Soumik Pal
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
	int shmid = shmget(key, 20, IPC_CREAT | S_IRWXU);
	if(shmid == -1)
	{
		perror("Error");
		exit(0);
	}
	void * ptr = shmat(shmid, NULL, SHM_RDONLY);
	if(ptr == (void *)-1)
	{
		perror("Error");
		exit(0);
	}
	printf("Successfully attached in Read Only Mode\n");
	char *str = (char *)ptr;
	printf("Enter a string to overwrite shared memory contents\n");
	scanf("%[^\n]s",str);
	printf("This should not be printed as there should be an error before this\n");
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 30b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Successfully attached in Read Only Mode
Enter a string to overwrite shared memory contents
Hello
Segmentation fault (core dumped)

===========================================================================
*/
