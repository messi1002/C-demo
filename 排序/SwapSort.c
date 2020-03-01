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

// 最简单的交换排序，效率很低，没有任何技巧(每一个关键字与其后的所有关键字比较，大则交换)。 
void primaryBubbleSort(List* ll)
{
	int i, j;
	
	// i的范围是1~n-1，最后一次不需要比较。 
	for (i = 1; i < ll->length; i++)
  	{
  		// j的范围是i+1~n。 
    	for (j = i+1; j <= ll->length; j++)
    	{
      		if (ll->r[i] > ll->r[j])
      		{
        		swap(ll, i, j);
      		}
    	}
	}
	
	printf("\nprimaryBubbleSort!\n");
	print(*ll);
} 

// 传统的冒泡排序方法。 
void bubbleSort(List* ll)
{
	int i, j;
	
	// i的范围是1~n-1，最后一次不需要比较。 
	for (i = 1; i < ll->length; i++)
  	{
  		// j的范围是n-1~i，从后往前循环。
		// 相邻数字两两之间每次进行比较，前一个数字大则交换，这样每次较小的数字如同气泡般慢慢浮到上面，所以称为冒泡排序法。   
    	for (j = ll->length-1; j >= i; j--)
    	{
      		if (ll->r[j] > ll->r[j+1])
      		{
        		swap(ll, j, j+1);
      		}
    	}
	}
		
	printf("\nbubbleSort!\n");
	print(*ll);
} 

// 冒泡排序的优化。 
void advancedBubbleSort(List* ll)
{
	// flag针对一些情况：如在执行了几次内层循环后，数据已然有序，此时剩下的循环不需要再执行。
	// 即避免因已经有序的情况下做无意义的循环判断。 
	int i, j;
	int flag = 1;
	 
	for (i = 1; i < ll->length && flag; i++)
  	{
  		flag = 0;
  		
    	for (j = ll->length-1; j >= i; j--)
    	{
      		if (ll->r[j] > ll->r[j+1])
      		{
        		swap(ll, j, j+1);
        		flag = 1;// 在循环内初始值为0，若有数据交换，则flag为1，继续循环。 
      		}
    	}
	}
		
	printf("\nadvancedBubbleSort!\n");
	print(*ll);
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

// Bubble Sort：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为之。
// 改进版的最好情况复杂度：O(n)(顺序)、最坏情况复杂度：O(n^2)(逆序)。 
	// 傻瓜版。 
	primaryBubbleSort(&l);
    // 普通版。 
	bubbleSort(&l);	
	// 改进版。 
	advancedBubbleSort(&l);

// 快速排序：	
	
	return 0;
} 
