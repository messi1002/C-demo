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

void directInsertSort(List* ll)
{
	int i, j;	
	
	// 每趟将一个元素，按照其关键字的大小插入到它前面已经排序的子序列中，依此重复，直到插入全部元素，初始为r[1]。 
	// 外循环中两两相比较，若后者比前者小，则将后者赋值给r[0](哨兵)，然后让后者之前比它大的元素向后移位，最后将这个“后者”插入到移出的空位中。 
	for (i = 2; i <= ll->length; i++)
	{
		if (ll->r[i] < ll->r[i-1])
		{
			// 设置哨兵。 
			ll->r[0] = ll->r[i];
			
			for (j = i-1; ll->r[j] > ll->r[0]; j--)
			{
				ll->r[j+1] = ll->r[j];			
			}
			
			// 注意for循环中j--了，才出去到外层。 
			ll->r[j+1] = ll->r[0];
		}
	}
	
	printf("\n直接插入排序！\n");	
	print(*ll);
}

// 希尔排序。 
void shellSort(List* ll)
{
	int i, j, increment;
	increment = ll->length;
	
	do
	{
		increment = increment / 2;
	
		for (i = increment + 1; i <= ll->length; i++)
		{
			if (ll->r[i] < ll->r[i-increment])
			{
				ll->r[0] = ll->r[i];
				
				for (j = i - increment; j > 0 && ll->r[0] < ll->r[j]; j -= increment)
				{
					ll->r[j+increment] = ll->r[j];
				}
				
				ll->r[j+increment] = ll->r[0];
			}
		}
	}
	while (increment > 0);
	
	printf("\n希尔排序！\n");
	print(*ll);	
}

int main()
{
	List l;
    int i;
	srand(0);
	
/*
    for (i = 1; i <= MAXSIZE; i++)
    {
    	l.r[i] = rand() % 101;  
	}*/
for (i = 1; i <= MAXSIZE; i++)
    {
    	if (i % 2 == 0)
		{ 
    	l.r[i] = 0;  
    	}
    	else {
    	l.r[i] = 1;}
	}
	l.length = MAXSIZE;
	printf("随机顺序！\n");
	print(l);
	
// 直接插入排序：将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表。 
 	// 它需要一个记录的辅助空间(哨兵)，最好的情况，时间复杂度为O(n)，最坏的情况，时间复杂度为O(n^2)。
	// 同样的O(n^2)时间复杂度，直接插入排序法比冒泡和简单选择排序的性能要好一些。  
	directInsertSort(&l);
    
// 希尔排序：采用跳跃分割的策略，将相距某个“增量”的记录组成一个子序列，
	// 这样才能保证在子序列内分别进行直接插入排序后得到的结果时基本有序而不是局部有序。
	// 将关键字较小的记录，不是一步一步地往前挪动，而是跳跃式地往前移，从而使得完成一轮循环后，整个序列就朝着有序坚实地迈进一步。 
	// 不是一种稳定的排序算法、时间复杂度为O(n^(3/2))。 
	shellSort(&l);	
	
	return 0;
} 
