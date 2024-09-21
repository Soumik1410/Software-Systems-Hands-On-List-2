/*
============================================================================
Name : 21_p1.c
Author : Soumik Pal
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 19th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int status = mkfifo("fifoq21", S_IRWXU);
	if(status == -1)
	{
		perror("Error during pipe file creation");
		exit(0);
	}
	int fd = open("fifoq21", O_RDWR, 0);
	if(fd < 0)
	{
		perror("Error during file opening");
		exit(0);
	}
	char buf[]="Hi Process 2\n";
	int retval = write(fd, buf, sizeof(buf));
	if(retval < 0)
	{
		perror("Error during writing");
		exit(0);
	}
	sleep(10);
	char buf2[50];
	retval = read(fd, buf2, sizeof(buf2));
	if(retval < 0)
	{
		perror("Error during reading");
		exit(0);
	}
	printf("Process 2's message : %s\n", buf2);
}

/*
========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 21_p1.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 5090
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 21_p2.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Process 1's message : Hi Process 2

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Process 2's message : Hi Process 1

[1]+  Done                    ./a.out

========================================================================
*/
