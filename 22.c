/*
============================================================================
Name : 22.c
Author : Soumik Pal
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<sys/time.h>
int main()
{
	int status = mkfifo("fifoq22", S_IRWXU);
	if(status == -1)
	{
		perror("Error during fifo creation");
		exit(0);
	}
	int fd = open("fifoq22", O_RDWR, 0);
	if(fd < 0)
	{
		perror("Error during opening file");
		exit(0);
	}
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(fd, &readfds);
	
	struct timeval tv;
	tv.tv_sec = 10;
	tv.tv_usec = 0;

	int retval = select(fd+1, &readfds, NULL, NULL, &tv);
	if(retval == -1)
	{
		perror("Error in select call");
		exit(0);
	}
	else if(retval)
	{
		printf("Data available in fifo in 10 seconds\n");
		char buf[30];
		int ret = read(fd, buf, sizeof(buf));
		if(ret < 0)
		{
			perror("Error during reading from fifo");
			exit(0);
		}
		printf("Data read from FIFO : %s\n", buf);
	}
	else
	{
		printf("Data was not made available in 10 seconds\n");
	}
}

/*
==========================================================================

Program Output : 

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 22.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 5407
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ echo 'Hello World' > fifoq22
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Data available in fifo in 10 seconds
Data read from FIFO : Hello World


[1]+  Done                    ./a.out

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 5424
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Data was not made available in 10 seconds

[1]+  Done                    ./a.out

============================================================================
*/
