/*题目三：
一.	题目内容：
编写程序实现简单的学生信息管理系统。
要求：
1.学生信息包括：学号，姓名和成绩
2.系统以菜单方式工作，输入特定指令可实现不同功能
3.系统应实现以下功能：
（1）学生信息读取功能（学生信息用txt文件保存） 
（2）学生信息浏览功能
（3）通过学号或姓名查找学生信息
（4）学生信息的删除与修改。
二. 构建思路：
1.首先用菜单的格式,写出菜单栏，每个功能分门别类.并引用switch（）函数与菜单结合，
使题目中的要求能用不同的函数实现； 
2.学生信息用txt文件保存，即要用文件的知识，需要自学文件； 
3.*特别注意，必须对增加的学生用学号进行排序，负责怎么用字符串数组查找呢？ 
*/

#include <stdio.h>//输入输出库；
#include<stdlib.h>//标准库头文件 ；（system（）函数）？ 
#include<string.h>//字符串处理库的头文件； 
#define N 20//最大学生人数 ； 
#define M 10//姓名和学号最大字符数； 

struct record//用结构体统计信息； 
{
     char name[M+1]; //姓名；                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
     char stuID[M+1];//学号； 
     int mark;//成绩；  
}stu[N];
//定义全局变量，方便在那些函数中调用；
//将全部需要调用的函数放在一起，便于阅读程序功能； 
     int p=1,m,n;//定义全局变量；       
     //函数声明：调用一些自定义功能的函数； 
     void menu();//以菜单方式工作；
     void statement(); 
     void read();//读取文件； 
     void seek();//查找学生信息； 
     void add(); //增加学生信息；
     void rank(); 
     void modify();//修改学生信息； 
     void delete(); //删除学生信息； 
     void display();//显示全部信息；
	 void save(); //保存新增信息； 
int main()//主函数中调用菜单； 
{
     while(p)
     menu();//菜单开始工作； 
     system("pause");//syetem()就是调用从程序中调用系统命令，
     //“pause”就是从程序中调用"pause"命令；
     return 0;
}
     
     void statement()            
     {
       printf("1.欢迎查看系统说明！\n");
       printf("2.请按照菜单功能键入菜单编号.\n");
       printf("3.谢谢你的使用！\n");    
     }
     
     void read()
     {
       char *p="student.txt";     
       FILE *fp;//FILE是变量类型，用于文件；*fp,指针指向FILE类型的对象。 
       int i=0;   
       if((fp=fopen("D:\\student.txt","r"))==NULL)
       {
       // fopen（）标准函数，打开磁盘文件student.txt，用于读，送返指针，指向FILE类型对象；
       //fscanf:用于从文件读入数据；scanf：用于从键盘读入数据；     
       printf("Open file is error!Strike any key to exit!",p);
       //系统没有找到文件，错误请按任意键继续，等待用户按一个键，然后返回； 
       system("pause");//系统中止？ 
       exit(0);
       }
       while (fscanf(fp,"%s%s%d",stu[i].name,stu[i].stuID,&stu[i].mark)==3)
       {
            i++;
       }
       fclose(fp);
       n=i;//录入了n个人，n是全局变量，对全局起作用； 
       printf("录入完毕！\n");
     } 
     
     void seek()
     {
       int i,item,flag;
       char s1[M+1];
       printf("\n---------------1.按学号查询---------------\n");
       printf("\n---------------2.按姓名查询---------------\n");
       printf("\n---------------3.退出本菜单---------------\n");
       printf("请选择子菜单编号：\n\n");   
       scanf("%d",&item);
       flag=0;
       switch(item)
       {
         case 1:
            printf("请输入要查询的学生学号\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
            if(strcmp(stu[i].stuID,s1)==0)
            {
            flag=1;
            printf("学生学号    学生姓名     成绩\n");
            printf("-----------------------------\n\n");
            printf("%s%s%d",stu[i].stuID,stu[i].name,stu[i].mark);
            } 
            if(flag==0) 
            printf("该学号不存在\n\n");
          break; 
          case 2:
          printf("请输入要查询的学生姓名\n");
          scanf("%s",s1);
          for(i=0;i<n;i++)
             if(strcmp(stu[i].name,s1)==0)
             {
             flag=1;
             printf("学生学号    学生姓名     成绩\n");
             printf("-----------------------------\n\n");
             printf("%s%s%d",stu[i].stuID,stu[i].name,stu[i].mark);
             } 
             if(flag==0) 
             printf("该姓名不存在\n\n");
          break;
          case 3:return;     
          default:printf("请在1-3之间选择\n\n"); 
       }
     } 
     
     void add()
     {
       int i=n,j,flag;
       printf("\n请输入增加学生数：\n");
       scanf("%d",&m);
       do
       {
          flag=1;
          while(flag)
             {
                flag=0;
                printf("\n请输入第%d个学生学号：\n",i+1);
                scanf("%s",&stu[i].stuID);
                for(j=0;j<i;j++)
                   if(strcmp(stu[i]. stuID,stu[j].stuID)==0)
                   {
                      printf("\n已有该学号，请重新输入！\n");
                      flag=1;
                      break;//如有重复直接跳出此层循环； 
                   }
              } 
         printf("\n请输入第%d个学生的姓名：\n",i+1);
         scanf("%s",stu[i].name);
         printf("\n请输入第%d个学生的成绩：\n",i+1);  
         scanf("%d",&stu[i].mark);             
       if (flag==0)
          {
           i=i;
           i++;        
           }
       }   
       while (i<n+m);
       n=n+m;//全局变量n个学生新增了m 个学生信息； 
       printf("录入完毕！\n");
       rank();
     }
     
     void save()
     {
       int i;
       FILE *fp;
       fp=fopen("D:\\student.txt","w");
       for(i=0;i<n;i++)
       {
        fprintf(fp,"%s %s %d\n",stu[i].stuID,stu[i].name,stu[i].mark);            
       }   
        fclose(fp);  
          
          
     }
     
     void rank()
     {
       int i,j,*p,*q,s;
       char temp[2];
       for(i=0;i<n-1;i++)
       {
           for(j=n-1;j>i;j--)//用字符串复制函数，作用是将字符串2复制到字符数组1中去； 
               if(strcmp(stu[j-1].stuID,stu[j].stuID)>0)
               {//如果前一个字符串学号大于后一个字符穿学号，则把前后信息都交换过来； 
                  strcpy(temp,stu[j-1].stuID);//相当于temp=a;a=b;b=temp;         
                  strcpy(stu[j-1].stuID,stu[j].stuID); 
                  strcpy(stu[j].stuID,temp); 
                  strcpy(temp,stu[j-1].name);           
                  strcpy(stu[j-1].name,stu[j].name); 
                  strcpy(stu[j].name,temp);//mark的类型是int,不能用字符串数组交换，得用指针； 
                  p=&stu[j-1].mark;
                  q=&stu[j].mark;
                  s=*q;
                  *q=*p;
                  *p=s;//用指针交换两个int型变量；                     
               }              
       } 
	   save();     
     }
      
     void modify()
     {
       int i,item,j;
       char s1[M+1],s2[M+1];
       printf("\n请输入要修改的学生学号\n");
       scanf("%s",s1);//不能修改学号？ 
       for(i=0;i<n;i++)    
       if(strcmp(stu[i].stuID,s1)==0)
       j=i;
       printf("\n-------------------\n");
       printf("\n     1.修改姓名    \n"); 
       printf("\n    2.修改成绩     \n");  
       printf("\n    3.退出本菜单   \n"); 
       printf("\n-------------------\n"); 
       while(1)
       {
           printf("请选择子菜单编号：\n");       
           scanf("%d",&item);
           switch(item)
           {
           case 1:
                printf("请输入新的姓名\n");
                scanf("%s",s2);
                strcpy(stu[j].name,s2);
           break; 
           case 2:
                printf("请输入新的成绩\n");
                scanf("%d",&stu[j].mark);//变量是整形，不能用字符串函数表示  
           break;
           case 3:
		   return;     
           default:printf("\n请在1-3之间选择\n"); 
           }    
       } 
     }
     
     void delete()
     {
       int i,j,flag=0;
       char s1[N+1];
       printf("\n请输入要删除的学生学号\n");
       scanf("%s",s1);
       for(i=0;i<n;i++)    
       if(strcmp(stu[i].stuID,s1)==0)
       //突然发现要把学号用字符串形式表示！！
       //不然怎么用字符串比较判别键入的学号是否重复或者存在？ 
       {
           flag=1;//这个用法很重要，学会表达原因； 
           for(j=i;j<n-1;j++); 
           stu[j]=stu[j+1];                         
       }   
       if(flag==0)
       printf("\n该学号不存在！\n");
       if(flag==1)
       {
           printf("\n删除成功！");
           n--;//全局变量的学生信息数减少；       
       } 
     }   
       
     void display()
     {
       read();
       int i;
       printf("\n所有学生的信息如下：\n");
       printf("\n学号       姓名     成绩   \n");
       printf("\n-------------------------------\n");
       for(i=0;i<n;i++)//for()显示全部信息；   
       {
          printf("%s%12s%12d",stu[i].stuID,stu[i].name,stu[i].mark);
          printf("\n\n");
       }    
     }
     
     void menu()
     {
       int num;
       printf("\n\n\n\n                         **********    学生管理系统   *********\n");
       printf("                                 --------------------------------------\n");
       printf("\n                               1.-------    系统说明及帮助    -------\n"); 
       printf("\n                               2.-------     查找学生信息     -------\n"); 
       printf("\n                               3.-------     增加学生信息     -------\n"); 
       printf("\n                               4.-------     修改学生信息     -------\n"); 
       printf("\n                               5.-------     删除学生信息     -------\n"); 
       printf("\n                               6.-------     显示全部信息     -------\n");
       printf("\n                               --------------------------------------\n");
       printf("请选择功能编号：\n");
       scanf("%d",&num);
       switch(num)
       {
             case 1:statement();break;
             case 2:seek();break;
             case 3:add();break;
             case 4:modify();break;
             case 5:delete();break;
             case 6:display();break; 
       default:printf("\n请在数字0-6之间选择\n");                    
       } 
     } 


