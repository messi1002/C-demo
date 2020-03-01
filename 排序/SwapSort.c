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

// ��򵥵Ľ�������Ч�ʺܵͣ�û���κμ���(ÿһ���ؼ������������йؼ��ֱȽϣ����򽻻�)�� 
void primaryBubbleSort(List* ll)
{
	int i, j;
	
	// i�ķ�Χ��1~n-1�����һ�β���Ҫ�Ƚϡ� 
	for (i = 1; i < ll->length; i++)
  	{
  		// j�ķ�Χ��i+1~n�� 
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

// ��ͳ��ð�����򷽷��� 
void bubbleSort(List* ll)
{
	int i, j;
	
	// i�ķ�Χ��1~n-1�����һ�β���Ҫ�Ƚϡ� 
	for (i = 1; i < ll->length; i++)
  	{
  		// j�ķ�Χ��n-1~i���Ӻ���ǰѭ����
		// ������������֮��ÿ�ν��бȽϣ�ǰһ�����ִ��򽻻�������ÿ�ν�С��������ͬ���ݰ������������棬���Գ�Ϊð�����򷨡�   
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

// ð��������Ż��� 
void advancedBubbleSort(List* ll)
{
	// flag���һЩ���������ִ���˼����ڲ�ѭ����������Ȼ���򣬴�ʱʣ�µ�ѭ������Ҫ��ִ�С�
	// ���������Ѿ��������������������ѭ���жϡ� 
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
        		flag = 1;// ��ѭ���ڳ�ʼֵΪ0���������ݽ�������flagΪ1������ѭ���� 
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
	printf("���˳��\n");
	print(l);

// Bubble Sort�������Ƚ����ڼ�¼�Ĺؼ��֣���������򽻻���ֱ��û�з���ļ�¼Ϊ֮��
// �Ľ�������������Ӷȣ�O(n)(˳��)���������Ӷȣ�O(n^2)(����)�� 
	// ɵ�ϰ档 
	primaryBubbleSort(&l);
    // ��ͨ�档 
	bubbleSort(&l);	
	// �Ľ��档 
	advancedBubbleSort(&l);

// ��������	
	
	return 0;
} 
