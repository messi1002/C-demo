// 写程序计算给定多项式在给定点处的值。
// f(x) = a0 + (a1)x + ... + (an-1)x^n-1 + (an)x^n。

#include <stdio.h>
#include <math.h> 
#include <time.h>

void f1(int n, int a[], int x);
void f2(int n, int a[], int x);

int main(void)
{
	clock_t start, stop;
	double interval;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;
	int length = sizeof(a) / sizeof(a[0]);

	start = clock();
	for (i = 0; i < 100000; i++) 
	{
		f1(length, a, 2);
	}
	stop = clock();
	/* 间隔 */interval = ((double)(stop - start)) / CLK_TCK;	
	printf("interval1 = %f\n", interval);
	
	start = clock();
	for (i = 0; i < 100000; i++) 
	{
		f2(length, a, 2);
	}
	stop = clock();
	/* 间隔 */interval = ((double)(stop - start)) / CLK_TCK;
	printf("interval2 = %f\n", interval);	
		
	return 0;
}

// 普通逻辑。 
void f1(int n, int a[], int x)
{
	int i;
	int sum = a[0];
	
	for (i = 1; i <= n; i++)
	{
		sum = sum + a[i] * pow(x, i);	
	}
	// printf("sum1 = %d\n", sum);
}

// 秦九韶算法。 
void f2(int n, int a[], int x)
{
	int i;
	int sum = a[n];
	
	for (i = n; i > 0; i--)
	{
		sum = a[i-1] + sum * x;	
	}
	// printf("sum2 = %d\n", sum);	
}
