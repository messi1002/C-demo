/*
查找算法中的“二分法”是这样定义的：给定N个从小到大排好序的整数序列List[]，以及某待查找整数X，
我们的目标是找到X在List中的下标。即若有List[i]=X，则返回i；否则返回-1表示没有找到。
二分法是先找到序列的中点List[M]，与X进行比较，若相等则返回中点下标；否则，若List[M]>X，
则在左边的子系列中查找X；若List[M]<X，则在右边的子系列中查找X。
*/

#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num); 
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(a) / sizeof(a[0]);
	int left = 0, right = length - 1;
	int flag = 0;
	
	// 如果 left <= right 继续寻找。 
	while (left <= right)
	{
		int middle = (left + right) / 2;
		
		// 右子列查找。 
		if (num > a[middle])
		{
			left = middle + 1;	
		}	
		// 左子列查找。 
		else if (num < a[middle])
		{
			right = middle - 1;
		}
		// a[middle] == num。 
		else
		{
			printf("a[%d] = %d", middle, num);
			// 找到了,跳出循环。 
			flag = 1;
			break;
		}	
	}
	
	// 没找到,返回 -1。 
	if (flag == 0)
	{
		printf("%d", -1);
	}
	
	return 0;	
} 
