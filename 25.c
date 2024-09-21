/*
============================================================================
Name : 25.c
Author : Soumik Pal
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<sys/types.h>
#include<errno.h>
#include<time.h>
int main()
{
	int key = ftok(".", 'A');
	int msgid = msgget(key, IPC_CREAT|S_IRWXU);
	if(msgid == -1)
	{
		perror("Error");
		exit(0);
	}
	struct msqid_ds buf;
	int status = msgctl(msgid, IPC_STAT, &buf);
	if(status == -1)
	{
		perror("Error in getting message queue details in IPC_STAT operation");
		exit(0);
	}
	printf("Access permission = %d\nUid = %d\nGid = %d\nTime of last message sent = %ld\nTime of last message received = %ld\nTime of last change in the message queue = %ld\nSize of the queue = %lu\nNumber of messages in the queue = %lu\nMaximum number of bytes allowed = %lu\nPid of the msgsnd = %d\nPid of msgrcv = %d\n", buf.msg_perm.mode, buf.msg_perm.uid, buf.msg_perm.gid, buf.msg_stime, buf.msg_rtime, buf.msg_ctime, buf.msg_cbytes, buf.msg_qnum, buf.msg_qbytes, buf.msg_lspid,buf.msg_lrpid);

}

/*
===============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 25.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Access permission = 448
Uid = 1000
Gid = 1000
Time of last message sent = 0
Time of last message received = 0
Time of last change in the message queue = 1726730319
Size of the queue = 0
Number of messages in the queue = 0
Maximum number of bytes allowed = 16384
Pid of the msgsnd = 0
Pid of msgrcv = 0

================================================================================
*/
