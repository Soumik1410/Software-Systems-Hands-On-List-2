/*
============================================================================
Name : 34b_client.c
Author : Soumik Pal
Description : Write a program to create a concurrent server.
b. use pthread_create
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#include<errno.h>
int main()
{
	srand(time(NULL));
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	int retval = connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr_in));
	if(retval == -1)
	{
		perror("Error in connecting to server");
		exit(0);
	}
	int id = 1000 + rand()%1000;
	char buffer[1024];
	sprintf(buffer, "My Client ID is : %d", id);
	write(sockfd, buffer, sizeof(buffer));
	close(sockfd);
}

/*
=========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 34b_server.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 26243
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Server set up with socket binded and listening on port 8888
Server going to sleep for 20 seconds
Allowing up to 3 conccurent connections to be pending
Then it will serve all at the same time

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 34b_client.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Server connected with client 0
Message received from client 1 : My Client ID is : 1086
Server connected with client 1
Message received from client 2 : My Client ID is : 1035
Server connected with client 2
Message received from client 3 : My Client ID is : 1951

==========================================================================
*/

