#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
sem_t m;
void *func(void *p)
{//辅助线程排序
	int i;
	int *a=p;
	for(i=0;i<10;i++)
	{
		sem_wait(&m);
		int t=a[i];
		int j;
		for(j=i;j>0&&t<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=t;
	}


}

int main()
{//主线程输出数字，辅助线程完成排序
	pthread_t thread_id;
	int a[10]={0};
	sem_init(&m,0,0);
	pthread_create(&thread_id,NULL,func,&a);
	puts("请输入10个数字：");
	int i;
	for(i=0;i<10;i++)
	{
		printf("请输入的%d个数据：",i);
		scanf("%d",&a[i]);
		sem_post(&m);
	}
	usleep(1);//等待最后一个排序完毕
	printf("main\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	sem_destory(&s);
}
