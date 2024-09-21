/*
============================================================================
Name : 7.c
Author : Soumik Pal
Description : Write a simple program to print the created thread ids.
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void * thread_func(void * arg)
{
	printf("Thread ID : %lu\n", pthread_self());
}
int main()
{
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, thread_func, NULL);
	pthread_create(&t2, NULL, thread_func, NULL);
	pthread_create(&t3, NULL, thread_func, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
}

/*
============================================================================

Program Output :

soumik@soumik-VirtualBox:~/SS_HandsOnList2$ cc 7.c -lpthread
soumik@soumik-VirtualBox:~/SS_HandsOnList2$ ./a.out
Thread ID : 131116725962432
Thread ID : 131116715476672
Thread ID : 131116704990912

===========================================================================
*/
