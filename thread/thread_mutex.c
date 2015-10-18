#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
pthread_mutex_t m;//pthread_mutex_t m=INITIALIZER;
void *func(void *p)
{//辅助线程排序
	pthread_mutex_lock(&m);
	int i;
	int *a=p;
	for(i=0;i<10;i++)
	{
		int t=a[i];
		int j;
		for(j=i;j>0&&t<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=t;

printf("\n****************\n");
for(i=0;i<10;i++)
{
	printf("%d ",a[i]);
}
printf("\n****************\n");

		pthread_mutex_unlock(&m);
		usleep(1);
		//pthread_mutex_lock(&m);
	}

	printf("main\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
}

int main()
{//主线程输出数字，辅助线程完成排序
	pthread_t thread_id;
	int a[10]={0};
	pthread_mutex_init(&m,NULL);
	pthread_mutex_lock(&m);
	pthread_create(&thread_id,NULL,func,&a);
	puts("请输入10个数字：");
	int i;
	for(i=0;i<10;i++)
	{
		printf("请输入的%d个数据：",i);
		scanf("%d",&a[i]);
		pthread_mutex_unlock(&m);
		usleep(1);
		pthread_mutex_lock(&m);
	}
	pthread_mutex_unlock(&m);

}
