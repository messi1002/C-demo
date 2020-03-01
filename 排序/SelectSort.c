#include <stdio.h>    

#define OK 0
#define ERROR 1
#define MAXSIZE 20

typedef struct
{
	// 用于存储要排序数组，r[0]用作哨兵或临时变量。 
	int r[MAXSIZE+1];
	int length;		
} List;

void swap(List* ll, int i, int j) 
{ 
	int temp = ll->r[i]; 
	ll->r[i] = ll->r[j]; 
	ll->r[j] = temp; 
}

void print(List l)
{
	int i;
	
	for (i = 1; i <= l.length; i++)
	{
		printf("%d", l.r[i]);	
			  
    	if (i < l.length)
    	{
      		printf(" ");
   		}
	}
}

// 简单选择排序。 
void simpleChoiceSort(List* ll)
{
	int i, j, min;
	
	// 模板还是简单排序的模板，但是里面的处理不同。 
	for (i = 1; i < ll->length; i++)
	{
		// 将当前下标定义为最小值下标。 
		min = i;
		
		for (j = i+1; j <=ll->length; j++)
		{
			// 在一次内层循环中，找到最小值。 
			if (ll->r[min] > ll->r[j])
			{
				min = j;
			}
		}
		
		// 将循环中找到的最小值与第i个值交换。 
		if (i != min)
		{
			swap(ll, i, min);
		}
	} 
	
	printf("\n简单选择排序！\n");
	print(*ll);
}	    	
	    	
// 堆排序。	    	
void heapSort(List* ll)
{
	
}

int main()
{
	List l;
    int i;
	srand(0);

    for (i = 1; i <= MAXSIZE; i++)
    {
    	l.r[i] = rand() % 101;  
	}

	l.length = MAXSIZE;
	printf("随机顺序！\n");
	print(l);
	
// 简单选择排序：通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i(1<=i<=n)个记录交换之。 
	// 最大的特点是交换移动数据次数相当少，但是比较次数还是和傻瓜排序一样多，所以总的时间复杂度还是O(n^2)。
	// 简单选择排序性能上略优于冒泡排序。 
	simpleChoiceSort(&l);	
	  
// 堆排序。    	
 	heapSort(&l);
	    	
	return 0;
} 
