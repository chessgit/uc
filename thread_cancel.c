#include <stdio.h>
#include <pthread.h>


void *func(void* p)
{
	puts("thread----------");
	for(;;)
	{
		puts(".");
		sleep(1);
	}
}

int main()
{
	pthread_t threadid;
	pthread_create(&threadid,NULL,func,NULL);
	sleep(1);//等待辅助线程先工作，不可靠
	puts("main----------");
	pthread_exit(NULL);
	
}
