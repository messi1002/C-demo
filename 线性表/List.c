#include <stdio.h>     

/* 
MAXSIZE�ǿռ��ʼ�������� 
���Ա�Χ(λ��)��1~length�� 
�����±���Ч��Χ��0~length-1�� 
*/
#define MAXSIZE 10
#define OK 0
#define ERROR 1

// ����StatusΪint�ͣ���ʾ����״̬��
typedef int Status; 

// ���ṹ��һ�������֣�Arr�� 
typedef struct Arr {
	// ������������洢����Ԫ�ء� 
	int data[MAXSIZE];
	// ���Ա�ǰ���ȡ� 
	int length;
} Arr;

/* 
�ı����Ա�Ľṹ--����ṹ��ָ�룬�ṹ��ָ�����ͨ����->��ֱ�Ӹı�ṹ�塣
���ı����Ա�Ľṹ-->����ṹ�帱���� 
*/
Status initList(Arr* la) 
{ 
    la->length = 0;
    return OK;
}
 
Status emptyList(Arr l)
{ 
	if (l.length == 0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

// ����l������Ԫ�ظ����� 
int listLength(Arr l)
{
	return l.length;
}

// ��e����l�е�i��(iָλ��)����Ԫ�ص�ֵ�� 
Status getElem(Arr l, int i, int* e)
{
	// ���ǿձ�λ��ΧΪ1~length�� 
	if (l.length == 0 || i < 1 || i > l.length)
	{
		return ERROR;
	}	
	
	// λ���1Ϊ�����±ꡣ 
	*e = l.data[i-1];
	return OK;
}

// ����l�е�1����e��ȵ�����Ԫ�ص�λ�� 
Status findElem(Arr l, int e, int* i)
{
	int j;
	
	// �������顣 
	for (j = 0; j <= l.length-1; j++)
	{
		if (l.data[j] == e)
		{
			// �����±��1����λ�� 
			*i = ++j;
			return OK;
		}
	}
	
	return ERROR;
} 
 
// ��l�е�i��λ��(λ��)֮ǰ�����µ�����Ԫ��e��l�ĳ��ȼ�1�� 
Status insertElem(Arr* la, int i, int e)
{
	int k;
	
	// ��������λ��ΧΪ1~length+1����i=length+1ʱ����ֱ�Ӳ������һ��λ�á�
	if (la->length == MAXSIZE || i < 1 || i > la->length+1)
	{
		return ERROR;
	}	
	else if (i <= la->length)
	{
		// �����±�Ϊi-1~length-1(λ��Ϊi~length)������Ԫ�����������λ�� 
		for (k = la->length-1; k >= i-1; k--)
		{
			la->data[k+1] = la->data[k];	
		}	
	}
	 
	// λ���1Ϊ�����±ꡣ
	// ����λ�ٲ��롣 
	la->data[i-1] = e;
	la->length++;
	return OK;
}

// ɾ��l�ĵ�i������Ԫ��(λ��)������e������ֵ��l�ĳ��ȼ�1�� 
Status deleteElem(Arr* la, int i, int* e)
{
	int k;
	
	// ���ǿձ�λ��ΧΪ1~length�� 
	if (la->length == 0 || i < 1 || i > la->length)
	{
		return ERROR;
	}	 
	else if (i <= la->length)
	{
		*e = la->data[i-1];
		
		// �����±�Ϊi~length-1(λ��Ϊi+1~length)������Ԫ��������ǰ��λ�� 
		for (k = i; k <= la->length-1; k++)
		{
			la->data[k-1] = la->data[k];	
		}	
	}
 
	la->length--;
	return OK;
} 
 
// ���ζ�l��ÿ������Ԫ������� 
Status printElem(Arr l)
{
	int i;
	
    for(i = 0; i <= l.length-1; i++)
    {
		printf("%d ", l.data[i]);    	
	}

    printf("\n");
    return OK;
} 
 
int main()
{  
    Arr l;
    int i, e;
    
    // Arr* la=&l;la��һ��ָ�룬��ֵΪl�ĵ�ַ��
	// ���ڽṹ��ָ����˵������ʹ��(*la).length/la->length������ָ��Ľṹ�塣 
    i = initList(&l);
    printf("��ʼ��l��%d\n", i);
    i = listLength(l);
    printf("��ʼ��l��l.length = %d\n", i);
    
    i = emptyList(l); 
    printf("l�Ƿ�Ϊ�գ�%d\n", i);
	
	for (i = 1; i <= MAXSIZE; i++)
	{
		e = i;
		insertElem(&l, i, e);
		printf("����%d\n", i);	
	} 
	
	printf("l.length = %d\n", l.length);
	
	for (i = 1; i <= l.length; i++)
	{
		getElem(l, i, &e);
		printf("��%d��Ԫ����%d\n", i, e);	
	}
	
	printf("��ӡ����Ԫ�أ�\n");
	printElem(l); 
	
	findElem(l, 2, &i);
	printf("��һ����Ԫ��2��ȵ�Ԫ��λ��%d\n", i);
	
	i = 1;
	while (i <= 10) 
	{
		deleteElem(&l, 1, &e);
		i++;	
		printf("ɾ��%d\n", e);
	}
	
	i = emptyList(l); 
    printf("l�Ƿ�Ϊ�գ�%d\n", i);
    	
	i = listLength(l);
	printf("l.length = %d\n", i);
	
	return 0;
}
