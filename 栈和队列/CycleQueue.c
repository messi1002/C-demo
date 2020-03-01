/* 
如下所写实现循环队列(避免假溢出问题)，即队列的头尾相接的顺序存储结构。
前提条件是当队列满时，数组中还有一个空闲单元，当队列空时，real==front。 
因为队列满时有两种情况： 
	1.front - real = 1、 
	2.real - front = QUEUESIZE - 1。 
所以判断队列是否已满的条件是：(real + 1) % QUEUESIZE == front(合理的、缜密的逻辑分析)。
(取模是为了整合rear与front有两种可能性的问题)。
用的计算队列长度公式为：(rear - front + QUEUESIZE) % QUEUESIZE，若它 == QUEUESIZE-1，则队列满了。  
因为对应上述的两种情况：
	1.QUEUESIZE - front + real、 
	2.rear - front。 
整合起来得到上面的长度计算公式。 
*/
 
#include <stdio.h>
 
#define OK 0
#define ERROR 1 
#define QUEUESIZE 5 
 
typedef int Status;

typedef struct Queue {
	int data[QUEUESIZE];
	int front;
	int rear;
} Queue; 

// 初始化一个空队列q。 
Status initQueue(Queue* qq)
{
	qq->front = 0;
	qq->rear = 0;
	return  OK;
}

// 若队列q为空队列，则返回OK，否则返回ERROR。 
Status queueEmpty(Queue q)
{ 
	// 空队列。 
	if (q.front == q.rear)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

// 返回q的元素个数，也就是队列的当前长度。 
int queueLength(Queue q)
{
	return (q.rear - q.front + QUEUESIZE) % QUEUESIZE;
}

// 若队列不空，用e返回q的队头元素，并返回OK，否则返回ERROR。 
Status getHead(Queue q, int* e)
{
	// 队列空。 
	if (q.front == q.rear)
	{
		return ERROR;
	}
	
	*e = q.data[q.front];
	
	return OK;
}

// 若队列未满，则插入元素e为q新的队尾元素。 
Status enQueue(Queue* qq, int e)
{
	if ((qq->rear + 1) % QUEUESIZE == qq->front)
	{ 
		return ERROR;
	} 

	qq->data[qq->rear] = e;
	// rear指针向后移一位置，若到最后则转到数组头部。 
	qq->rear = (qq->rear + 1) % QUEUESIZE;
	return OK;
}

// 若队列不空，则删除q中队头元素，用e返回其值。 
Status deQueue(Queue* qq, int* e)
{
	if (qq->front == qq->rear)
	{	
		return ERROR;
	}
	
	*e = qq->data[qq->front];
	// front指针向后移一位置，若到最后则转到数组头部。 
	qq->front = (qq->front + 1) % QUEUESIZE;	
	return OK;
}

void printQueue(Queue q)
{ 
	int i;
	i = 0;
	
	while ((i + q.front) != q.rear)
	{
		printf("%d ", q.data[i+q.front]);
		// 考虑循环问题。 
		i = (i+1) % QUEUESIZE; 
	}
	printf("\n");
}

int main()
{
	int i, e;
	Queue q;
	
	printf("初始化队列！\n");
	initQueue(&q); 
	printf("队列是否为空：%d\n", queueEmpty(q));
	i = queueLength(q);
	printf("队列长度：%d\n", i);
	
	i = 0;
	while (i < 5)
	{
		++i;
		enQueue(&q, i);
		printf("插入%d\n", i);
	}
	printf("打印队列：");
	printQueue(q);
	
	deQueue(&q, &e);
	printf("删除：%d\n", e);
	printf("打印队列："); 
	printQueue(q);
	deQueue(&q, &e);
	printf("删除：%d\n", e);
	printf("打印队列："); 
	printQueue(q);
	i = queueLength(q);
	printf("队列长度：%d\n", i);
	
	getHead(q, &e);
	printf("队头：%d\n", e);
	return 0;
}
