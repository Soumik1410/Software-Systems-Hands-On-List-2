/*
============================================================================
Name : 27a.c
Author : Soumik Pal
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 19th Sep, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
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
	//printf("%d\n",msgid);
	struct mymsg msg;
	int ret = msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);
	if(ret == -1)
	{
		perror("Error");
		exit(0);
	}
	printf("Message received from Queue : %s\n", msg.mtext);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     700        20           2

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 27a.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Message received from Queue : Hello
soumik@soumik-VirtualBox:~/SS_HandsOnList2$
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61020b87 2          soumik     700        10           1           


============================================================================
*/

