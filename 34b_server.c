/*
============================================================================
Name : 34b_server.c
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
#include<errno.h>
#include<pthread.h>
struct thread_data
{
	int counter;
	int fd;
};
void *thread_func(void *arg)
{
	struct thread_data *data = (struct thread_data *)arg;
	int count = data->counter;
	int connfd = data->fd;
        char buffer[1024];
        while((read(connfd, buffer, sizeof(buffer))) <= 0);
        printf("Message received from client %d : %s\n", count, buffer);
}
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
	server.sin_port = htons(8888);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	int retval = bind(sockfd, (const struct sockaddr *)&server, sizeof(struct sockaddr_in));
	if(retval == -1)
	{
		perror("Error in binding socket");
		exit(0);
	}

	retval = listen(sockfd, 3);
	printf("Server set up with socket binded and listening on port 8888\nServer going to sleep for 20 seconds\nAllowing up to 3 conccurent connections to be pending\nThen it will serve all at the same time\n");
	sleep(20);
	int i=0;
	pthread_t tid[3];
	while(1)
	{
		socklen_t addrlen = sizeof(struct sockaddr_in);
		int connfd = accept(sockfd, (struct sockaddr *)&client, &addrlen);
		if(connfd < 0)
		{
			perror("Error in connecting to client");
			exit(0);
		}
		printf("Server connected with client %d\n",i);
		struct thread_data data;
		data.counter = i+1;
		data.fd = connfd;
		int retval = pthread_create(&tid[i], NULL, thread_func, &data);
		pthread_join(tid[i], NULL);
		i++;
		close(connfd);
	}
}	

/*
===============================================================================

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

===============================================================================
*/
