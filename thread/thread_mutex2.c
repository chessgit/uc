#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

const char* list[10]={"第1个客人","第2个客人","第3个客人","第4个客人","第5个客人","第6个客人","第7个客人","第8个客人","第9个客人","第10个客人"};
int pos=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
void* func(void *p)
{
	while(1)
	{
		pthread_mutex_lock(&m);
		if(pos>=10)break;
		printf("\n%s号 服务%s\n",(char*)p,list[pos++]);
		printf("服务了1个小时\n");
		pthread_mutex_unlock(&m);
		sleep(10);
	}
	pthread_mutex_unlock(&m);
}

int main()
{
	printf("玉颜琼楼open\n");
	pthread_t threadid1,threadid2,threadid3;
	pthread_create(&threadid1,0,func,"1");
	pthread_create(&threadid2,0,func,"2");
	pthread_create(&threadid3,0,func,"3");
	pthread_join(threadid1,NULL);
	pthread_join(threadid2,NULL);
	pthread_join(threadid3,NULL);
	printf("今天进账10k！\n");
}

