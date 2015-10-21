#include <iostream>
using namespace std;

void qsort(int a[], int lh, int rh) 
{
        if (lh >= rh)
            return;

        // 在数组大小小于7的情况下使用快速排序
     /*   if (rh - lh + 1 < 7) {
          for (int i = lh; i <= rh; i++) {
                int t = a[i];
                int j = i;
                for (; j > lh && a[j - 1] > t; j--) {
                    a[j] = a[j - 1];
                }
                a[j] = t;
            }
            return;
        }*/

     	int i=lh;
	int j=rh;
	int x=a[i];
	while(i<j)
	{
		while(i<j&&a[j]>x)
			j--;
		if(i<j)
			a[i++]=a[j];
		while(i<j&&a[i]<x)
			i++;
		if(i<j)
			a[j--]=a[i];
	}
	a[i]=x;
        qsort(a, lh, i - 1);
        qsort(a, i + 1, rh);

}



//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] > x) // 从右向左找第一个小于x的数
				j--;  
            if(i < j) 
				s[i++] = s[j];
			
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;  
            if(i < j) 
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}


int main()
{
	const int N = 20;
	int a[N]={1,1,5,1,2,26,1,2,2,9,1,1,1,1,1,1,1,1,1,1};
	int temlh[N];
//	for (int i = 0; i < N; i++)
//	{
//		a[i] =1;
//	}
	cout << endl;
	clock_t t1 = clock();
	//quick_sort(a,0,9);//0.078395
	//mergesort(a,0,999999,temlh);//0.155327
	qsort(a,0,19);
	clock_t t2 = clock();
	cout << double(t2 - t1) / CLOCKS_PER_SEC  << endl;
	for(int i=0;i<20;i++)
	{
		cout<<a[i]<<" ";
	}
}
