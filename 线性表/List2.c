/*
通过测试用例，可知这里的位置指的是数组下标，不是位序。
Last指的也是最后一个数组元素的下标。 
并且每个函数中传过去的都是结构体指针(L)。 
明白题意后再做题。 
*/

// 创建并返回一个空的线性表。 
List MakeEmpty()
{
	/* 
	malloc()在堆区分配一块指定大小的内存空间，用来存放数据。不需要它的时候，可以释放。 
	分配成功返回指向该内存的地址，失败则返回NULL。 
	函数的返回值类型是void*，即返回的指针类型未知。所以在使用malloc()时通常需要进行强制类型转换，将void*转换成我们希望的类型。 
	所以综上所述，malloc分配一块内存空间存放此结构体，然后返回该结构体的地址给L。 
	List类型就是个指针类型，这道题里传的都是指针！！所以通过指针L->..可以改变结构体。 
	*/ 
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// 返回线性表中X的位置，若找不到则返回ERROR。
Position Find(List L, ElementType X)
{
  int i;
  
  for (i = 0; i <= L->Last; i++)
  {
    if (L->Data[i] == X)
    {
      return i;
    }
  }
  
  return ERROR;
}

// 将X插入在位置P并返回true。
// 若空间已满，则打印“FULL”并返回false；如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false；
bool Insert(List L, ElementType X, Position P)
{
  int i;
  
  if (L->Last == MAXSIZE-1)
  {
    printf("FULL");
    return false;    
  }
  else if (P < 0 || P > L->Last+1)
  {
    printf("ILLEGAL POSITION");
    return false;
  }
  else
  {
  	// 从P~Last，都向后移。 
    for (i = L->Last; i >= P; i--)
    {
      L->Data[i+1] = L->Data[i];
    }
  }
  
  L->Data[P] = X;
  // 初始化时定义了L->Last=-1，此时第一次添加一个元素，则有L->last=0。
  // 正好即最后一个元素的数组下标为0。 
  L->Last++; 
  return true;
}

// 将位置P的元素删除并返回true。若参数P指向非法位置，则打印“POSITION P EMPTY”（其中P是参数值）并返回false。
bool Delete(List L, Position P)
{
  int i;
  
  if (P < 0 || P > L->Last)
  {
    printf("POSITION %d EMPTY", P);
    return false;
  }
  else
  {
  	// 从P+1~Last，元素均向前移。 
    for (i = P+1; i < L->Last; i++)
    {
      L->Data[i-1] = L->Data[i];
    }
    
    L->Last--;
    return true;
  }
}
