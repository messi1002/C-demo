#include <stdio.h>
#include <stdlib.h>

#define ERROR 1
#define OK 0
#define MAXSIZE 20

typedef int Status;

struct SNode {
    int* data;
    int top1, top2;
};

typedef struct SNode* Stack;

/*
注意创建的代码，数组需要申请。
这篇代码里，用的都是结构体指针。 
*/
Stack createStack()
{
  Stack s = (Stack)malloc(sizeof(struct SNode));
  s->data = (int*)malloc(sizeof(int) * MAXSIZE);
  s->top1 = -1;
  s->top2 = MAXSIZE;
  
  return s;
}

// 若栈s为空栈，则返回OK，否则返回ERROR。 
Status stackEmpty(Stack s)
{ 
    if (s->top1 == -1 && s->top2 == MAXSIZE)
    { 
		return OK;
	} 
    else
    { 
		return ERROR;
	} 
}

// 返回s的元素个数，即栈的长度。 
int stackLength(Stack s, int tag)
{ 
	if (tag == 1)
	{
		return s->top1 + 1; 
	}
	else 
	{
		return MAXSIZE - s->top2;
	}
}


Status Push(Stack s, int x, int tag)
{
  if (s->top1 + 1 == s->top2)
  {
    printf("Stack Full\n");
    return ERROR;
  }
 
  if (tag == 1)
  {
    s->top1++;
    s->data[s->top1] = x;
  }
  else
  {
    s->top2--; 
    s->data[s->top2] = x;
  }
 
  return OK;
}

Status Pop(Stack s, int tag)
{ 
  if (tag == 1)
  {
    if (s->top1 == -1)
    {
      printf("Stack 1 Empty\n");
      return ERROR;
    }
    
    s->top1--;
  }
  else
  { 
    if (s->top2 == MAXSIZE)
    {
      printf("Stack 2 Empty\n");
      return ERROR;
    }
    
    s->top2++; 
  }
 
  return OK;
}

void printStack(Stack s, int tag)
{
	int i;
	
	if (tag == 1)
	{
		printf("\n1:");
		for (i = 0; i <= s->top1; i++)
		{
			printf("%d ", s->data[i]);
		}
	}
	else 
	{
		printf("\n2:");
		for (i = MAXSIZE-1; i >= s->top2; i--)
		{
			printf("%d ", s->data[i]);
		}
	}
}
 
int main()
{
	int i;
	 
	Stack s;
	s = createStack();
	i = stackEmpty(s);
	printf("栈是否为空：%d\n", i); 
	
	i = stackLength(s, 1);
	printf("栈1的长度：%d\n", i);
	i = stackLength(s, 2);
	printf("栈2的长度：%d\n", i);
		
	i = 0;	
	while (i < 5)
	{	
		++i;
		Push(s, i, 1);
	}
	printStack(s, 1); 
	
	i = 0;	
	while (i < 5)
	{	
		++i;
		Push(s, i, 2);
	}
	printStack(s, 2);
	
	Pop(s, 1);
	printStack(s, 1); 
	Pop(s, 2);
	printStack(s, 2);
	
	return 0;
}
