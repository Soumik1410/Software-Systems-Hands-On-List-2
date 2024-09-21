/*
============================================================================
Name : 20_p1.c
Author : Soumik Pal
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int status = mkfifo("fifoq20", S_IRWXU);
	if(status == -1)
	{
		perror("Error during fifo creation");
		exit(0);
	}
	int fd = open("fifoq20", O_WRONLY, 0);
	if(fd < 0)
	{
		perror("Error during file opening");
		exit(0);
	}
	char buf[]="Hello World\n";
	int retval = write(fd, buf, sizeof(buf));
	if(retval < 0)
	{
		perror("Error during write call");
		exit(0);
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 20_p1.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 4562
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 20_p2.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Data received : Hello World

[1]+  Done                    ./a.out

===========================================================================
*/
