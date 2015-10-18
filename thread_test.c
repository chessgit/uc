#include <stdio.h>
#include <pthread.h>

//int a[20];

void *func(void* p)
{
	int *a=(int*)p;
	puts("thread----------");
	int i=0;
	int x=100;
	for(;i<20;i++)
	{
		a[i]=x++;
		sleep(1);
	}
}

int main()
{
	pthread_t threadid;
	int a[20];
	pthread_create(&threadid,NULL,func,a);
	sleep(1);//等待辅助线程先工作，不可靠
	puts("main----------");
	int i;
	for(i=0;i<20;i++)
	{
		printf("%d ",a[i]);
		fflush(stdout);
		sleep(1);
	}
	
}
