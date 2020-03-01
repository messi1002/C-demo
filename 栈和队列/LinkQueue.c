// �����С�β��ͷ���� 

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0 
#define ERROR 1 

typedef int Status; 

// ���ṹ�� 
typedef struct QNode {
   int data;
   struct QNode* next;
} QNode, *QueuePtr;

// ���е�����ṹ����ͷָ��ָ�������е�ͷ��㣬��βָ��ָ���ն˽�㡣 
typedef struct
{
   QueuePtr front;
   QueuePtr rear;
} LinkQueue;

// ����һ���ն���q�� 
Status initQueue(LinkQueue* qq)
{ 
	// �ն���ʱ��front��real��ָ��ͷ��㡣 
	qq->front = qq->rear = (QueuePtr)malloc(sizeof(QNode));
	// ��ͷ���ָ��ա� 
	qq->front->next = NULL;
	
	return OK;
}

// ��q��Ϊ�ն��С� 
Status clearQueue(LinkQueue* qq)
{
	QueuePtr p, q; 
	qq->rear = qq->front;
	// pָ���һ����㡣 
	p = qq->front->next;
	// ��ͷ���ָ��ա� 
	qq->front->next = NULL;

	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	
	return OK;
}

// ��qΪ�ն��У��򷵻�OK�����򷵻�ERROR�� 
Status queueEmpty(LinkQueue q)
{ 
	// �ն��е������� 
	if (q.front == q.rear)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

// ����еĳ��ȡ� 
int queueLength(LinkQueue q)
{ 
	int i = 0;
	QueuePtr p;
	p = q.front;
	
	// ��rearָ��û��ָ������˵��������ǿգ�++i���ɡ� 
	while (q.rear != p)
	{
		++i;
		p = p->next;
	}
	
	return i;
}

// �����в��գ�����e����q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR�� 
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


// ����Ԫ��eΪq���µĶ�βԪ�ء� 
Status enQueue(LinkQueue* qq, int e)
{ 
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	// ��ԭ���Ķ�β����qq->rear��ָ��s�� 
	qq->rear->next = s;	
	qq->rear = s;		
	
	return OK;
}

// �����в��գ�ɾ��q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR�� 
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
	
	// ����ͷ���Ƕ�β�����������ɾ����ͷ��qq->rear�޹ء� 
	if (qq->rear == p)
	{
		qq->rear = qq->front;
	}
	
	free(p);
	return OK;
}

// �Ӷ�ͷ����β���ζԶ���q��ÿ��Ԫ������� 
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
	
	printf("��ʼ�����У�\n");
	initQueue(&l); 
	i = queueEmpty(l);
	printf("�Ƿ�Ϊ�ն��У�%d\n", i);
	i = queueLength(l);
	printf("���еĳ��ȣ�%d\n", i);
	
	i = 0;
	while (i < 5)
	{
		++i;
		enQueue(&l, i);
		printf("����%d\n", i);
	} 
	printf("��ӡ���У�");
	printQueue(l);
	
	getHead(l, &e);
	printf("��ͷԪ�أ�%d\n", e);
	deQueue(&l, &e);
	printf("ɾ����%d\n", e);
	printf("��ӡ���У�");
	printQueue(l);
	i = queueLength(l);
	printf("���еĳ��ȣ�%d\n", i);
	
	printf("��ն��У�\n"); 
	clearQueue(&l);
	i = queueLength(l);
	printf("���еĳ��ȣ�%d\n", i);
	
	return 0;
}
