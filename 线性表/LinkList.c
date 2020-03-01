#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1

/*
单链表的大部分工作都需要指针后移遍历。 
注意指向指针的指针。 
*/

typedef int Status;

// 相当于重复使用这一个模板。 
typedef struct Node {
	// 存放数据元素的数据域。 
	int data;
	// 存放后继结点地址的指针域。 
	struct Node* next;
} Node;
// 给指向Node结构体的指针一个别名link。 
typedef struct Node* link;

/*
初始化线性表。 
link等价于struct Node*，link l中-->l被定义为一个头指针，指向一个Node结构体(头结点)。
link* ll中-->ll也是一个指针，指向变量l(头指针)。
指针的指针在定义时，就需要加两个*。 
ll(指针)的值是l(头指针)的地址，这里没什么用处，*ll的值就是变量l(头指针)的值，即l所指向的头结点的地址。
注意之前想要改变结构体，需要传入指向结构体的指针，这里需要改变l的值，自然需要传入指向头指针l的指针。
malloc分配一块内存空间存放Node结构体(头结点)，然后返回该头结点的地址给l(头指针)，使l(头指针)指向该头结点。
l等价与*ll！！服了这个大话作者，二级指针和一级指针是一样的名字，你是在逗我吗？ 
因为这里需要改变头指针l的值，所以要传入指向头指针l的指针。 

#include <stdio.h>
swap(int* p, int* q)
{
	// 在这个交换函数中，指针的目的，是为了访问a，b本身！！ 
	int i;
	i = *p;
	*p = *q;
	*q = i;  
}
int main()
{
	int a = 0, b = 1;
	printf("%d %d\n", a, b);// 0 1。 
	swap(&a, &b);
	printf("%d %d\n", a, b);// 1 0。 
	return 0;
}
所以*ll的目的，是为了改变l本身指向！！ 
*/ 
Status initList(link* ll) 
{ 
	// 产生头结点,并使l(头指针)指向此头结点。 
    *ll = (link)malloc(sizeof(Node));
    
    // *ll为NULL，存储分配失败。 
    if (!(*ll))
    {
        return ERROR;
    }
    
    // 令头结点的指针域为空。 
    (*ll)->next = NULL; 
    return OK;
}

// 若l为空表，则返回OK，否则返回ERROR。 
Status emptyList(link l)
{ 
	// 如果头结点的指针域非空，不是空表。 
    if (l->next)
    { 
        return ERROR;
    } 
    else
    { 
    	return OK;
    } 
}

// 将l重置为空表。 
Status clearList(link l)
{ 
	link p, q;
	// p(头结点的指针域)保存第一个结点的地址，即指向第一个结点。 
	p = l->next;      

	// 如果存在第一个结点，让q保存第一个结点指针域的值，即它指向的第二个结点的地址。 
	// free函数释放p所保存的地址的内存(即第一个结点被释放)，再令第二个结点的地址交给p。
	// 判断是否有值...。 
	while (p)             
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	// 令头结点的指针域为空。 
	l->next = NULL;    
	return OK;
}

// 返回l中数据元素个数。 
int listLength(link l)
{
	// p为头结点的指针域，指向第一个结点。 
    int i = 0;
    link p = l->next; 
     
    // 如果第一个结点不为空，i=1，再向下指。 
    while (p)                        
    {
        ++i;
        p = p->next;
    }
    
    return i;
}

// 用e返回l中第i个数据元素的值。  
Status getElem(link l, int i, int* e)
{
	// 目前指向第一个结点。 
	int j = 1; 
	// 让p指向链表l的第一个结点。 
	// 第一个结点的数据是l->next->data/p->data。 
	link p = l->next; 
	
	// 如果p不为空且没有循环到i。 
	while (p && j < i)
	{
		j++;
		// p指向下一个结点。 
		p = p->next;	
	} 
	
	// (p为空)第i个元素不存在，用j>i是怕出现负数！。 
	if (!p || j > i)
	{
		return ERROR;
	}
	
	// 取得第i个元素的数据。 
	*e = p->data;
	return OK;
} 

// 返回l中第1个与e满足关系的数据元素的位序。 
// 若这样的数据元素不存在，则返回值为0。 
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

// 在l中第i个位置之前插入新的数据元素e，l的长度加1。 
Status insertElem(link l, int i, int e)
{
	// p=l是因为如果插入到第一个位置，是要改变头结点的指针域的，将头结点也当成一个结点，便于统一代码。 
	int j = 1; 
	link p = l;
	
	// 如果p不为空且没有循环到i。 
	while (p && j < i)
	{
		// p指向下一个结点。 
		p = p->next;
		++j;	
	} 
	
	// p为空，第i个元素不存在。 
	if (!p || j > i)
	{
		return ERROR;
	}
	
	// 生成一个新的结点，在内存中找了一块小空地。
	// 终极：即s是一个结构体指针，指向新生成的结构体(新结点)。 
	link s = (link)malloc(sizeof(Node));
	// 将e数据存放在新结点的数据域中。 
	s->data = e; 
	// 将p的后继结点(第i个结点，指针域保存第i+1个结点的地址)赋值给s->next，即让新结点的指针域指向第i个结点。 
	s->next = p->next;
	// 将s的值(新结点的地址)赋值给p的后继，即让p指向新结点，新结点变为第i个结点。
	// p为第i-1个结点，原来的p->next为第i+1个结点。 
	p->next = s;
	return OK;
}

// 删除l的第i个数据元素，并用e返回其值，l的长度减1。 
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
	
	// p->next指向第i个结点，将第i个结点的内存地址赋给q。 
	link q = p->next;
	// 让p指向第i+1个结点。 
	p->next = q->next;		
	*e = q->data;               
	// 函数free，让系统回收此内存，即释放第i个结点。 
	free(q);                    
	return OK;
}

// 依次对l的每个数据元素输出。 
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

// 随机产生n个元素的值，建立带表头结点的单链线性表l（头插法）。 
void createListHead(link* ll, int n) 
{
	int i;
	// 初始化随机数种子。 
	srand(time(0));                 
	
	// 先建立一个带头结点的单链表。 
	*ll = (link)malloc(sizeof(Node));
	(*ll)->next = NULL;       
	     
	// 每次对于新插入的结点来说，先让它保存头结点之前指向的地址。再让头结点保存它的地址。
	// 每次循环与上次依靠头结点相联系。 
	for (i = 0; i < n; i++) 
	{
		// 生成新结点。 
		link p = (link)malloc(sizeof(Node)); 
		// 随机生成100以内的数字。 
		p->data = rand() % 100 + 1;    
		// 第一次p->next=NULL(第一次生成的新结点会是最后一个结点)。
		// 第二次p->next=第一次插入的结点的内存地址，...，依次类推，每次头插。         
		p->next = (*ll)->next;    
		// 插入到表头，让头结点指向新结点。 
		(*ll)->next = p;					
	}
}

// 随机产生n个元素的值，建立带表头结点的单链线性表l（尾插法）。 
void createListTail(link* ll, int n) 
{
	link r;
	int i;
	srand(time(0));                   
	
	// 每次让上一次生成的结点保存新结点的地址，再让新结点指向NULL。 
	// 上一次循环与这一次循环有联系，需要中间量，r为指向尾部的结点。 
	*ll = (link)malloc(sizeof(Node)); 
	r = *ll;            
	for (i = 0; i < n; i++) 
	{
		link p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;       
		// 将表尾终端结点的指针指向新结点。 
		r->next = p;                        
		// 将当前的新结点定义为表尾终端结点。 
		r = p;                            
	}
	
	// 表示当前链表结束。 
	r->next = NULL;                       
}

int main()
{
	int i, e;
	// 定义一个头指针。 
	link l; 
	
	i = initList(&l);
	printf("初始化链表：%d\n", i);
	
	i = emptyList(l);
	printf("l是否为空表：%d\n", i); 
	
	i = listLength(l);
	printf("l.length：%d\n", i);
	
	for (i = 1; i <= 10; i++)
	{
		insertElem(l, i, i);
		printf("插入%d\n", i);
	}
	printf("打印l：");
	printList(l);
	
	i = listLength(l);
	printf("l.length：%d\n", i);
	
	getElem(l, 2, &e);
	printf("第二个元素：%d\n", e); 
	i = findElem(l, 3); 
	printf("元素3的位置：%d\n", i);
	
	for (i = 1; i <= 10; i++)
	{
		deleteElem(l, 1, &e);
		printf("删除%d\n", e);	
	}
	
	i = listLength(l);
	printf("l.length：%d\n", i);
	
	printf("使用头插法随机创建5个结点：");
	createListHead(&l, 5);
	printList(l);
	
	printf("清空线性表：");
	clearList(l); 
	
	i = listLength(l);
	printf("l.length：%d\n", i);
	
	printf("使用尾插法随机创建5个结点：");
	createListTail(&l, 5);
	printList(l);	
 
	return 0;	
} 
