/*1：
根据描述设计程序
问题描述：统计输入次数最多的颜色并输出该颜色。
输入： 输入包含多个测试用例。每个测试用例以数字N开始（0<N<=1000）-输入的颜色个数。
接下来的N行每行包含一个颜色。 颜色是一串最多15个字母的单词。N=0时测试用例终止输出，并且打印exit。
输出： 在单行上打印出出现次数最多的颜色。
示例输入输出： 
5 
green red red blue orange
red
3 
white black black
black
0 exit
*/ 
//ps:没有看懂测试用例？？？ 
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
printf("请输入您想输入的颜色个数\n");
scanf("%d",&i);
for(j=0;j<i;j++) 
{
   printf("请输入您的单词\n");
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
    strcpy(temp,game[j-1].word);//相当于temp=a;a=b;b=temp;
    strcpy(game[j-1].word,game[j].word);
    strcpy(game[j].word,temp);
    }
}
}
printf("\n出现次数最多的颜色是:\n");
printf("%s\n",game[0].word); 
return 0;
}

