#include <stdio.h>

int Fbi(int i)
{
	if (i == 0)
	{
		return 0;
	}	
	else if (i == 1)
	{
		return 1;
	}
	else
	{
		return Fbi(i-1) + Fbi(i-2);
	}
}

int main()
{
	int i, a[10];  
	
	printf("迭代显示斐波那契数列：\n");
	a[0] = 0;
	a[1] = 1;
	printf("%d %d ", a[0], a[1]);  
	  
	for (i = 2; i < 10; i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
	printf("\n");
	
	printf("递归显示斐波那契数列：\n");
	for (i = 0; i < 10; i++)  
	{ 
		// 每次打印都要递归。 
		printf("%d ", Fbi(i));  
	} 
	
	return 0;
}
