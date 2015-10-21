#include <iostream>
using namespace std;




//排序：冒泡、插入、选择、快速
template<typename T>
void bubble(T &a, int n)
{//0.515279

	bool changed;
	do
	{
		changed = false;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1]>a[i])
			{
				swap(a[i-1], a[i]);
				changed = true;
			}
				
		}
		--n;
	} while (changed);
}

void insert_sort(int *a, int n)
{//0.170691
	int j;
	for (int i = 1; i < n; i++)
	{
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

void select2(int *a, int n)
{//错误版本
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = a[i];
		for (int j = i; j < n; j++)
		{
			if (a[j] < min)
				min = a[j];
		}
		swap(a[i], min);
	}
}

void select(int *a, int n)
{//0.155358 记得交换的是数组里面的内容，不是复制出来的内容，所以要知道最小值的位置，不是他的值
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}


//将有序数组a[]和b[]合并到c[]中
void MemeryArray(int a[], int n, int b[], int m, int c[])
{
	int i, j, k;

	i = j = k = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++]; 
	}

	while (i < n)
		c[k++] = a[i++];

	while (j < m)
		c[k++] = b[j++];
}

//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{//0.00095
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

void quick_sort(int *a, int n)
{//0.000852
	if (n <= 1)return;//n==1 zhe ge tiao jian you cuo wu 
	if (n == 2)
	if (a[1] > a[0])
	{
		swap(a[1], a[0]);
		return;
	}
	int *l = a + 1;
	int *r = a + n - 1;
	swap(a[0], a[n/2]);
	while (l < r)
	{
		while (*l < a[0] && l < r)++l;
		while (*r >= a[0] && r>a)--r;
		if (l < r)
			swap(*l, *r);
	}
	if (*r < a[0])
		swap(a[0], *r);
	quick_sort(a, r-a);
	quick_sort(r + 1, n - (r - a) - 1);
}





void swap(int a[],int lh,int rh)
{
	int x=a[lh];
	a[lh]=a[rh];
	a[rh]=x;
}

int med3(int x[], int a, int b, int c) {
        return x[a] < x[b] ? (x[b] < x[c] ? b : x[a] < x[c] ? c : a)
                : x[b] > x[c] ? b : x[a] > x[c] ? c : a;
  }

 void qsort6(int a[], int p, int r) {
        if (p >= r)
            return;

        // 在数组大小小于7的情况下使用快速排序
        if (r - p + 1 < 7) {
          for (int i = p; i <= r; i++) {
                int t = a[i];
                int j = i;
                for (; j > p && a[j - 1] > t; j--) {
                    a[j] = a[j - 1];
                }
                a[j] = t;
            }
            return;
        }

        // 计算数组长度
        int len = r - p + 1;
        // 求出中点，大小等于7的数组直接选择中数
        int m = p + (len >> 1);
        // 大小大于7
        if (len > 7) {
            int l = p;
            int n = p + len - 1;
            if (len > 40) { // 大数组，采用median-of-nine选择
                int s = len / 8;
                l = med3(a, l, l + s, l + 2 * s); // 取样左端点3个数并得出中数
                m = med3(a, m - s, m, m + s); // 取样中点3个数并得出中数
                n = med3(a, n - 2 * s, n - s, n); // 取样右端点3个数并得出中数
            }
            m = med3(a, l, m, n); // 取中数中的中数,median-of-three
        }
        // 交换pivot到左端点，后面的操作与qsort4相同
        swap(a, p, m);
        m = p;
        int j = r + 1;
        int x = a[p];
        while (true) {
            do {
                m++;
            } while (m <= r && a[m] < x);
            do {
                j--;
            } while (a[j] > x);
            if (j < m)
                break;
            swap(a, m, j);
        }
        swap(a, p, j);
        qsort6(a, p, j - 1);
        qsort6(a, j + 1, r);

    }






int main()
{
	const int N = 1000000;
	int a[N];
	int temp[N];
	for (int i = 0; i < N; i++)
	{
		a[i] =1;
	}
	cout << endl;
	clock_t t1 = clock();
	//quick_sort(a, N);//0.078395
	//mergesort(a,0,999999,temp);//0.155327
	qsort6(a,0,999999);
	clock_t t2 = clock();
	cout << double(t2 - t1) / CLOCKS_PER_SEC  << endl;
}
