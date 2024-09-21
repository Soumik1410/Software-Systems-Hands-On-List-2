/*
============================================================================
Name : 26.c
Author : Soumik Pal
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include<fcntl.h>
struct mymsg
{
	long mtype;
	char mtext[10];
};
int main()
{
	int key = ftok(".",'a');
	int msgid = msgget(key, IPC_CREAT | S_IRWXU);
	struct mymsg msg = {1, "Hello"};
	int ret = msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
	if(ret == -1)
	{
		perror("Error in sending message");
		exit(0);
	}
}

/*
=============================================================================

Progra Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 26.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     700        10           1

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     700        20           2

=============================================================================
*/
