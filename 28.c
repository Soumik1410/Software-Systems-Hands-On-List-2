/*
============================================================================
Name : 28.c
Author : Soumik Pal
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	struct msqid_ds buf;
	int key = ftok(".",'a');
	int msgid = msgget(key, 0);
	int ret = msgctl(msgid, IPC_STAT, &buf);
	if(ret == -1)
	{
		perror("Error in IPC_STAT call");
		exit(0);
	}
	buf.msg_perm.mode=(S_IRUSR | S_IWUSR);
	ret = msgctl(msgid, IPC_SET, &buf);
	if(ret == -1)
	{
		perror("Error in IPC_SET call");
		exit(0);
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 28.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     700        0            0

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61020b87 2          soumik     600        0            0

===========================================================================
*/
