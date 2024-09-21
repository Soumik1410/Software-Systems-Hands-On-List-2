/*
============================================================================
Name : 34a_client.c
Author : Soumik Pal
Description : Write a program to create a concurrent server.
a. use fork
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
=============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 34a_server.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 24585
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Server set up with socket binded and listening on port 8888
Server going to sleep for 20 seconds
Allowing up to 5 conccurent connections to be pending
Then it will serve all at the same time

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ netstat -anp | grep 8888
(Not all processes could be identified, non-owned process info
 will not be shown, you would have to be root to see it all.)
tcp        0      0 127.0.0.1:8888          0.0.0.0:*               LISTEN      24585/./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 34a_client.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Server connected with client 1
Server connected with client 2
Server connected with client 3
Message received from client 1 : My Client ID is : 1059
Server connected with client 4
Message received from client 2 : My Client ID is : 1060
Server connected with client 5
Message received from client 3 : My Client ID is : 1101
Message received from client 4 : My Client ID is : 1152
Message received from client 5 : My Client ID is : 1517

==============================================================================
*/
