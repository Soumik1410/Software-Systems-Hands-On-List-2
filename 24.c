/*
============================================================================
Name : 24.c
Author : Soumik Pal
Description : Write a program to create a message queue and print the key and message queue id.
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
int main()
{
	key_t key = ftok(".",'A');
	int msgid = msgget(key, IPC_CREAT|S_IRWXU);
	printf("key = %d\nid = %d\n",key,msgid);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 24.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
key = 1090653063
id = 1
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x41020b87 1          soumik     700        0            0

============================================================================
*/
