/*
============================================================================
Name : 33_server.c
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
	struct sockaddr_in server, client;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(8888);
	int retval = bind(sockfd, (const struct sockaddr *)&server, sizeof(struct sockaddr_in));
	if(retval == -1)
	{
		perror("Error in socket binding");
		exit(0);
	}
	retval = listen(sockfd, 1);
	if(retval == -1)
	{
		perror("Error in setting socket to listen");
		exit(0);
	}
	printf("Server has created socket, binded and listening on 127.0.0.1:8888\n It is now blocked waiting for an incoming connection\n");
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int connfd = accept(sockfd, (struct sockaddr *)&client, &addrlen);
	if(connfd == -1)
	{
		perror("Error in accpeting client connection");
		exit(0);
	}
	printf("Server has accepted client connection\n");

	char buffer1[1024];
	char buffer2[] = "Hello Client\n";
	read(connfd, buffer1, sizeof(buffer1));
	printf("Client message received in Server : %s\n",buffer1);
	write(connfd, buffer2, sizeof(buffer2));

	sleep(1);
	close(connfd);
	close(sockfd);
	printf("Server closed connections\n");
}
	
/*
=============================================================================

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

=============================================================================
*/
