#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1

typedef int Status;

// 不需要头结点，头指针就是栈顶指针。 
// 结点结构。 
typedef struct Stack {
	int data;
	struct Stack* next;
} Stack, *LinkPro; 
 
// 栈的链表结构。 
typedef struct {
	// 栈顶指针，指向Stack结构体(第一个结点)。
    LinkPro top;
    int count;
} Link;

// 构造一个空栈l，ll为指向Stack结构体的结构体指针。 
Status initStack(Link ll)
{ 
    ll.top = (LinkPro)malloc(sizeof(Stack));
    ll.top = NULL;
    ll.count = 0;
    
	return OK;
}

// 把l置为空栈。 
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

// 若栈l为空栈，则返回OK，否则返回ERROR。 
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

// 返回l的元素个数，即栈的长度。 
int stackLength(Link l)
{ 
    return l.count;
}

// 若栈不空，则用e返回l的栈顶元素，并返回OK，否则返回ERROR。 
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

// 插入元素e为新的栈顶元素。 
Status Push(Link* ll, int e)
{
    LinkPro s = (LinkPro)malloc(sizeof(Stack)); 
	s->data = e; 
    s->next = ll->top;	
    ll->top = s;        
    ll->count++;
    
	return OK;
}

// 若栈不空，则删除l的栈顶元素，用e返回其值，并返回OK，否则返回ERROR。 
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
	printf("是否为空栈:%d\n", i);
	i = stackLength(l);
	printf("栈的长度：%d\n", i);
	
	i = 0;
	while (i < 5)
	{
		++i;
		Push(&l, i);
		printf("插入：%d\n", i);
	}
	printf("打印栈：");
	printStack(l);
	
	Pop(&l, &e);
	printf("删除栈顶元素：%d\n", e); 
	printf("打印栈：");
	printStack(l);
	i = stackLength(l);
	printf("栈的长度：%d\n", i);

	printf("清空栈 ");
	clearStack(&l);
	i = stackLength(l);
	printf("栈的长度：%d\n", i);
	
	return 0;
}
