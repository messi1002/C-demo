// ʵ�ֺ���PrintN,ʹ�ô���һ��������ΪN�Ĳ�����,˳���ӡ��1-N��ȫ����������

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

// ѭ��ʵ�֡�
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

// �ݹ�ʵ�֡�
// ���ڵݹ麯��,ִ�е�100000ʱ,�ռ䲻��,��������ֹ�� 
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
