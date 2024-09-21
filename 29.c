/*
============================================================================
Name : 29.c
Author : Soumik Pal
Description : Write a program to remove the message queue.
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	int key = ftok(".",'a');
	int msgid = msgget(key, 0);
	int ret = msgctl(msgid, IPC_RMID, 0);
	if(ret == -1)
	{
		perror("Error in removing MQ");
		exit(0);
	}
	printf("Successfully removed MQ\n");
}

/*
==============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 29.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     600        0            0

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Successfully removed MQ
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

===============================================================================
*/
