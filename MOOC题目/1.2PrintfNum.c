// 实现函数PrintN,使得传入一个正整数为N的参数后,顺序打印从1-N的全部正整数。

#include <stdio.h>

void f1(int num);
void f2(int num);

int main(void)
{
	int num;
	scanf("%d", &num);
	
	f1(num);
	printf("\n----------------------------\n"); 
	f2(num);
	
	return 0;
}

// 循环实现。
void f1(int num)
{
	int i;
	
	for (i = 1; i <= num; i++)
	{
		printf("\t%d", i);
		
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}	
}

// 递归实现。
// 对于递归函数,执行到100000时,空间不够,非正常终止。 
void f2(int num)
{
	if (num)
	{
		f2(num - 1);

		printf("\t%d", num);	
		
		if (num % 10 == 0)
		{
			printf("\n");
		}
	}
	
	return;
}
