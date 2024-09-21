/*
============================================================================
Name : 21_p2.c
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
	int fd = open("fifoq21", O_RDWR, 0);
	if(fd < 0)
	{
		perror("Error during file opening");
		exit(0);
	}
	char buf[50];
        int retval = read(fd, buf, sizeof(buf));
        if(retval < 0)
        {
                perror("Error during reading");
                exit(0);
        }
        printf("Process 1's message : %s\n", buf);

	char buf2[]="Hi Process 1";
	retval = write(fd, buf2, sizeof(buf2));
	if(retval < 0)
	{
		perror("Error during writing");
		exit(0);
	}
}

/*
===========================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 21_p1.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out &
[1] 5090
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 21_p2.c
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Process 1's message : Hi Process 2

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ Process 2's message : Hi Process 1

[1]+  Done                    ./a.out

============================================================================
*/
