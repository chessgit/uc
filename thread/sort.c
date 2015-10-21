#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{//主线程输出数字，辅助线程完成排序
	int a[10]={0};
puts("请输入10个数字：");
	int i;
	for(i=0;i<10;i++)
	{
		printf("请输入的%d个数据：",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		int t=a[i];
		int j;
		for(j=i;j>0&&t<a[j-1];j--)//t<a[j-1] 不能写成a[j]<a[j-1] 
			a[j]=a[j-1];
		a[j]=t;
	}

	printf("main\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
}
