/*
============================================================================
Name : 27b.c
Author : Soumik Pal
Description : Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date: 19th Sep, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
struct mymsg
{
	long mtype;
	char mtext[10];
};
int main()
{
	int key = ftok(".",'a');
	int msgid = msgget(key, 0);
	struct mymsg msg;
	int ret = msgrcv(msgid, &msg, sizeof(msg.mtext), 1, IPC_NOWAIT);
	if(ret == -1)
	{
		perror("Error");
		exit(0);	
	}
	printf("Message received from Queue : %s\n", msg.mtext);
}

/*
=======================================================================

Program Output :

oumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     700        10           1

soumik@soumik-VirtualBox:~/SS_HandsOnList2$
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 27b.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Message received from Queue : Hello
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     700        0            0

=======================================================================
*/
