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

// ��ѡ������ 
void simpleChoiceSort(List* ll)
{
	int i, j, min;
	
	// ģ�廹�Ǽ������ģ�壬��������Ĵ���ͬ�� 
	for (i = 1; i < ll->length; i++)
	{
		// ����ǰ�±궨��Ϊ��Сֵ�±ꡣ 
		min = i;
		
		for (j = i+1; j <=ll->length; j++)
		{
			// ��һ���ڲ�ѭ���У��ҵ���Сֵ�� 
			if (ll->r[min] > ll->r[j])
			{
				min = j;
			}
		}
		
		// ��ѭ�����ҵ�����Сֵ���i��ֵ������ 
		if (i != min)
		{
			swap(ll, i, min);
		}
	} 
	
	printf("\n��ѡ������\n");
	print(*ll);
}	    	
	    	
// ������	    	
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
	printf("���˳��\n");
	print(l);
	
// ��ѡ������ͨ��n-i�ιؼ��ּ�ıȽϣ���n-i+1����¼��ѡ���ؼ�����С�ļ�¼�����͵�i(1<=i<=n)����¼����֮�� 
	// �����ص��ǽ����ƶ����ݴ����൱�٣����ǱȽϴ������Ǻ�ɵ������һ���࣬�����ܵ�ʱ�临�ӶȻ���O(n^2)��
	// ��ѡ������������������ð������ 
	simpleChoiceSort(&l);	
	  
// ������    	
 	heapSort(&l);
	    	
	return 0;
} 
