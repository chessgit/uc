/*
	开三个线程，每个在屏幕打字。
	一开始都等待
	输入1 开始一个线程，2 全部都给机会，3 全部等待	
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int flag=1;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c=PTHREAD_COND_INITIALIZER;
void* func(void *p)
{
	while(1)
	{
		pthread_mutex_lock(&m);
		if(flag) pthread_cond_wait(&c,&m);//解锁，给其他人机会，当收到信号，就加锁。
		write(0,p,strlen(p)+1);
		pthread_mutex_unlock(&m);
		sleep(1);
	}
}


int main()
{
	printf("玉颜琼楼open\n");
	pthread_t threadid1,threadid2,threadid3;
	pthread_create(&threadid1,0,func,"啊～");
	pthread_create(&threadid2,0,func,"嗯～");
	pthread_create(&threadid3,0,func,"呼～");
	while(1)	
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='1')
			flag=0,pthread_cond_signal(&c);
		else if(ch=='2')
			pthread_cond_broadcast(&c),flag=0;
		else if(ch=='3')
			flag=1;
		else if(ch=='4')
			{
				pthread_cancel(threadid1);
				pthread_cancel(threadid2);
				pthread_cancel(threadid3);
				break;
			}
			
	}
	printf("今天进账10k！\n");
}

