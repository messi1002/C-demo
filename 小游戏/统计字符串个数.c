/*1��
����������Ƴ���
����������ͳ���������������ɫ���������ɫ��
���룺 ��������������������ÿ����������������N��ʼ��0<N<=1000��-�������ɫ������
��������N��ÿ�а���һ����ɫ�� ��ɫ��һ�����15����ĸ�ĵ��ʡ�N=0ʱ����������ֹ��������Ҵ�ӡexit��
����� �ڵ����ϴ�ӡ�����ִ���������ɫ��
ʾ����������� 
5 
green red red blue orange
red
3 
white black black
black
0 exit
*/ 
//ps:û�п����������������� 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 15
#define M 150
struct record
{
       char word[N+1];
       int times;
}game[M];
int main()
{
int i,j,k,*p,*q,s,t;
char temp[2];
char a[N];
printf("�����������������ɫ����\n");
scanf("%d",&i);
for(j=0;j<i;j++) 
{
   printf("���������ĵ���\n");
   scanf("%s",game[j].word);  
}
for(j=i-1;j>0;j--)
{
	t=0;
	for(k=i-2;k>0;k--)
	{
    if(strcmp(game[j].word,game[k].word)==0)
    {
    t++;
    game[j].times=t;
	}    
    }
} 
for(k=0;k<i;k++)
{
    for(j=i-1;j>0;j--)
    {
    if(game[j-1].times<game[j].times)
    {
	p=&game[j-1].times;
    q=&game[j].times;
    s=*q;
    *q=*p;
    *p=s;
    strcpy(temp,game[j-1].word);//�൱��temp=a;a=b;b=temp;
    strcpy(game[j-1].word,game[j].word);
    strcpy(game[j].word,temp);
    }
}
}
printf("\n���ִ���������ɫ��:\n");
printf("%s\n",game[0].word); 
return 0;
}

