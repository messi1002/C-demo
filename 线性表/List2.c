/*
ͨ��������������֪�����λ��ָ���������±꣬����λ��
Lastָ��Ҳ�����һ������Ԫ�ص��±ꡣ 
����ÿ�������д���ȥ�Ķ��ǽṹ��ָ��(L)�� 
��������������⡣ 
*/

// ����������һ���յ����Ա� 
List MakeEmpty()
{
	/* 
	malloc()�ڶ�������һ��ָ����С���ڴ�ռ䣬����������ݡ�����Ҫ����ʱ�򣬿����ͷš� 
	����ɹ�����ָ����ڴ�ĵ�ַ��ʧ���򷵻�NULL�� 
	�����ķ���ֵ������void*�������ص�ָ������δ֪��������ʹ��malloc()ʱͨ����Ҫ����ǿ������ת������void*ת��������ϣ�������͡� 
	��������������malloc����һ���ڴ�ռ��Ŵ˽ṹ�壬Ȼ�󷵻ظýṹ��ĵ�ַ��L�� 
	List���;��Ǹ�ָ�����ͣ�������ﴫ�Ķ���ָ�룡������ͨ��ָ��L->..���Ըı�ṹ�塣 
	*/ 
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// �������Ա���X��λ�ã����Ҳ����򷵻�ERROR��
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

// ��X������λ��P������true��
// ���ռ����������ӡ��FULL��������false���������Pָ��Ƿ�λ�ã����ӡ��ILLEGAL POSITION��������false��
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
  	// ��P~Last��������ơ� 
    for (i = L->Last; i >= P; i--)
    {
      L->Data[i+1] = L->Data[i];
    }
  }
  
  L->Data[P] = X;
  // ��ʼ��ʱ������L->Last=-1����ʱ��һ�����һ��Ԫ�أ�����L->last=0��
  // ���ü����һ��Ԫ�ص������±�Ϊ0�� 
  L->Last++; 
  return true;
}

// ��λ��P��Ԫ��ɾ��������true��������Pָ��Ƿ�λ�ã����ӡ��POSITION P EMPTY��������P�ǲ���ֵ��������false��
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
  	// ��P+1~Last��Ԫ�ؾ���ǰ�ơ� 
    for (i = P+1; i < L->Last; i++)
    {
      L->Data[i-1] = L->Data[i];
    }
    
    L->Last--;
    return true;
  }
}
