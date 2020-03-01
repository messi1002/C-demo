#include <stdio.h>    

#define OK 0
#define ERROR 1
#define MAXSIZE 20

typedef struct
{
	// ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ������ 
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
	
	// ÿ�˽�һ��Ԫ�أ�������ؼ��ֵĴ�С���뵽��ǰ���Ѿ�������������У������ظ���ֱ������ȫ��Ԫ�أ���ʼΪr[1]�� 
	// ��ѭ����������Ƚϣ������߱�ǰ��С���򽫺��߸�ֵ��r[0](�ڱ�)��Ȼ���ú���֮ǰ�������Ԫ�������λ�������������ߡ����뵽�Ƴ��Ŀ�λ�С� 
	for (i = 2; i <= ll->length; i++)
	{
		if (ll->r[i] < ll->r[i-1])
		{
			// �����ڱ��� 
			ll->r[0] = ll->r[i];
			
			for (j = i-1; ll->r[j] > ll->r[0]; j--)
			{
				ll->r[j+1] = ll->r[j];			
			}
			
			// ע��forѭ����j--�ˣ��ų�ȥ����㡣 
			ll->r[j+1] = ll->r[0];
		}
	}
	
	printf("\nֱ�Ӳ�������\n");	
	print(*ll);
}

// ϣ������ 
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
	
	printf("\nϣ������\n");
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
	printf("���˳��\n");
	print(l);
	
// ֱ�Ӳ������򣺽�һ����¼���뵽�Ѿ��ź����������У��Ӷ��õ�һ���µġ���¼����1������� 
 	// ����Ҫһ����¼�ĸ����ռ�(�ڱ�)����õ������ʱ�临�Ӷ�ΪO(n)����������ʱ�临�Ӷ�ΪO(n^2)��
	// ͬ����O(n^2)ʱ�临�Ӷȣ�ֱ�Ӳ������򷨱�ð�ݺͼ�ѡ�����������Ҫ��һЩ��  
	directInsertSort(&l);
    
// ϣ�����򣺲�����Ծ�ָ�Ĳ��ԣ������ĳ�����������ļ�¼���һ�������У�
	// �������ܱ�֤���������ڷֱ����ֱ�Ӳ��������õ��Ľ��ʱ������������Ǿֲ�����
	// ���ؼ��ֽ�С�ļ�¼������һ��һ������ǰŲ����������Ծʽ����ǰ�ƣ��Ӷ�ʹ�����һ��ѭ�����������оͳ��������ʵ������һ���� 
	// ����һ���ȶ��������㷨��ʱ�临�Ӷ�ΪO(n^(3/2))�� 
	shellSort(&l);	
	
	return 0;
} 
