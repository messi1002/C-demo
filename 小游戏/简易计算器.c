/* 
//7：简易计算器
*/ 
#include <stdio.h> 
int main()
{
	float x,y;
	char z;	
	printf("请输入两个数x,y:\n");
	scanf("%f%f",&x,&y);
	printf("请输入运算符号\n");
	while (getchar() != '\n') {
		continue;
	}
	scanf("%c",&z);//必须有一个空格； 
	
	switch(z)
	{
		case '+':printf("%.5f\n",x+y);break;
		case '-':printf("%.5f\n",x-y);break;	
		case '*':printf("%.5f\n",x*y);break;
		case '/':
		         if(y==0.0)
		           printf("分母不能为0，输入有错误\n");
		         else 
		           printf("%.5f\n",x/y);
		         break;
		default: printf("您的输入有错误！\n");	
	} 
	return 0;	
} 

