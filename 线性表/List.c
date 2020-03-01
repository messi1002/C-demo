#include <stdio.h>     

/* 
MAXSIZE是空间初始分配量。 
线性表范围(位序)：1~length。 
数组下标有效范围：0~length-1。 
*/
#define MAXSIZE 10
#define OK 0
#define ERROR 1

// 定义Status为int型，表示函数状态。
typedef int Status; 

// 给结构体一个新名字：Arr。 
typedef struct Arr {
	// 定义整型数组存储数据元素。 
	int data[MAXSIZE];
	// 线性表当前长度。 
	int length;
} Arr;

/* 
改变线性表的结构--传入结构体指针，结构体指针可以通过“->”直接改变结构体。
不改变线性表的结构-->传入结构体副本。 
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

// 返回l中数据元素个数。 
int listLength(Arr l)
{
	return l.length;
}

// 用e返回l中第i个(i指位序)数据元素的值。 
Status getElem(Arr l, int i, int* e)
{
	// 不是空表、位序范围为1~length。 
	if (l.length == 0 || i < 1 || i > l.length)
	{
		return ERROR;
	}	
	
	// 位序减1为数组下标。 
	*e = l.data[i-1];
	return OK;
}

// 返回l中第1个与e相等的数据元素的位序。 
Status findElem(Arr l, int e, int* i)
{
	int j;
	
	// 遍历数组。 
	for (j = 0; j <= l.length-1; j++)
	{
		if (l.data[j] == e)
		{
			// 数组下标加1返回位序。 
			*i = ++j;
			return OK;
		}
	}
	
	return ERROR;
} 
 
// 在l中第i个位置(位序)之前插入新的数据元素e，l的长度加1。 
Status insertElem(Arr* la, int i, int e)
{
	int k;
	
	// 不是满表、位序范围为1~length+1，当i=length+1时可以直接插在最后一个位置。
	if (la->length == MAXSIZE || i < 1 || i > la->length+1)
	{
		return ERROR;
	}	
	else if (i <= la->length)
	{
		// 数组下标为i-1~length-1(位序为i~length)的数据元素依次向后移位。 
		for (k = la->length-1; k >= i-1; k--)
		{
			la->data[k+1] = la->data[k];	
		}	
	}
	 
	// 位序减1为数组下标。
	// 先移位再插入。 
	la->data[i-1] = e;
	la->length++;
	return OK;
}

// 删除l的第i个数据元素(位序)，并用e返回其值，l的长度减1。 
Status deleteElem(Arr* la, int i, int* e)
{
	int k;
	
	// 不是空表、位序范围为1~length。 
	if (la->length == 0 || i < 1 || i > la->length)
	{
		return ERROR;
	}	 
	else if (i <= la->length)
	{
		*e = la->data[i-1];
		
		// 数组下标为i~length-1(位序为i+1~length)的数据元素依次向前移位。 
		for (k = i; k <= la->length-1; k++)
		{
			la->data[k-1] = la->data[k];	
		}	
	}
 
	la->length--;
	return OK;
} 
 
// 依次对l的每个数据元素输出。 
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
    
    // Arr* la=&l;la是一个指针，其值为l的地址。
	// 对于结构体指针来说，可以使用(*la).length/la->length访问它指向的结构体。 
    i = initList(&l);
    printf("初始化l：%d\n", i);
    i = listLength(l);
    printf("初始化l后：l.length = %d\n", i);
    
    i = emptyList(l); 
    printf("l是否为空：%d\n", i);
	
	for (i = 1; i <= MAXSIZE; i++)
	{
		e = i;
		insertElem(&l, i, e);
		printf("插入%d\n", i);	
	} 
	
	printf("l.length = %d\n", l.length);
	
	for (i = 1; i <= l.length; i++)
	{
		getElem(l, i, &e);
		printf("第%d个元素是%d\n", i, e);	
	}
	
	printf("打印表中元素：\n");
	printElem(l); 
	
	findElem(l, 2, &i);
	printf("第一个与元素2相等的元素位序：%d\n", i);
	
	i = 1;
	while (i <= 10) 
	{
		deleteElem(&l, 1, &e);
		i++;	
		printf("删除%d\n", e);
	}
	
	i = emptyList(l); 
    printf("l是否为空：%d\n", i);
    	
	i = listLength(l);
	printf("l.length = %d\n", i);
	
	return 0;
}
