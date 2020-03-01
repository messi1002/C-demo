#include <stdio.h>

#define MAXSIZE 10
#define ERROR 1
#define OK 0

typedef int Status; 

typedef struct Stack {
	int data[MAXSIZE];
	// ָʾջ��Ԫ���������е�λ�ã�top<=MAXSIZE-1��
	// ��ջ����һ��Ԫ��ʱ��top=0�����Կ�ջ���ж�����Ϊtop=-1�� 
	int top;
} Stack;

// ��ʼ��һ����ջs�� 
Status initStack(Stack* ss)
{  
	ss->top = -1;
    return OK;
}

// ��ջsΪ��ջ���򷵻�OK�����򷵻�ERROR�� 
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

// ����s��Ԫ�ظ�������ջ�ĳ��ȡ� 
int stackLength(Stack s)
{ 
	return ++s.top;
}

// ��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR�� 
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

// ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ�� 
void printStack(Stack s)
{
    int i;
        
    for (i = 0; i <= s.top; i++)
    {
        printf("%d ", s.data[i]);
    }
        
    printf("\n");
}

// ����Ԫ��eΪ�µ�ջ��Ԫ�ء� 
Status Push(Stack* ss, int e)
{
	// ջ���� 
	if (ss->top == MAXSIZE-1)	
	{
		return ERROR;
	}
	
	ss->top++;
	ss->data[ss->top] = e; 
	return OK;
}

// ջ���գ���ɾ��s��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR�� 
Status Pop(Stack* ss, int* e)
{
	// ջ�ա� 
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
	
	printf("��ʼ��ջ��%d\n", initStack(&s));
	printf("�Ƿ�Ϊ��ջ��%d\n", stackEmpty(s));
	printf("ջ�ĳ��ȣ�%d\n", stackLength(s));
	
	printf("����ջ��Ԫ��\n");
	for (i = 0; i < MAXSIZE; i++)
	{
		Push(&s, i);
		printf("���룺%d\n", i); 
	}
	
	printf("��ӡջԪ�أ�");
	printStack(s);
	
	printf("ջ�ĳ��ȣ�%d\n", stackLength(s));	
	getTop(s, &e);
	printf("ջ��Ԫ�أ�%d\n", e);
	
	Pop(&s, &e);	
	printf("ɾ��ջ��Ԫ�أ�%d\n", e);
	
	printf("ջ�ĳ��ȣ�%d\n", stackLength(s));	
	getTop(s, &e);
	printf("ջ��Ԫ�أ�%d\n", e);
	
	return 0;	
}
