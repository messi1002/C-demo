/* 
//7�����׼�����
*/ 
#include <stdio.h> 
int main()
{
	float x,y;
	char z;	
	printf("������������x,y:\n");
	scanf("%f%f",&x,&y);
	printf("�������������\n");
	while (getchar() != '\n') {
		continue;
	}
	scanf("%c",&z);//������һ���ո� 
	
	switch(z)
	{
		case '+':printf("%.5f\n",x+y);break;
		case '-':printf("%.5f\n",x-y);break;	
		case '*':printf("%.5f\n",x*y);break;
		case '/':
		         if(y==0.0)
		           printf("��ĸ����Ϊ0�������д���\n");
		         else 
		           printf("%.5f\n",x/y);
		         break;
		default: printf("���������д���\n");	
	} 
	return 0;	
} 

