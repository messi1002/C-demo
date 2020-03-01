// 链队列、尾进头出。 

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0 
#define ERROR 1 

typedef int Status; 

// 结点结构。 
typedef struct QNode {
   int data;
   struct QNode* next;
} QNode, *QueuePtr;

// 队列的链表结构，队头指针指向链队列的头结点，队尾指针指向终端结点。 
typedef struct
{
   QueuePtr front;
   QueuePtr rear;
} LinkQueue;

// 构造一个空队列q。 
Status initQueue(LinkQueue* qq)
{ 
	// 空队列时，front和real都指向头结点。 
	qq->front = qq->rear = (QueuePtr)malloc(sizeof(QNode));
	// 令头结点指向空。 
	qq->front->next = NULL;
	
	return OK;
}

// 将q清为空队列。 
Status clearQueue(LinkQueue* qq)
{
	QueuePtr p, q; 
	qq->rear = qq->front;
	// p指向第一个结点。 
	p = qq->front->next;
	// 令头结点指向空。 
	qq->front->next = NULL;

	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	
	return OK;
}

// 若q为空队列，则返回OK，否则返回ERROR。 
Status queueEmpty(LinkQueue q)
{ 
	// 空队列的条件。 
	if (q.front == q.rear)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

// 求队列的长度。 
int queueLength(LinkQueue q)
{ 
	int i = 0;
	QueuePtr p;
	p = q.front;
	
	// 若rear指针没有指向它，说明这个结点非空，++i即可。 
	while (q.rear != p)
	{
		++i;
		p = p->next;
	}
	
	return i;
}

// 若队列不空，则用e返回q的队头元素，并返回OK，否则返回ERROR。 
Status getHead(LinkQueue q, int* e)
{ 
	QueuePtr p;
	
	if(q.front == q.rear)
	{
		return ERROR;
	}
	
	p = q.front->next;
	*e = p->data;
	return OK;
}


// 插入元素e为q的新的队尾元素。 
Status enQueue(LinkQueue* qq, int e)
{ 
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	// 让原来的对尾结点和qq->rear都指向s。 
	qq->rear->next = s;	
	qq->rear = s;		
	
	return OK;
}

// 若队列不空，删除q的队头元素，用e返回其值，并返回OK，否则返回ERROR。 
Status deQueue(LinkQueue* qq, int* e)
{
	QueuePtr p;
	
	if (qq->front == qq->rear)
	{
		return ERROR;
	}
	
	p = qq->front->next;
	*e = p->data;			
	qq->front->next = p->next;
	
	// 若队头就是队尾的情况，否则删除队头与qq->rear无关。 
	if (qq->rear == p)
	{
		qq->rear = qq->front;
	}
	
	free(p);
	return OK;
}

// 从队头到队尾依次对队列q中每个元素输出。 
Status printQueue(LinkQueue q)
{
	QueuePtr p;
	p = q.front->next;
	
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	
	printf("\n");
	return OK;
}

int main()
{
	int i, e;
	LinkQueue l;
	
	printf("初始化队列！\n");
	initQueue(&l); 
	i = queueEmpty(l);
	printf("是否为空队列：%d\n", i);
	i = queueLength(l);
	printf("队列的长度：%d\n", i);
	
	i = 0;
	while (i < 5)
	{
		++i;
		enQueue(&l, i);
		printf("插入%d\n", i);
	} 
	printf("打印队列：");
	printQueue(l);
	
	getHead(l, &e);
	printf("队头元素：%d\n", e);
	deQueue(&l, &e);
	printf("删除：%d\n", e);
	printf("打印队列：");
	printQueue(l);
	i = queueLength(l);
	printf("队列的长度：%d\n", i);
	
	printf("清空队列！\n"); 
	clearQueue(&l);
	i = queueLength(l);
	printf("队列的长度：%d\n", i);
	
	return 0;
}
