#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1

typedef int Status;

// ����Ҫͷ��㣬ͷָ�����ջ��ָ�롣 
// ���ṹ�� 
typedef struct Stack {
	int data;
	struct Stack* next;
} Stack, *LinkPro; 
 
// ջ������ṹ�� 
typedef struct {
	// ջ��ָ�룬ָ��Stack�ṹ��(��һ�����)��
    LinkPro top;
    int count;
} Link;

// ����һ����ջl��llΪָ��Stack�ṹ��Ľṹ��ָ�롣 
Status initStack(Link ll)
{ 
    ll.top = (LinkPro)malloc(sizeof(Stack));
    ll.top = NULL;
    ll.count = 0;
    
	return OK;
}

// ��l��Ϊ��ջ�� 
Status clearStack(Link* ll)
{ 
    LinkPro p, q;
    p = ll->top;
        
	while (p)
    {  
        q = p;
    	p = p->next;
        free(q);
    } 
    
	ll->count = 0;
    return OK;
}

// ��ջlΪ��ջ���򷵻�OK�����򷵻�ERROR�� 
Status stackEmpty(Link l)
{ 
    if (l.count == 0)
    {
    	return OK;
    }
    else
    {  
	    return ERROR;
	}
}

// ����l��Ԫ�ظ�������ջ�ĳ��ȡ� 
int stackLength(Link l)
{ 
    return l.count;
}

// ��ջ���գ�����e����l��ջ��Ԫ�أ�������OK�����򷵻�ERROR�� 
Status getTop(Link l, int* e)
{
    if (l.top == NULL)
    {
	    return ERROR;
	}
    else
    {
        *e = l.top->data;
    }
    
	return OK;
}

// ����Ԫ��eΪ�µ�ջ��Ԫ�ء� 
Status Push(Link* ll, int e)
{
    LinkPro s = (LinkPro)malloc(sizeof(Stack)); 
	s->data = e; 
    s->next = ll->top;	
    ll->top = s;        
    ll->count++;
    
	return OK;
}

// ��ջ���գ���ɾ��l��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR�� 
Status Pop(Link* ll, int* e)
{ 
    if (!stackEmpty(*ll))
    {
        return ERROR;
	}
	
	LinkPro p;	
    *e = ll->top->data;
    p = ll->top;				
    ll->top = ll->top->next;    
    free(p);               
    ll->count--;
    
	return OK;
}

void printStack(Link l)
{
    LinkPro p;
    p = l.top;
     
	while (p)
    {
    	printf("%d ", p->data);
        p = p->next;
    }
    
	printf("\n");
}

int main()
{
	int i, e;
	Link l;
	
	initStack(l);
	i = stackEmpty(l); 
	printf("�Ƿ�Ϊ��ջ:%d\n", i);
	i = stackLength(l);
	printf("ջ�ĳ��ȣ�%d\n", i);
	
	i = 0;
	while (i < 5)
	{
		++i;
		Push(&l, i);
		printf("���룺%d\n", i);
	}
	printf("��ӡջ��");
	printStack(l);
	
	Pop(&l, &e);
	printf("ɾ��ջ��Ԫ�أ�%d\n", e); 
	printf("��ӡջ��");
	printStack(l);
	i = stackLength(l);
	printf("ջ�ĳ��ȣ�%d\n", i);

	printf("���ջ ");
	clearStack(&l);
	i = stackLength(l);
	printf("ջ�ĳ��ȣ�%d\n", i);
	
	return 0;
}
