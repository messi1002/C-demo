/*  ��Ŀһ
    ����һ���򵥵Ĳµ���������Ϸ����Ϸ��ÿ��ֻ�ܲ�һ����ĸ�������Ϸ�߲µ���ĸ�ڵ����У����������еĸ���ĸ������Ϊ�Ѳ³������磺���ԭ������apple����Ϸ�߲³���
p�������Ӧ��ʾ��ǰ�³��Ĳ�ȱ����Ϊ-pp--������ѡ��ʱ�����ƻ�´�������ƣ���
��ʱ����ߴ�����������Ϸʧ�ܡ�
1-5����ĸΪ������6-9����ĸΪ�м���10����ĸ����Ϊ�߼����´������ʱ�������Զ���

����Ҫ��
1.�����Ϸ����Ϣ��ʽ����¼�û������ɼ��������棬�´ο�ʼʱ��ѡ���û�������Ϸ���û���Ϣ��š�
2.��dadt.txt�С������������а񣬱�����ͬ����ǰ�����ĳɼ���
3.���ݵ��ʳ������ò�ͬ�������Ϸ��
4.��Ϸ�����У��´����ĸ������¼������ÿ�β²����ϷӦ��ʾ����ǰ�³��Ĳ�ȱ���ʣ��Լ���ǰ�´��������ĸ����ʣ�µĻ��ᡣ
5.�ṩ��Ӧ��ȫ���ƣ���֤����Ľ�׳�ԣ���ѡ�񵥴ʳ���ʱ��Ӧ����������ַ���������ɳ������ȡ�
6.�ṩѡ��һ���������ᡣ�����ָ��λ���ϵ�һ����ĸ�ȡ�
*/
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 10//������ѧ������ַ�����
#define A 8
#define B 12
#define C 18
struct record//�ýṹ��ͳ����Ϣ��
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
     printf("\n\n\n-----------------�µ�����Ϸ---------------\n");
     printf("\n\n\n\n\n\n       ��ӭ�����µ�����Ϸ������");
     printf("\n                 0.��Ϸ����            \n");
     printf("\n\n               1.ע��                \n");
     printf("\n\n               2.��½��Ϸ            \n");
     printf("\n\n               3.�����Ѷȳɼ����а�  \n");
     printf("\n\n               4.�м��Ѷȳɼ����а�  \n");
     printf("\n\n               5.�߼��Ѷȳɼ����а�  \n");
     printf(" �������Ӳ˵���ţ� ");
     scanf("%d",&num);
     switch(num)
     {
           case 0:statement();break;
           case 1:new();break;
           case 2:login();break;
           case 3:Amark();break;
		   case 4:Bmark();break;
		   case 5:Cmark();break;
           default:printf("��������0-5֮��ѡ��\n");break;
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
       printf("¼����ϣ�\n");
     }
void statement()
     {
       printf("1.��ӭ�鿴��Ϸ����\n");
       printf("2.�밴�ղ˵����ܼ���˵����:\n");
       printf("3.����һ���򵥵Ĳµ���������Ϸ����ÿ��ֻ�ܲ�һ����ĸ��������µ���ĸ�ڵ����У����������еĸ���ĸ������Ϊ�Ѳ³���");
	   printf("4.���磺���ԭ������apple����Ϸ�߲³���p�������Ӧ��ʾ��ǰ�³��Ĳ�ȱ����Ϊ-pp--��\n");
       printf("5.1-5����ĸΪ������6-9����ĸΪ�м���10����ĸ����Ϊ�߼����ڿ�ʼ��Ϸ������ѡ�������Ѷȡ�\n");
       printf("�����Ѷȵ�");
	   printf("6.���ǽ��ֱ𱣴�������м����߼���Ϸ��ǰ�����û��ĳɼ����������鿴��");
	   printf("7.лл����ʹ�ã�\n");
     }
void new()
     {
     printf("\n��ӭע��\n");
     int i=n,j,flag;
     flag=1;
     while(flag)
          {
          flag=0;
          printf("\n�����������û�����\n");
          scanf("%s",game[i].name);
          for(j=0;j<i;j++)
                   if(strcmp(game[i]. name,game[j].name)==0)
                   {
                      printf("\n���и����֣����������룡\n");
                      flag=1;
                      break;
                   }
          }
          if (flag==0)
          {
          printf("\nע��ɹ���\n");
          printf("\n��¼�󼴿ɱ���������Ϸ�ɼ�\n");
          n++;
          game[i].Amark=0;
		  game[i].Bmark=0;
		  game[i].Cmark=0;
          printf("��ĳ�ʼ�����ɼ�Ϊ��%d\n",game[i].Amark);
          printf("��ĳ�ʼ�м��ɼ�Ϊ��%d\n",game[i].Bmark);
          printf("��ĳ�ʼ�߼��ɼ�Ϊ��%d\n",game[i].Cmark);
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
                  strcpy(temp,game[j-1].name);//�൱��temp=a;a=b;b=temp;
                  strcpy(game[j-1].name,game[j].name);
                  strcpy(game[j].name,temp);
                  if(game[j-1].Bmark>game[j].Bmark )
                  p=&game[j-1].Bmark;
                  q=&game[j].Bmark;
                  c=*a;
                  *a=*b;
                  *b=c;
                  strcpy(temp,game[j-1].name);//�൱��temp=a;a=b;b=temp;
                  strcpy(game[j-1].name,game[j].name);
                  strcpy(game[j].name,temp);
                  if(game[j-1].Cmark>game[j].Cmark )
                  p=&game[j-1].Cmark;
                  q=&game[j].Cmark;
                  f=*e;
                  *e=*d;
                  *d=f;
                  strcpy(temp,game[j-1].name);//�൱��temp=a;a=b;b=temp;
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
	 printf("�����������û���\n");
	 flag=0;
	 scanf("%s",s1);
	 for(U=0;U<i;U++)
	    if(strcmp(s1,game[U].name)==0)
        {
           printf("��½�ɹ�����ѡ����Ϸ�Ѷȣ�\n");
           flag=1;
           break;
        }
     if(flag==0)
     {
     printf("���û�����δ��ע�ᣬ���������룡");
	 login();
	 }

	 int item;
	 printf("1.�����Ѷ�\n");
	 printf("2.�м��Ѷ�\n");
	 printf("3.�߼��Ѷ�\n");
	 printf("4.�˳�\n");
	 printf("��ѡ���Ӳ˵���ţ�\n");
	 scanf("%d",&item);
	 switch(item)
	 {
	       case 1:Agame();break;
	       case 2:Bgame();break;
		   case 3:Cgame();break;
		   case 4:system("pause");
	       default:printf("\n����1-3֮��ѡ��\n");break;
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
     printf("��ʼ��Ϸ��\n");
	 printf("���ǳ����Ѷȵ���Ϸ:\n");
     printf("ϵͳ����ʾ���µ��ʵĵ�һ����ĸ������������ĸ�����㣺%c",a[0]);
     for(i=1;i<q;i++)
     {
     printf("%c",c);
	 }
	 printf("\n");
     printf("������%d�λ���\n",A);
	 for(o=1;o<=A;o++)
	 {
	    for(j=1;j<=A;j++);
	    {
	       flag=0;
	       printf("�Ѿ��¶Եĵ��ʲ����ظ����룬���ܼ�������ĸ������������\n");
		   printf("��������²����ĸ��\n");

		   scanf("%s",&b[j]);
		   //b[j]=getchar();
		   printf("%c",b[j]);
		   //printf("���1");
           r=A-o;
           for(i=0;i<q;i++)
           {
		      if(a[i]==b[j])
              {
                  		   //printf("���2");
			    flag=1;
		        printf("��ϲ�㣬�¶���!\n");
		        printf("ʣ��Ļ��᣺%d\n",r);
		        printf("�����µ����ڵ�%dλ",i+1);
	            printf("����Ϊ��%c",a[i]);
		        p++;
		       
		       if(p==q)
			  {
			     printf("\n��ɹ��³���������ʣ����ڳ������а��ϣ�1��\n");
			     t++;
			     game[U].Amark=t;
			     rank();
	             printf("�˳��밴1\n");
	             printf("������Ϸ�밴2\n");
	             scanf("%d",&l);
	             switch(l)
	             {
	 	                  case 1:system("pause");break;
	 	                  case 2:Agame();break;
	 	                  default:printf("��ѡ��1-2\n");break;
	             }
               }
           }
	        }
           if(flag==0)
		     {
		     printf("���ź����´��ˣ�\n");
		     printf("�´�ĵ���Ϊ��%c\n",b[j]);
		     printf("ʣ��Ļ��᣺%d\n",r);
		     }
        }
     }
     printf("�ÿ�ϧ����δ�ܲ³�������ʣ�\n");
	 printf("���������\n:");
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
printf("��ʼ��Ϸ��\n");
printf("�����м��Ѷȵ���Ϸ:\n");
     printf("ϵͳ����ʾ���µ��ʵĵ�һ����ĸ������������ĸ�����㣺%c\n",a[0]);
     for(i=1;i<q;i++)
     {
     printf("%c",c);
	 }
	 printf("\n");
     printf("������%d�λ���",B);
	 for(o=1;o<=B;o++)
	 {
	    for(j=1;j<=B;j++);
	    {
	       flag=0;
	       printf("�Ѿ��¶Եĵ��ʲ����ظ����룬���ܼ�������ĸ������������\n");
		   printf("��������²����ĸ��\n");
		   scanf("%s",&b[j]);
           r=B-o;
           for(i=0;i<q;i++)
           {
		      if(a[i]==b[j])
              {
			    flag=1;
		        printf("��ϲ�㣬�¶���!\n");
		        printf("ʣ��Ļ��᣺%d\n",r);
		        printf("�����µ����ڵ�%dλ\n",i+1);
	            printf("����Ϊ��%c",a[i]);
		        p++;
		       }
		       if(p==q)
			  {
			     printf("��ɹ��³���������ʣ����ڳ������а��ϣ�3��\n");
			     t=t+3;
			     game[U].Bmark=t;
			     rank();
	             printf("�˳��밴1\n");
	             printf("������Ϸ�밴2\n");
	             scanf("%d",&l);
	             switch(l)
	             {
	 	                  case 1:system("pause");break;
	 	                  case 2:Bgame();break;
	 	                  default:printf("��ѡ��1-2\n");break;
	             }
               }
	        }
           if(flag==0)
		   {
		   printf("���ź����´��ˣ�\n");
		   printf("�´�ĵ���Ϊ��%c\n",b[j]);
		   printf("ʣ��Ļ��᣺%d\n",r);
		   }
        }
     }
     printf("�ÿ�ϧ����δ�ܲ³�������ʣ�\n");
	 printf("���������\n:");
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
printf("��ʼ��Ϸ��\n");
printf("���Ǹ߼��Ѷȵ���Ϸ:\n");
     printf("ϵͳ����ʾ���µ��ʵĵ�һ����ĸ������������ĸ�����㣺%c\n",a[0]);
     for(i=1;i<q;i++)
     {
     printf("%c",c);
	 }
     printf("������%d�λ���",C);
	 for(o=1;o<=C;o++)
	 {
	    for(j=1;j<=C;j++);
	    {
	    	flag=0;
	       printf("�Ѿ��¶Եĵ��ʲ����ظ����룬���ܼ�������ĸ������������\n");
		   printf("��������²����ĸ��\n");
		   scanf("%s",&b[j]);
           r=C-o;
           for(i=0;i<q;i++)
           {
		      if(a[i]==b[j])
              {
			    flag=1;
		        printf("��ϲ�㣬�¶���!\n");
		        printf("ʣ��Ļ��᣺%d\n",r);
		        printf("�����µ����ڵ�%dλ",i+1);
	            printf("����Ϊ��%c",a[i]);
		        p++;
		       }
		       if(p==q)
			  {
			     printf("��ɹ��³���������ʣ����ڳ������а��ϣ�5��\n");
			     t=t+5;
			     game[U].Cmark=t;
			     rank();
	             printf("�˳��밴1\n");
	             printf("������Ϸ�밴2\n");
	             scanf("%d",&l);
	             switch(l)
	             {
	 	                  case 1:system("pause");break;
	 	                  case 2:Cgame();break;
	 	                  default:printf("��ѡ��1-2\n");break;
	             }
               }
	        }
           if(flag==0)
		     {
		     printf("���ź����´��ˣ�\n");
		     printf("�´�ĵ���Ϊ��%c\n",b[j]);
		     printf("ʣ��Ļ��᣺%d\n",r);
		     }
        }
     }
     printf("�ÿ�ϧ����δ�ܲ³�������ʣ�\n");
	 printf("���������\n:");
	 for(i=0;i<q;i++)
	 {
	    printf("%c",a[i]);
	 }
}
void Amark()
{
	int j;
	printf("�����������top 5\n");
	printf("\n-----�������            �ɼ�-----\n");
	for(j=0;j<5;j++)
	{
	printf("%s",game[j].name );
	printf("%15d",game[j].Amark);
	}
}
void Bmark()
{
	int j;
    printf("�м��������top 5\n");
	printf("\n-----�������            �ɼ�-----\n");
	for(j=0;j<5;j++)
	{
	printf("%s",game[j].name );
	printf("%15d",game[j].Bmark);
	}
}
void Cmark()
{
	int j;
    printf("�߼��������top 5\n");
	printf("\n-----�������            �ɼ�-----\n");
	for(j=0;j<5;j++)
	{
	printf("%s",game[j].name );
	printf("%15d",game[j].Bmark);
    }
}
