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
	
	printf("������ʾ쳲��������У�\n");
	a[0] = 0;
	a[1] = 1;
	printf("%d %d ", a[0], a[1]);  
	  
	for (i = 2; i < 10; i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
	printf("\n");
	
	printf("�ݹ���ʾ쳲��������У�\n");
	for (i = 0; i < 10; i++)  
	{ 
		// ÿ�δ�ӡ��Ҫ�ݹ顣 
		printf("%d ", Fbi(i));  
	} 
	
	return 0;
}
