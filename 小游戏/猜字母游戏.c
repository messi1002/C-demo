/*  题目一
    这是一个简单的猜单词智力游戏，游戏者每次只能猜一个字母，如果游戏者猜的字母在单词中，单词中所有的该字母将被视为已猜出。例如：如果原单词是apple，游戏者猜出了
p，则程序应显示当前猜出的残缺单词为-pp--；设置选择时间限制或猜错次数限制，超
过时间或者次数限制则游戏失败。
1-5个字母为初级；6-9个字母为中级；10个字母以上为高级，猜错次数和时间限制自定。

二、要求：
1.设计游戏者信息格式：记录用户名、成绩，并保存，下次开始时可选择用户继续游戏，用户信息存放。
2.在dadt.txt中。建立积分排行榜，保留不同级别前五名的成绩。
3.根据单词长度设置不同级别的游戏。
4.游戏过程中，猜错的字母将被记录下来，每次猜测后，游戏应显示出当前猜出的残缺单词，以及当前猜错的所有字母，和剩下的机会。
5.提供相应安全机制，保证程序的健壮性，如选择单词长度时，应避免非数字字符的输入造成程序出错等。
6.提供选择一次求助机会。如给出指定位置上的一个字母等。
*/
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 10//姓名和学号最大字符数；
#define A 8
#define B 12
#define C 18
struct record//用结构体统计信息；
{

     char name[M+1];
	 int Amark;
	 int Bmark;
	 int Cmark;
}game[N];
int m,n,U;
void menu();
void statement();
void new();
void login();
void rank();
void read();
void save();
void Agame();
void Bgame();
void Cgame();
void Amark();
void Bmark();
void Cmark();
int main()
{

    read();
    while(1)
    menu();
    system("pause");
    return 0;
}
void menu()
{
	 int num;
     printf("\n\n\n-----------------猜单词游戏---------------\n");
     printf("\n\n\n\n\n\n       欢迎来到猜单词游戏！！！");
     printf("\n                 0.游戏规则            \n");
     printf("\n\n               1.注册                \n");
     printf("\n\n               2.登陆游戏            \n");
     printf("\n\n               3.初级难度成绩排行榜  \n");
     printf("\n\n               4.中级难度成绩排行榜  \n");
     printf("\n\n               5.高级难度成绩排行榜  \n");
     printf(" 请输入子菜单编号； ");
     scanf("%d",&num);
     switch(num)
     {
           case 0:statement();break;
           case 1:new();break;
           case 2:login();break;
           case 3:Amark();break;
		   case 4:Bmark();break;
		   case 5:Cmark();break;
           default:printf("请在数字0-5之间选择\n");break;
     }
}
void read()
     {
       char *p="game.txt";
       FILE *fp;
       int i=0;
       if((fp=fopen("game.txt","r"))==NULL)
       {
       printf("Open file is error!Strike any key to exit!");
       system("pause");
       exit(0);
       }
       while (fscanf(fp,"%s %d %d %d",game[i].name,&game[i].Amark,&game[i].Bmark,&game[i].Cmark)==4)
       {
            i++;
       }
       fclose(fp);
       n=i;
       printf("录入完毕！\n");
     }
void statement()
     {
       printf("1.欢迎查看游戏规则！\n");
       printf("2.请按照菜单功能键入菜单编号:\n");
       printf("3.这是一个简单的猜单词智力游戏，您每次只能猜一个字母，如果您猜的字母在单词中，单词中所有的该字母将被视为已猜出。");
	   printf("4.例如：如果原单词是apple，游戏者猜出了p，则程序应显示当前猜出的残缺单词为-pp--；\n");
       printf("5.1-5个字母为初级；6-9个字母为中级；10个字母以上为高级。在开始游戏后，您可选择任意难度。\n");
       printf("初级难度的");
	   printf("6.我们将分别保存初级，中级，高级游戏的前五名用户的成绩，方便您查看。");
	   printf("7.谢谢您的使用！\n");
     }
void new()
     {
     printf("\n欢迎注册\n");
     int i=n,j,flag;
     flag=1;
     while(flag)
          {
          flag=0;
          printf("\n请输入您的用户名：\n");
          scanf("%s",game[i].name);
          for(j=0;j<i;j++)
                   if(strcmp(game[i]. name,game[j].name)==0)
                   {
                      printf("\n已有该名字，请重新输入！\n");
                      flag=1;
                      break;
                   }
          }
          if (flag==0)
          {
          printf("\n注册成功！\n");
          printf("\n登录后即可保存您的游戏成绩\n");
          n++;
          game[i].Amark=0;
		  game[i].Bmark=0;
		  game[i].Cmark=0;
          printf("你的初始初级成绩为：%d\n",game[i].Amark);
          printf("你的初始中级成绩为：%d\n",game[i].Bmark);
          printf("你的初始高级成绩为：%d\n",game[i].Cmark);
	      rank();
          }
     }
void rank()
{
 int i,j,*p,*q,s,*a,*b,c,*d,*e,f;
 char temp[2];
       for(i=0;i<n-1;i++)
       {
           for(j=n-1;j>i;j--)
           {
           	     if(game[j-1].Amark>game[j].Amark )
                  p=&game[j-1].Amark;
                  q=&game[j].Amark;
                  s=*q;
                  *q=*p;
                  *p=s;
                  strcpy(temp,game[j-1].name);//相当于temp=a;a=b;b=temp;
                  strcpy(game[j-1].name,game[j].name);
                  strcpy(game[j].name,temp);
                  if(game[j-1].Bmark>game[j].Bmark )
                  p=&game[j-1].Bmark;
                  q=&game[j].Bmark;
                  c=*a;
                  *a=*b;
                  *b=c;
                  strcpy(temp,game[j-1].name);//相当于temp=a;a=b;b=temp;
                  strcpy(game[j-1].name,game[j].name);
                  strcpy(game[j].name,temp);
                  if(game[j-1].Cmark>game[j].Cmark )
                  p=&game[j-1].Cmark;
                  q=&game[j].Cmark;
                  f=*e;
                  *e=*d;
                  *d=f;
                  strcpy(temp,game[j-1].name);//相当于temp=a;a=b;b=temp;
                  strcpy(game[j-1].name,game[j].name);
                  strcpy(game[j].name,temp);
		   }
       }
       save();
}
void save()
     {
	     int i;
         FILE *fp;
         fp=fopen("game.txt","w");
         for(i=0;i<n;i++)
         {
            fprintf(fp,"%s %d %d %d\n",game[i].name,game[i].Amark,game[i].Bmark,game[i].Cmark);
         }
         fclose(fp);
    }
void login()
{
	 int i=n,j,flag;
	 char s1[M+1];
	 printf("请输入您的用户名\n");
	 flag=0;
	 scanf("%s",s1);
	 for(U=0;U<i;U++)
	    if(strcmp(s1,game[U].name)==0)
        {
           printf("登陆成功！请选择游戏难度！\n");
           flag=1;
           break;
        }
     if(flag==0)
     {
     printf("该用户名尚未被注册，请重新输入！");
	 login();
	 }

	 int item;
	 printf("1.初级难度\n");
	 printf("2.中级难度\n");
	 printf("3.高级难度\n");
	 printf("4.退出\n");
	 printf("请选择子菜单编号：\n");
	 scanf("%d",&item);
	 switch(item)
	 {
	       case 1:Agame();break;
	       case 2:Bgame();break;
		   case 3:Cgame();break;
		   case 4:system("pause");
	       default:printf("\n请在1-3之间选择\n");break;
	 }
}
void Agame()
{
     int i,j,k,l,p,q,flag,o,r;
     int t=game[U].Amark;
     char a[5];
     char b[A+1] = "";
     char c='-';
     p=1;
     srand(time(NULL));
     k=rand()%30;
     switch(k)
     {
           case 0 :a[0]='q';a[1]='u';a[2]='o';a[3]='t';a[4]='e';q=5;break;
           case 1 :a[0]='c';a[1]='h';a[2]='i';a[3]='n';a[4]='a';q=5;break;
           case 2 :a[0]='c';a[1]='h';a[2]='o';a[3]='s';a[4]='e';q=5;break;
           case 3 :a[0]='b';a[1]='a';a[2]='s';a[3]='i';a[4]='c';q=5;break;
           case 4 :a[0]='g';a[1]='r';a[2]='e';a[3]='a';a[4]='t';q=5;break;
           case 5 :a[0]='b';a[1]='r';a[2]='e';a[3]='a';a[4]='k';q=5;break;
           case 6 :a[0]='d';a[1]='o';a[2]='n';a[3]='e';q=4;break;
           case 7 :a[0]='w';a[1]='a';a[2]='t';a[3]='e';a[4]='r';q=5;break;
           case 8 :a[0]='l';a[1]='e';a[2]='a';a[3]='v';a[4]='e';q=5;break;
           case 9 :a[0]='h';a[1]='i';q=2;break;
           case 10:a[0]='e';a[1]='x';a[2]='t';a[3]='r';a[4]='a';q=5;break;
           case 11:a[0]='d';a[1]='r';a[2]='e';a[3]='a';a[4]='m';q=5;break;
           case 12:a[0]='b';a[1]='e';a[2]='a';a[3]='c';a[4]='h';q=5;break;
           case 13:a[0]='h';a[1]='e';a[2]='a';a[3]='r';q=4;break;
           case 14:a[0]='l';a[1]='o';a[2]='c';a[3]='k';q=4;break;
           case 15:a[0]='t';a[1]='i';a[2]='m';a[3]='e';q=4;break;
           case 16:a[0]='s';a[1]='o';a[2]='r';a[3]='t';q=4;break;
           case 17:a[0]='f';a[1]='a';a[2]='s';a[3]='t';q=4;break;
           case 18:a[0]='v';a[1]='i';a[2]='e';a[3]='w';q=4;break;
           case 19:a[0]='l';a[1]='i';a[2]='f';a[3]='e';q=4;break;
           case 20:a[0]='s';a[1]='a';a[2]='v';a[3]='e';q=4;break;
           case 21:a[0]='n';a[1]='i';a[2]='c';a[3]='e';q=4;break;
           case 22:a[0]='b';a[1]='e';a[2]='a';a[3]='r';q=4;break;
           case 23:a[0]='h';a[1]='a';a[2]='r';a[3]='m';q=4;break;
           case 24:a[0]='r';a[1]='a';a[2]='n';a[3]='k';q=4;break;
           case 25:a[0]='m';a[1]='e';a[2]='n';a[3]='u';q=4;break;
           case 26:a[0]='c';a[1]='a';a[2]='s';a[3]='e';q=4;break;
           case 27:a[0]='o';a[1]='n';a[2]='e';q=3;break;
           case 28:a[0]='r';a[1]='o';a[2]='w';q=3;break;
           case 29:a[0]='c';a[1]='o';a[2]='w';q=3;break;

     }
     printf("开始游戏！\n");
	 printf("这是初级难度的游戏:\n");
     printf("系统将提示被猜单词的第一个字母及单词所含字母数给你：%c",a[0]);
     for(i=1;i<q;i++)
     {
     printf("%c",c);
	 }
	 printf("\n");
     printf("您将有%d次机会\n",A);
	 for(o=1;o<=A;o++)
	 {
	    for(j=1;j<=A;j++);
	    {
	       flag=0;
	       printf("已经猜对的单词不能重复键入，不能键入首字母，否则程序错误\n");
		   printf("请输入你猜测的字母：\n");

		   scanf("%s",&b[j]);
		   //b[j]=getchar();
		   printf("%c",b[j]);
		   //printf("检查1");
           r=A-o;
           for(i=0;i<q;i++)
           {
		      if(a[i]==b[j])
              {
                  		   //printf("检查2");
			    flag=1;
		        printf("恭喜你，猜对了!\n");
		        printf("剩余的机会：%d\n",r);
		        printf("您所猜单词在第%d位",i+1);
	            printf("单词为：%c",a[i]);
		        p++;
		       
		       if(p==q)
			  {
			     printf("\n你成功猜出了这个单词！将在初级排行榜上＋1分\n");
			     t++;
			     game[U].Amark=t;
			     rank();
	             printf("退出请按1\n");
	             printf("继续游戏请按2\n");
	             scanf("%d",&l);
	             switch(l)
	             {
	 	                  case 1:system("pause");break;
	 	                  case 2:Agame();break;
	 	                  default:printf("请选择1-2\n");break;
	             }
               }
           }
	        }
           if(flag==0)
		     {
		     printf("很遗憾，猜错了！\n");
		     printf("猜错的单词为：%c\n",b[j]);
		     printf("剩余的机会：%d\n",r);
		     }
        }
     }
     printf("好可惜！你未能猜出这个单词！\n");
	 printf("这个单词是\n:");
	 for(i=0;i<q;i++)
	 {
	    printf("%c",a[i]);
	 }
}
void Bgame()
{
int i,j,k,l,p,q,flag,o,r;
int t=game[U].Bmark;
     char a[9];
     char b[B+1];
     char c='-';
     p=1;
     srand(time(NULL));
     k=rand()%11;
     switch(k)
     {
     case 0 :a[0]='s';a[1]='p';a[2]='e';a[3]='c';a[4]='i';a[5]='a';a[6]='l';q=7;break;
     case 1 :a[0]='r';a[1]='e';a[2]='w';a[3]='a';a[4]='r';a[5]='d';q=6;break;
     case 2 :a[0]='s';a[1]='o';a[2]='m';a[3]='e';a[4]='w';a[5]='h';a[6]='a';a[7]='t';q=8;break;
     case 3 :a[0]='q';a[1]='u';a[2]='e';a[3]='s';a[4]='t';a[5]='i';a[6]='o';a[7]='n';q=8;break;
     case 4 :a[0]='t';a[1]='h';a[2]='o';a[3]='u';a[4]='g';a[5]='h';q=6;break;
     case 5 :a[0]='a';a[1]='c';a[2]='t';a[3]='i';a[4]='o';a[5]='n';q=6;break;
     case 6 :a[0]='c';a[1]='o';a[2]='m';a[3]='p';a[4]='u';a[5]='t';a[6]='e';a[7]='r';q=8;break;
     case 7 :a[0]='i';a[1]='n';a[2]='c';a[3]='l';a[4]='u';a[5]='d';a[6]='e';q=7;break;
     case 8 :a[0]='s';a[1]='h';a[2]='o';a[3]='u';a[4]='l';a[5]='d';a[6]='e';a[7]='r';q=8;break;
     case 9 :a[0]='a';a[1]='d';a[2]='v';a[3]='i';a[4]='c';a[5]='e';q=6;break;
}
printf("开始游戏！\n");
printf("这是中级难度的游戏:\n");
     printf("系统将提示被猜单词的第一个字母及单词所含字母数给你：%c\n",a[0]);
     for(i=1;i<q;i++)
     {
     printf("%c",c);
	 }
	 printf("\n");
     printf("您将有%d次机会",B);
	 for(o=1;o<=B;o++)
	 {
	    for(j=1;j<=B;j++);
	    {
	       flag=0;
	       printf("已经猜对的单词不能重复键入，不能键入首字母，否则程序错误\n");
		   printf("请输入你猜测的字母：\n");
		   scanf("%s",&b[j]);
           r=B-o;
           for(i=0;i<q;i++)
           {
		      if(a[i]==b[j])
              {
			    flag=1;
		        printf("恭喜你，猜对了!\n");
		        printf("剩余的机会：%d\n",r);
		        printf("您所猜单词在第%d位\n",i+1);
	            printf("单词为：%c",a[i]);
		        p++;
		       }
		       if(p==q)
			  {
			     printf("你成功猜出了这个单词！将在初级排行榜上＋3分\n");
			     t=t+3;
			     game[U].Bmark=t;
			     rank();
	             printf("退出请按1\n");
	             printf("继续游戏请按2\n");
	             scanf("%d",&l);
	             switch(l)
	             {
	 	                  case 1:system("pause");break;
	 	                  case 2:Bgame();break;
	 	                  default:printf("请选择1-2\n");break;
	             }
               }
	        }
           if(flag==0)
		   {
		   printf("很遗憾，猜错了！\n");
		   printf("猜错的单词为：%c\n",b[j]);
		   printf("剩余的机会：%d\n",r);
		   }
        }
     }
     printf("好可惜！你未能猜出这个单词！\n");
	 printf("这个单词是\n:");
	 for(i=0;i<p;i++)
	 {
	    printf("%c",a[i]);
	 }
}
void Cgame()
{
int i,j,k,l,p,q,flag,o,r;
int t=game[U].Cmark;
     char a[13];
     char b[C+1];
     char c='-';
     p=1;
     srand(time(NULL));
     k=rand()%5;
     switch(k)
{
case 0:
a[0]='j';a[1]='o';a[2]='u';a[3]='r';a[4]='n';a[5]='a';a[6]='l';a[7]='i';a[8]='s';a[9]='t';q=10;break;
case 1:
a[0]='d';a[1]='i';a[2]='s';a[3]='c';a[4]='o';a[5]='u';a[6]='r';a[7]='a';a[8]='g';a[9]='e';q=10;break;
case 2:
a[0]='u';a[1]='n';a[2]='d';a[3]='e';a[4]='r';a[5]='s';a[6]='t';a[7]='a';a[8]='n';a[9]='d';q=10;break;
case 3:
a[0]='p';a[1]='l';a[2]='a';a[3]='y';a[4]='g';a[5]='r';a[6]='o';a[7]='u';a[8]='n';a[9]='d';q=10;break;
case 4:
a[0]='d';a[1]='i';a[2]='s';a[3]='c';a[4]='o';a[5]='u';a[6]='r';a[7]='a';a[8]='g';a[9]='e';q=10;break;
}
printf("开始游戏！\n");
printf("这是高级难度的游戏:\n");
     printf("系统将提示被猜单词的第一个字母及单词所含字母数给你：%c\n",a[0]);
     for(i=1;i<q;i++)
     {
     printf("%c",c);
	 }
     printf("您将有%d次机会",C);
	 for(o=1;o<=C;o++)
	 {
	    for(j=1;j<=C;j++);
	    {
	    	flag=0;
	       printf("已经猜对的单词不能重复键入，不能键入首字母，否则程序错误\n");
		   printf("请输入你猜测的字母：\n");
		   scanf("%s",&b[j]);
           r=C-o;
           for(i=0;i<q;i++)
           {
		      if(a[i]==b[j])
              {
			    flag=1;
		        printf("恭喜你，猜对了!\n");
		        printf("剩余的机会：%d\n",r);
		        printf("您所猜单词在第%d位",i+1);
	            printf("单词为：%c",a[i]);
		        p++;
		       }
		       if(p==q)
			  {
			     printf("你成功猜出了这个单词！将在初级排行榜上＋5分\n");
			     t=t+5;
			     game[U].Cmark=t;
			     rank();
	             printf("退出请按1\n");
	             printf("继续游戏请按2\n");
	             scanf("%d",&l);
	             switch(l)
	             {
	 	                  case 1:system("pause");break;
	 	                  case 2:Cgame();break;
	 	                  default:printf("请选择1-2\n");break;
	             }
               }
	        }
           if(flag==0)
		     {
		     printf("很遗憾，猜错了！\n");
		     printf("猜错的单词为：%c\n",b[j]);
		     printf("剩余的机会：%d\n",r);
		     }
        }
     }
     printf("好可惜！你未能猜出这个单词！\n");
	 printf("这个单词是\n:");
	 for(i=0;i<q;i++)
	 {
	    printf("%c",a[i]);
	 }
}
void Amark()
{
	int j;
	printf("初级玩家排行top 5\n");
	printf("\n-----玩家姓名            成绩-----\n");
	for(j=0;j<5;j++)
	{
	printf("%s",game[j].name );
	printf("%15d",game[j].Amark);
	}
}
void Bmark()
{
	int j;
    printf("中级玩家排行top 5\n");
	printf("\n-----玩家姓名            成绩-----\n");
	for(j=0;j<5;j++)
	{
	printf("%s",game[j].name );
	printf("%15d",game[j].Bmark);
	}
}
void Cmark()
{
	int j;
    printf("高级玩家排行top 5\n");
	printf("\n-----玩家姓名            成绩-----\n");
	for(j=0;j<5;j++)
	{
	printf("%s",game[j].name );
	printf("%15d",game[j].Bmark);
    }
}
