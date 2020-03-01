#include <stdio.h>

#define MAXSIZE 10
#define ERROR 1
#define OK 0

typedef int Status; 

typedef struct Stack {
	int data[MAXSIZE];
	// 指示栈顶元素在数组中的位置，top<=MAXSIZE-1。
	// 当栈存在一个元素时，top=0，所以空栈的判定条件为top=-1。 
	int top;
} Stack;

// 初始化一个空栈s。 
Status initStack(Stack* ss)
{  
	ss->top = -1;
    return OK;
}

// 若栈s为空栈，则返回OK，否则返回ERROR。 
Status stackEmpty(Stack s)
{ 
    if (s.top == -1)
    {
		return OK;
	}
    else
    {
        return ERROR;
    }
}

// 返回s的元素个数，即栈的长度。 
int stackLength(Stack s)
{ 
	return ++s.top;
}

// 若栈不空，则用e返回s的栈顶元素，并返回OK；否则返回ERROR。 
Status getTop(Stack s, int* e)
{
    if (s.top == -1)
    {
        return ERROR;
    }
	else
	{
        *e = s.data[s.top];
        return OK;
    }
}

// 从栈底到栈顶依次对栈中每个元素显示。 
void printStack(Stack s)
{
    int i;
        
    for (i = 0; i <= s.top; i++)
    {
        printf("%d ", s.data[i]);
    }
        
    printf("\n");
}

// 插入元素e为新的栈顶元素。 
Status Push(Stack* ss, int e)
{
	// 栈满。 
	if (ss->top == MAXSIZE-1)	
	{
		return ERROR;
	}
	
	ss->top++;
	ss->data[ss->top] = e; 
	return OK;
}

// 栈不空，则删除s的栈顶元素，用e返回其值，并返回OK；否则返回ERROR。 
Status Pop(Stack* ss, int* e)
{
	// 栈空。 
	if (ss->top == -1)
	{
		return ERROR;	
	} 
	
	*e = ss->data[ss->top];
	ss->top--;
	return OK;
}


int main()
{
	Stack s;
	int i, e;
	
	printf("初始化栈：%d\n", initStack(&s));
	printf("是否为空栈：%d\n", stackEmpty(s));
	printf("栈的长度：%d\n", stackLength(s));
	
	printf("插入栈顶元素\n");
	for (i = 0; i < MAXSIZE; i++)
	{
		Push(&s, i);
		printf("插入：%d\n", i); 
	}
	
	printf("打印栈元素：");
	printStack(s);
	
	printf("栈的长度：%d\n", stackLength(s));	
	getTop(s, &e);
	printf("栈顶元素：%d\n", e);
	
	Pop(&s, &e);	
	printf("删除栈顶元素：%d\n", e);
	
	printf("栈的长度：%d\n", stackLength(s));	
	getTop(s, &e);
	printf("栈顶元素：%d\n", e);
	
	return 0;	
}
