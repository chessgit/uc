#include <pthread.h>
#include <stdio.h>

void *func(void *p)
{
	int i;
	for(i=*(int*)p;i>0;i--)
	{
		write(0,"thread\n",sizeof("thread\n"));
		sleep(1);
	}
	return (void*)32432;
}
int main()
{
	pthread_t thread_id;
	int x=10;
	pthread_create(&thread_id,NULL,func,&x);//运行func(&x)
	int i;
	for(i=x;i>0;i--)
	{
		write(0,"main\n",sizeof("main\n"));
		sleep(1);
	}
	void* tmp;
	puts("线程返回值：");
	pthread_join(thread_id,&tmp);
	printf("%d\n",(int)tmp);
}


/*
	pthread_join(pthread_t threadid,void **rh)
	{
		fun(&threadid,&rh);
	}
*/
