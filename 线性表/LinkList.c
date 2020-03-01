#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1

/*
������Ĵ󲿷ֹ�������Ҫָ����Ʊ����� 
ע��ָ��ָ���ָ�롣 
*/

typedef int Status;

// �൱���ظ�ʹ����һ��ģ�塣 
typedef struct Node {
	// �������Ԫ�ص������� 
	int data;
	// ��ź�̽���ַ��ָ���� 
	struct Node* next;
} Node;
// ��ָ��Node�ṹ���ָ��һ������link�� 
typedef struct Node* link;

/*
��ʼ�����Ա� 
link�ȼ���struct Node*��link l��-->l������Ϊһ��ͷָ�룬ָ��һ��Node�ṹ��(ͷ���)��
link* ll��-->llҲ��һ��ָ�룬ָ�����l(ͷָ��)��
ָ���ָ���ڶ���ʱ������Ҫ������*�� 
ll(ָ��)��ֵ��l(ͷָ��)�ĵ�ַ������ûʲô�ô���*ll��ֵ���Ǳ���l(ͷָ��)��ֵ����l��ָ���ͷ���ĵ�ַ��
ע��֮ǰ��Ҫ�ı�ṹ�壬��Ҫ����ָ��ṹ���ָ�룬������Ҫ�ı�l��ֵ����Ȼ��Ҫ����ָ��ͷָ��l��ָ�롣
malloc����һ���ڴ�ռ���Node�ṹ��(ͷ���)��Ȼ�󷵻ظ�ͷ���ĵ�ַ��l(ͷָ��)��ʹl(ͷָ��)ָ���ͷ��㡣
l�ȼ���*ll����������������ߣ�����ָ���һ��ָ����һ�������֣������ڶ����� 
��Ϊ������Ҫ�ı�ͷָ��l��ֵ������Ҫ����ָ��ͷָ��l��ָ�롣 

#include <stdio.h>
swap(int* p, int* q)
{
	// ��������������У�ָ���Ŀ�ģ���Ϊ�˷���a��b������ 
	int i;
	i = *p;
	*p = *q;
	*q = i;  
}
int main()
{
	int a = 0, b = 1;
	printf("%d %d\n", a, b);// 0 1�� 
	swap(&a, &b);
	printf("%d %d\n", a, b);// 1 0�� 
	return 0;
}
����*ll��Ŀ�ģ���Ϊ�˸ı�l����ָ�򣡣� 
*/ 
Status initList(link* ll) 
{ 
	// ����ͷ���,��ʹl(ͷָ��)ָ���ͷ��㡣 
    *ll = (link)malloc(sizeof(Node));
    
    // *llΪNULL���洢����ʧ�ܡ� 
    if (!(*ll))
    {
        return ERROR;
    }
    
    // ��ͷ����ָ����Ϊ�ա� 
    (*ll)->next = NULL; 
    return OK;
}

// ��lΪ�ձ��򷵻�OK�����򷵻�ERROR�� 
Status emptyList(link l)
{ 
	// ���ͷ����ָ����ǿգ����ǿձ� 
    if (l->next)
    { 
        return ERROR;
    } 
    else
    { 
    	return OK;
    } 
}

// ��l����Ϊ�ձ� 
Status clearList(link l)
{ 
	link p, q;
	// p(ͷ����ָ����)�����һ�����ĵ�ַ����ָ���һ����㡣 
	p = l->next;      

	// ������ڵ�һ����㣬��q�����һ�����ָ�����ֵ������ָ��ĵڶ������ĵ�ַ�� 
	// free�����ͷ�p������ĵ�ַ���ڴ�(����һ����㱻�ͷ�)������ڶ������ĵ�ַ����p��
	// �ж��Ƿ���ֵ...�� 
	while (p)             
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	// ��ͷ����ָ����Ϊ�ա� 
	l->next = NULL;    
	return OK;
}

// ����l������Ԫ�ظ����� 
int listLength(link l)
{
	// pΪͷ����ָ����ָ���һ����㡣 
    int i = 0;
    link p = l->next; 
     
    // �����һ����㲻Ϊ�գ�i=1��������ָ�� 
    while (p)                        
    {
        ++i;
        p = p->next;
    }
    
    return i;
}

// ��e����l�е�i������Ԫ�ص�ֵ��  
Status getElem(link l, int i, int* e)
{
	// Ŀǰָ���һ����㡣 
	int j = 1; 
	// ��pָ������l�ĵ�һ����㡣 
	// ��һ������������l->next->data/p->data�� 
	link p = l->next; 
	
	// ���p��Ϊ����û��ѭ����i�� 
	while (p && j < i)
	{
		j++;
		// pָ����һ����㡣 
		p = p->next;	
	} 
	
	// (pΪ��)��i��Ԫ�ز����ڣ���j>i���³��ָ������� 
	if (!p || j > i)
	{
		return ERROR;
	}
	
	// ȡ�õ�i��Ԫ�ص����ݡ� 
	*e = p->data;
	return OK;
} 

// ����l�е�1����e�����ϵ������Ԫ�ص�λ�� 
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0�� 
int findElem(link l, int e)
{
    int j = 0;
    link p = l->next;
    
	while (p)
    {
    	++j;
    	
        if (p->data == e)
        {
		    return j;
    	}
    	
		p = p->next;
    }

    return 0;
}

// ��l�е�i��λ��֮ǰ�����µ�����Ԫ��e��l�ĳ��ȼ�1�� 
Status insertElem(link l, int i, int e)
{
	// p=l����Ϊ������뵽��һ��λ�ã���Ҫ�ı�ͷ����ָ����ģ���ͷ���Ҳ����һ����㣬����ͳһ���롣 
	int j = 1; 
	link p = l;
	
	// ���p��Ϊ����û��ѭ����i�� 
	while (p && j < i)
	{
		// pָ����һ����㡣 
		p = p->next;
		++j;	
	} 
	
	// pΪ�գ���i��Ԫ�ز����ڡ� 
	if (!p || j > i)
	{
		return ERROR;
	}
	
	// ����һ���µĽ�㣬���ڴ�������һ��С�յء�
	// �ռ�����s��һ���ṹ��ָ�룬ָ�������ɵĽṹ��(�½��)�� 
	link s = (link)malloc(sizeof(Node));
	// ��e���ݴ�����½����������С� 
	s->data = e; 
	// ��p�ĺ�̽��(��i����㣬ָ���򱣴��i+1�����ĵ�ַ)��ֵ��s->next�������½���ָ����ָ���i����㡣 
	s->next = p->next;
	// ��s��ֵ(�½��ĵ�ַ)��ֵ��p�ĺ�̣�����pָ���½�㣬�½���Ϊ��i����㡣
	// pΪ��i-1����㣬ԭ����p->nextΪ��i+1����㡣 
	p->next = s;
	return OK;
}

// ɾ��l�ĵ�i������Ԫ�أ�����e������ֵ��l�ĳ��ȼ�1�� 
Status deleteElem(link l, int i, int* e) 
{ 
	int j = 1;
	link p = l;
		
	while (p && j < i)
	{
        p = p->next;
        ++j;
	}
	
	if (!p->next || j > i)  
	{
	    return ERROR;        
	}
	
	// p->nextָ���i����㣬����i�������ڴ��ַ����q�� 
	link q = p->next;
	// ��pָ���i+1����㡣 
	p->next = q->next;		
	*e = q->data;               
	// ����free����ϵͳ���մ��ڴ棬���ͷŵ�i����㡣 
	free(q);                    
	return OK;
}

// ���ζ�l��ÿ������Ԫ������� 
void printList(link l)
{
    link p = l->next;
    
	while (p)
    {
    	printf("%d ", p->data); 
        p = p->next;
    }
    printf("\n");
}

// �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�l��ͷ�巨���� 
void createListHead(link* ll, int n) 
{
	int i;
	// ��ʼ����������ӡ� 
	srand(time(0));                 
	
	// �Ƚ���һ����ͷ���ĵ����� 
	*ll = (link)malloc(sizeof(Node));
	(*ll)->next = NULL;       
	     
	// ÿ�ζ����²���Ľ����˵������������ͷ���֮ǰָ��ĵ�ַ������ͷ��㱣�����ĵ�ַ��
	// ÿ��ѭ�����ϴ�����ͷ�������ϵ�� 
	for (i = 0; i < n; i++) 
	{
		// �����½�㡣 
		link p = (link)malloc(sizeof(Node)); 
		// �������100���ڵ����֡� 
		p->data = rand() % 100 + 1;    
		// ��һ��p->next=NULL(��һ�����ɵ��½��������һ�����)��
		// �ڶ���p->next=��һ�β���Ľ����ڴ��ַ��...���������ƣ�ÿ��ͷ�塣         
		p->next = (*ll)->next;    
		// ���뵽��ͷ����ͷ���ָ���½�㡣 
		(*ll)->next = p;					
	}
}

// �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�l��β�巨���� 
void createListTail(link* ll, int n) 
{
	link r;
	int i;
	srand(time(0));                   
	
	// ÿ������һ�����ɵĽ�㱣���½��ĵ�ַ�������½��ָ��NULL�� 
	// ��һ��ѭ������һ��ѭ������ϵ����Ҫ�м�����rΪָ��β���Ľ�㡣 
	*ll = (link)malloc(sizeof(Node)); 
	r = *ll;            
	for (i = 0; i < n; i++) 
	{
		link p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;       
		// ����β�ն˽���ָ��ָ���½�㡣 
		r->next = p;                        
		// ����ǰ���½�㶨��Ϊ��β�ն˽�㡣 
		r = p;                            
	}
	
	// ��ʾ��ǰ��������� 
	r->next = NULL;                       
}

int main()
{
	int i, e;
	// ����һ��ͷָ�롣 
	link l; 
	
	i = initList(&l);
	printf("��ʼ������%d\n", i);
	
	i = emptyList(l);
	printf("l�Ƿ�Ϊ�ձ�%d\n", i); 
	
	i = listLength(l);
	printf("l.length��%d\n", i);
	
	for (i = 1; i <= 10; i++)
	{
		insertElem(l, i, i);
		printf("����%d\n", i);
	}
	printf("��ӡl��");
	printList(l);
	
	i = listLength(l);
	printf("l.length��%d\n", i);
	
	getElem(l, 2, &e);
	printf("�ڶ���Ԫ�أ�%d\n", e); 
	i = findElem(l, 3); 
	printf("Ԫ��3��λ�ã�%d\n", i);
	
	for (i = 1; i <= 10; i++)
	{
		deleteElem(l, 1, &e);
		printf("ɾ��%d\n", e);	
	}
	
	i = listLength(l);
	printf("l.length��%d\n", i);
	
	printf("ʹ��ͷ�巨�������5����㣺");
	createListHead(&l, 5);
	printList(l);
	
	printf("������Ա�");
	clearList(l); 
	
	i = listLength(l);
	printf("l.length��%d\n", i);
	
	printf("ʹ��β�巨�������5����㣺");
	createListTail(&l, 5);
	printList(l);	
 
	return 0;	
} 
