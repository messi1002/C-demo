/* 
������дʵ��ѭ������(������������)�������е�ͷβ��ӵ�˳��洢�ṹ��
ǰ�������ǵ�������ʱ�������л���һ�����е�Ԫ�������п�ʱ��real==front�� 
��Ϊ������ʱ����������� 
	1.front - real = 1�� 
	2.real - front = QUEUESIZE - 1�� 
�����ж϶����Ƿ������������ǣ�(real + 1) % QUEUESIZE == front(����ġ����ܵ��߼�����)��
(ȡģ��Ϊ������rear��front�����ֿ����Ե�����)��
�õļ�����г��ȹ�ʽΪ��(rear - front + QUEUESIZE) % QUEUESIZE������ == QUEUESIZE-1����������ˡ�  
��Ϊ��Ӧ���������������
	1.QUEUESIZE - front + real�� 
	2.rear - front�� 
���������õ�����ĳ��ȼ��㹫ʽ�� 
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

// ��ʼ��һ���ն���q�� 
Status initQueue(Queue* qq)
{
	qq->front = 0;
	qq->rear = 0;
	return  OK;
}

// ������qΪ�ն��У��򷵻�OK�����򷵻�ERROR�� 
Status queueEmpty(Queue q)
{ 
	// �ն��С� 
	if (q.front == q.rear)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

// ����q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���ȡ� 
int queueLength(Queue q)
{
	return (q.rear - q.front + QUEUESIZE) % QUEUESIZE;
}

// �����в��գ���e����q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR�� 
Status getHead(Queue q, int* e)
{
	// ���пա� 
	if (q.front == q.rear)
	{
		return ERROR;
	}
	
	*e = q.data[q.front];
	
	return OK;
}

// ������δ���������Ԫ��eΪq�µĶ�βԪ�ء� 
Status enQueue(Queue* qq, int e)
{
	if ((qq->rear + 1) % QUEUESIZE == qq->front)
	{ 
		return ERROR;
	} 

	qq->data[qq->rear] = e;
	// rearָ�������һλ�ã����������ת������ͷ���� 
	qq->rear = (qq->rear + 1) % QUEUESIZE;
	return OK;
}

// �����в��գ���ɾ��q�ж�ͷԪ�أ���e������ֵ�� 
Status deQueue(Queue* qq, int* e)
{
	if (qq->front == qq->rear)
	{	
		return ERROR;
	}
	
	*e = qq->data[qq->front];
	// frontָ�������һλ�ã����������ת������ͷ���� 
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
		// ����ѭ�����⡣ 
		i = (i+1) % QUEUESIZE; 
	}
	printf("\n");
}

int main()
{
	int i, e;
	Queue q;
	
	printf("��ʼ�����У�\n");
	initQueue(&q); 
	printf("�����Ƿ�Ϊ�գ�%d\n", queueEmpty(q));
	i = queueLength(q);
	printf("���г��ȣ�%d\n", i);
	
	i = 0;
	while (i < 5)
	{
		++i;
		enQueue(&q, i);
		printf("����%d\n", i);
	}
	printf("��ӡ���У�");
	printQueue(q);
	
	deQueue(&q, &e);
	printf("ɾ����%d\n", e);
	printf("��ӡ���У�"); 
	printQueue(q);
	deQueue(&q, &e);
	printf("ɾ����%d\n", e);
	printf("��ӡ���У�"); 
	printQueue(q);
	i = queueLength(q);
	printf("���г��ȣ�%d\n", i);
	
	getHead(q, &e);
	printf("��ͷ��%d\n", e);
	return 0;
}
