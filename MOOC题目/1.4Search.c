/*
�����㷨�еġ����ַ�������������ģ�����N����С�����ź������������List[]���Լ�ĳ����������X��
���ǵ�Ŀ�����ҵ�X��List�е��±ꡣ������List[i]=X���򷵻�i�����򷵻�-1��ʾû���ҵ���
���ַ������ҵ����е��е�List[M]����X���бȽϣ�������򷵻��е��±ꣻ������List[M]>X��
������ߵ���ϵ���в���X����List[M]<X�������ұߵ���ϵ���в���X��
*/

#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num); 
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(a) / sizeof(a[0]);
	int left = 0, right = length - 1;
	int flag = 0;
	
	// ��� left <= right ����Ѱ�ҡ� 
	while (left <= right)
	{
		int middle = (left + right) / 2;
		
		// �����в��ҡ� 
		if (num > a[middle])
		{
			left = middle + 1;	
		}	
		// �����в��ҡ� 
		else if (num < a[middle])
		{
			right = middle - 1;
		}
		// a[middle] == num�� 
		else
		{
			printf("a[%d] = %d", middle, num);
			// �ҵ���,����ѭ���� 
			flag = 1;
			break;
		}	
	}
	
	// û�ҵ�,���� -1�� 
	if (flag == 0)
	{
		printf("%d", -1);
	}
	
	return 0;	
} 
