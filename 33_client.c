/*
============================================================================
Name : 33_client.c
Author : Soumik Pal
Description : Write a program to communicate between two machines using socket.
Date: 20th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		perror("Error in socket creation");
		exit(0);
	}
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(8888);
	int retval = connect(sockfd, (const struct sockaddr *)&server, sizeof(struct sockaddr_in));
	if(retval == -1)
	{
		perror("Error in connecting to server");
		exit(0);
	}
	printf("Client successfully connected to server\n");

	char buffer1[] = "Hello Server\n";
	char buffer2[1024];
	write(sockfd, buffer1, sizeof(buffer1));
	read(sockfd, buffer2, sizeof(buffer2));
	printf("Server message received in client : %s\n", buffer2);

	sleep(1);
	close(sockfd);
	printf("Client closed connections\n");
}

/*
==========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 33_server.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 23748
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Server has created socket, binded and listening on 127.0.0.1:8888
 It is now blocked waiting for an incoming connection

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ netstat -anp | grep 8888
(Not all processes could be identified, non-owned process info
 will not be shown, you would have to be root to see it all.)
tcp        0      0 127.0.0.1:8888          0.0.0.0:*               LISTEN      23748/./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 33_client.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Client successfully connected to server
Server has accepted client connection
Client message received in Server : Hello Server

Server message received in client : Hello Client

Client closed connections
Server closed connections
[1]+  Done                    ./a.out

=========================================================================
*/
