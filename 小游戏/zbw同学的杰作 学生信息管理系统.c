#include <stdio.h>//头文件
#include <stdlib.h>//包含最常用的系统函数
#include <string.h>//关于字符数组的函数定义的头文件 
#include <conio.h>
//定义结构体 
struct USER//定义移动用户结构体变量
{ 
	char name[20];    //定义输入名字的数组
	char phone_number[100]; //定义输入电话号码的数组
	char address[60]; //定义输入地址的数组
	char sex[5];
	int age;
	char job[40];
	char identify[20];
} user1[100]; //默认有100个数据 
int n=0;//记录移动用户数量  
FILE *fp;//定义文件 
//程序用到的所有函数  
void main_order();//主菜单
void increase_person();//增加用户函数
void readfile();//文件读入函数
void writefile();//文件写入函数
void change_information();//修改联系人函数
void change_name();//姓名修改
void change_by_name();//按姓名查找修改
void change_by_phone_number();//按电话号码查找修改 
void change_phone_number();//电话号码修改
void find();//查找联系人函数
void find_name();//按姓名查找
void find_phone_number();//按电话号码查找
void delete_p();//删除联系人函数
void delete_all();//全部删除
void delete_single();//单个删除
void cancel_number();//删除用户的某一项数据 
void add_1();//增加用户的某一项数据 
void show_all();//用户信息显示
void sort_by_identify();//根据身份证号对用户进行排序 
int main()//主函数main
{
    readfile();    //读入文件
	while(1)//循环（永远进行） 
	{	
		main_order();//调用主菜单函数
	}
} 
void readfile()//读取文件 
{
	if((fp=fopen("C:\\移动用户信息.txt","r"))==NULL)  //以只读方式打开判定文件是否为空
	{ 
		printf("\n\t\t\t    移动用户信息文件不存在");    //判断结论
		if((fp=fopen("移动用户信息.txt","w"))==NULL) //只写方式判断
		{ 
			printf("\n\t\t建立失败");      //为空结论
			exit(0);                        //退出
		}                                  
		else                               //不为空则执行else
		{ 
		    printf("\n\t-----------------欢迎使用移动用户管理系统------------------");
		    printf("\n\t                    用户文件已建立                         "); 
		    printf("\n\t                   按任意键进入主菜单                      "); 
		    printf("\n\t-----------------------------------------------------------");
		    getch(); 
		    return;
		}
		exit(0); 
	} 
	fseek(fp,0,2); //文件位置指针移动到文件末尾 
	if(ftell(fp)>0) //文件不为空 
	{ 
		rewind(fp); //文件位置指针移动到文件开始位置
		for (n=0;!feof(fp) && fread(&user1[n],sizeof(struct USER),1,fp);n++);
		{
			printf("\n\t-----------------欢迎使用移动用户管理系统----------------");
		    printf("\n\t                   文件导入成功!                          "); 
		    printf("\n\t                 按任意键返回主菜单                      "); 
		    printf("\n\t---------------------------------------------------------");
			getch();
			return;
		}
	}
	printf("\n\t-----------------欢迎使用移动用户管理系统----------------");
	printf("\n\t                     文件导入成功!                        "); 
	printf("\n\t            移动用户信息文件中无任何纪录                 "); 
	printf("\n\t                  按任意键返回主菜单                     "); 
	printf("\n\t---------------------------------------------------------");
	getch();
	return;  
}
void main_order()//文件主菜单 
{
	char c; 
	system("cls"); 
	printf("\n\t\t|---------------欢迎您使用移动用户管理系统-------------|"); 
	printf("\n\t\t|                     1-添加新用户                     |"); 
	printf("\n\t\t|                     2-查询和显示用户信息             |");
	printf("\n\t\t|                     3-删除用户                       |"); 
	printf("\n\t\t|                     4-修改用户信息                   |");
	printf("\n\t\t|                     5-注销用户手机号码               |");
	printf("\n\t\t|                     6-增加用户手机号码               |");
	printf("\n\t\t|                     7-保存退出                       |"); 
	printf("\n\t\t|                     8-根据身份证号码进行用户排序     |"); 
	printf("\n\t\t|                     0-不保存退出                     |"); 
	printf("\n\t\t|------------------------------------------------------|"); 
	printf("\n\t\t请选择您所所要的服务："); 
	c=getch(); 
	switch (c) /*对于上边的选择项目*/
	{ 
	    case '1':increase_person();break;//增加用户 
	    case '2':find();break; //查找用户 
	    case '3':delete_p();break;//删除用户 
	    case '4':change_information();break;//修改用户信息 
	    case '5':cancel_number();break;//注销用户手机号 
	    case '6':add_1();break;//增加用户手机号 
		case '7':writefile();break; //保存退出 
		case '8':sort_by_identify();break; 
		case '0':exit(0); //不保存退出 
		default:main_order(); /*若没有则返回主菜单等待输入*/
	} 
}
void increase_person()//添加移动用户 
{
	char k[2]={"\t"};
	printf("\n\t\t------------------ 请输入移动用户信息 --------------------\n"); 
	printf("\n\t\t输入用户姓名:"); 
	scanf("%s",user1[n].name);    //键盘输入
	printf("\n\t\t输入用户电话号码:"); 
	scanf("%s",user1[n].phone_number); 
	printf("\n\t\t输入用户家庭住址:"); 
	scanf("%s",user1[n].address); 
	printf("\n\t\t输入用户性别：");
	scanf("%s",user1[n].sex);
	printf("\n\t\t输入用户年龄：");
	scanf("%d",&user1[n].age);
	printf("\n\t\t输入用户工作：");
	scanf("%s",user1[n].job); 
	printf ("\n\t\t输入用户身份证号：");
	scanf("%s",user1[n].identify);
	strcat(user1[n].phone_number,k);
	//strcpy(user1[n].phone_number,k);
	n++;                          //统计个数
	printf("\n\t\t是否继续添加用户?(y/n):"); //是否继续添加新用户
	if(getch()=='y')
	{
		increase_person();
	} 
} 
void writefile()//写入移动用户信息文件 
{
	int i; 
	if((fp=fopen("C:\\移动用户信息.txt","w"))==NULL) 
	{ 
		printf("\n\t\t文件打开失败"); 
	} 
	for(i=0;i<n;i++) 
	{ 
		if(fwrite(&user1[i],sizeof(struct USER),1,fp)!=1)//判断是否写入文件成功 
		{ 
			printf("\n\t\t写入文件错误!\n"); 
		} 
	}
	fclose(fp); //关闭文件
	printf("\n\t------------------------------------------------------"); //输出提示信息
	printf("\n\t\t移动用户信息文件已保存"); 
	printf("\n\t\t欢迎再次使用，谢谢!\n");
	printf("\n\t\t按任意键退出程序\n\t\t"); 
	printf("\n\t------------------------------------------------------");//输出完毕 
	exit(0);
} 
void find()//查询移动用户 
{
	char c; 
	system("cls"); //清除屏幕上的所有显示 
	printf("\n\t\t------------------- 显示和查询移动用户 ------------------"); 
	printf("\n\t\t|                    1-逐个显示所有                   |");
	printf("\n\t\t|                    2-按姓名查询                     |"); 
	printf("\n\t\t|                    3-按电话查询                     |"); 
	printf("\n\t\t|                    4-返回主菜单                     |");
	printf("\n\t\t|------------------------------------------------------"); 
	printf("\n\t\t请选择您所要的服务："); 
	c=getch(); 
	switch (c) 
	{ 
		case '1':show_all();break;   /*显示所有号码*/ 
		case '2':find_name();break;  /*调用按姓名查询函数*/
		case '3':find_phone_number();break;  /*调用按号码查询函数*/
		case '4':main_order();break;       /*主菜单*/
	} 
}
void show_all()//显示所有移动用户 
{
	int i; 
	system("cls");//清除屏幕上的所有显示 
	if(n!=0) 
	{ 
		printf("\n\t\t----------欢迎您查询所有移动用户信息-------------"); 
		for (i=0;i<n;i++)     /*依次序显示*/
		{ 
			printf("\n\t\t姓名： %s",user1[i].name); 
			printf("\n\t\t电话： %s",user1[i].phone_number); 
			printf("\n\t\t地址： %s",user1[i].address); 
			printf("\n\t\t工作： %s",user1[i].job);
			printf("\n\t\t性别： %s",user1[i].sex);
			printf("\n\t\t身份证号码： %s",user1[i].identify);
			printf("\n\t\t年龄： %d",user1[i].age);
			printf("\n\t\t--------------------------------------------------"); 
			if(i+1<n) 
			{ 
				printf("\n\t\t-----------------------"); 
				system("pause");//返回错误信息 
			} 
		} 
		printf("\n\t\t---------------------------------------------"); 
	} 
	else//无移动用户
	printf("\n\t\t移动用户信息中无任何纪录"); 
	printf("\n\t\t按任意键返回主菜单："); 
	getch();  
}
void find_phone_number() //按号码查询 
{
	int mark=0; 
	int i; 
	char phone[15]; 
	printf("\n\t\t------------------- 按电话查找 -------------------------");
	printf("\n\t\t请输入电话号码:"); 
	scanf("%s",phone); 
	for(i=0;i<n;i++) 
	{ 
		if(strcmp(user1[i].phone_number,phone)==0)//对比查找函数 
		{ 
			printf("\n\t\t------------ 以下是您查找的移动用户信息 ------------"); 
			printf("\n\t\t 姓名：%s",user1[i].name); 
			printf("\n\t\t 电话：%s",user1[i].phone_number); 
			printf("\n\t\t 地址：%s",user1[i].address); 
			printf("\n\t\t 工作：%s",user1[i].job);
			printf("\n\t\t 性别：%s",user1[i].sex);
			printf("\n\t\t 身份证号码：%s",user1[i].identify);
			printf("\n\t\t 年龄：%d",user1[i].age);
			printf("\n\t\t------------------------------------------------"); 
			printf("\n\t\t按任意键返回主菜单："); 
			mark++; 
			getch();
		} 
	} 
	if(mark==0) 
	{ 
		printf("\n\t\t没有找到移动用户的信息"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch();  
	} 
}

void find_name()//按姓名查询 
{
	int mark=0; 
	int i; 
	char name[20];
    printf("\n\t\t----------------按姓名查找 --------------------");
	printf("\n\t\t请输入您要查找的姓名:"); 
	scanf("%s",name); 
	for(i=0;i<n;i++) 
	{ 
		if(strcmp(user1[i].name,name)==0) 
		{ 
			printf("\n\t\t------------ 以下是您查找的移动用户信息 ---------------"); 
		    printf("\n\t\t 姓名：%s",user1[i].name); 
			printf("\n\t\t 电话：%s",user1[i].phone_number); 
			printf("\n\t\t 地址：%s",user1[i].address); 
			printf("\n\t\t 工作：%s",user1[i].job);
			printf("\n\t\t 性别：%s",user1[i].sex);
			printf("\n\t\t 身份证号码：%s",user1[i].identify);
			printf("\n\t\t 年龄：%d",user1[i].age);
			printf("\n\t\t---------------------------------------------------"); 
			mark++;
			getch();
		} 
	}
	if(mark==0) 
	{ 
		printf("\n\t\t没有找到移动用户的信息"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch();  
	}
}
void delete_p()//删除移动用户信息 
{
	char c; 
	if(n==0)     //如果移动用户信息中没有一个记录输出以下部分
	{ 
		printf("\n\t\t对不起，文件中无任何纪录"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch();  
	} 
	system("cls");      //清除屏幕上所有的显示 
	printf("\n\t\t------------  删除菜单 ----------------"); 
	printf("\n\t\t|           1-删除所有                 |");
	printf("\n\t\t|           2-删除单个                 |"); 
	printf("\n\t\t|           3-返回主菜单               |"); 
	printf("\n\t\t|--------------------------------------"); 
	printf("\n\t\t请选择您所所要的服务："); 
	c=getch();     //输入的赋予choice
	switch(c)     
	{ 
		case '1':delete_all();break; 
		case '2':delete_single();break; 
		case '3':main_order();break; 
		default:main_order();break; 
	} 
}
void delete_all()//删除所有移动用户 
{
	printf("\n\t\t确认删除?(y/n)"); 
	if(getch()=='y') 
	{ 
		fclose(fp); 
		if((fp=fopen("移动用户信息.txt","w"))==NULL)   //文件空输出
		{ 
			printf("\n\t\t不能打开文件，删除失败"); 
			readfile(); 
		} 
		n=0; 
		printf("\n\t\t记录已删除，按任意键返回主菜单"); 
		getch();  
	} 
	else 
	return; 
} 
void delete_by_name()//按姓名删除移动用户 
{
	int i,m,mark=0,a=0; 
	char name[20]; 
	printf("\n\t\t请输入要删除移动用户姓名:"); 
	scanf("%s",name);    //键盘输入姓名
	for(i=a;i<n;i++) 
	{ 
		if(strcmp(user1[i].name,name)==0) //对比字符串查找到要删除的移动用户 
		{ 
			printf("\n\t\t以下是您要删除的移动用户记录："); 
			printf("\n\t\t--------------------------------"); 
			printf("\n\t\t姓名： %s",user1[i].name); 
			printf("\n\t\t电话： %s",user1[i].phone_number); 
			printf("\n\t\t地址： %s",user1[i].address); 
			printf("\n\t\t工作： %s",user1[i].job);
			printf("\n\t\t性别： %s",user1[i].sex);
			printf("\n\t\t身份证号码： %s",user1[i].identify);
			printf("\n\t\t年龄： %d",user1[i].age);
			printf("\n\t\t--------------------------------"); 
			printf("\n\t\t是否删除?(y/n)");  
			if(getch()=='y') // 实现删除功能  
			{ 
				for(m=i;m<n-i-1;m++)
				{
					user1[m]=user1[m+1];    //将移动用户信息的项前移
					//n--;
				}
				n--;
				mark++; 
				printf("\n\t\t删除成功"); 
				printf("\n\t\t是否继续删除?(y/n)");  
				if(getch()=='y')
				{
					delete_by_name();   //继续调用删除函数
				}
				return; 
			} 
			else 
			return;
		}  
		continue; 
	} 
	if(mark==0) 
	{ 
		printf("\n\t\t没有该移动用户的纪录"); 
		printf("\n\t\t是否继续删除?(y/n)"); 
		if(getch()=='y')
		{
			delete_by_name();
		} 
		return; 
	} 
}
void delete_by_phone_number()//按电话号码删除联系人 
{
	int i,m,mark=0;    //变量定义
	char phone[20]; 
	printf("\n\t\t请输入要删除移动用户电话号码："); 
	scanf("%s",phone); 
	if(n==0) 
	{ 
		printf("\n\t\t对不起，文件中无任何记录"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch(); 
		return; 
	} 
	for(i=0;i<n;i++) 
	{ 
		if(strcmp(user1[i].phone_number,phone)==0) 
		{ 
			printf("\n\t\t以下是您要删除的移动用户记录："); 
			printf("\n\t\t姓名： %s",user1[i].name); 
			printf("\n\t\t电话： %s",user1[i].phone_number); 
			printf("\n\t\t地址： %s",user1[i].address); 
			printf("\n\t\t工作： %s",user1[i].job);
			printf("\n\t\t性别： %s",user1[i].sex);
			printf("\n\t\t身份证号码： %s",user1[i].identify);
			printf("\n\t\t年龄： %d",user1[i].age);
			printf("\n\t\t是否删除?(y/n)");
			if(getch()=='y') 
			{ 
				for(m=i;m<n-i-1;m++) //递推替换实现删除 
				{
					user1[m]=user1[m+1]; 
					//n--;
				}	
				n--;
				mark++; //记录删除次数 
				printf("\n\t\t删除成功"); 
				printf("\n\t\t是否继续删除?(y/n)"); 
				if(getch()=='y')
				{
					delete_by_phone_number();
				}
				return; 
			} 
			else 
			return; 
		} 
		continue; 
	} 
	if(mark==0) 
	{ 
		printf("\n\t\t没有该移动用户的纪录"); 
		printf("\n\t\t是否继续删除?(y/n)");
		if(getch()=='y')  
		return ; 
	} 
}
void delete_single()//删除单个用户  
{
	char c; 
	printf("\n\t----------------------------------------------------------"); 
	printf("\n\t\t   1-按姓名删除    2-按电话删除"); 
	printf("\n\t\t请选择您所所要的服务："); 
	printf("\n\t----------------------------------------------------------");
	c=getch();  
	switch (c) 
	{  
		case '1':delete_by_name();break;
		case '2':delete_by_phone_number();break;
	} 
}
void change_information()//修改移动用户信息
{ 
    char c;
    if(n==0)
    {
    	printf("\n\t\t对不起，文件中无任何纪录"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch(); 
		return; 	
    }
    system("cls"); 
	printf("\n\t\t-----------------修改移动用户菜单-----------------------");
	printf("\n\t\t|               1-按姓名修改                           |");
	printf("\n\t\t|               2-按电话修改                           |"); 
	printf("\n\t\t|                任意键-按返回主菜单                   |");
	printf("\n\t\t------------------------------------------------------");
 	c=getch(); 
	switch(c) 
	{ 
		case '1':change_by_name();break; 
		case '2':change_by_phone_number();break; 
		default:main_order();break;
	} 
}
void change_by_name()//按名字查询修改 
{
	char c;
	int i,mark=0;
	char name[20];
	printf("\n\t\t请输入要修改的用户姓名："); 
	scanf("%s",name);
	if(n==0)
	{
	   printf("\n\t\t文件中无任何用户");
	   printf("\n\t\t按任意键返回主菜单");
	   getch();
	   mark++;
	   return; 
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(user1[i].name,name)==0)
		{
	    	printf("\n\t\t以下是您要修改的用户信息");
		 	printf("\n\t\t姓名： %s",user1[i].name); 
		 	printf("\n\t\t电话： %s",user1[i].phone_number); 
		 	printf("\n\t\t地址： %s",user1[i].address); 
	     	printf("\n\t\t工作： %s",user1[i].job);
		 	printf("\n\t\t身份证号码： %s",user1[i].identify);
		 	printf("\n\t\t年龄： %d",user1[i].age);
		 	printf("\n\t\t是否修改(y/n)"); 
			if(getch()=='y')
		 	{
 		    	printf("\n\t------------请选择修改信息---------------");
				printf("\n\t         1-修改姓名                   ");
				printf("\n\t         2-修改电话                 "); 
				printf("\n\t         3-修改地址               ");
				printf("\n\t         4-修改工作 ");
				printf("\n\t         5-修改身份证号码");
				printf("\n\t         6-修改年龄"); 
				printf("\n\t-----------------------------------------");
				printf("\n\t请选择您所所要的服务："); 
				scanf("%s",&c);
				switch(c)
				{
			  		case '1': printf("\n\t请输入新姓名： ");
			  		scanf("%s",user1[i].name);break;
			  		case'2':printf("\n\t请输入新电话：   ");
			  		scanf("%s",user1[i].phone_number);break;
			  		case'3':printf("\n\t请输入新地址: ");
			  		scanf("%s",user1[i].address);break;
			  		case'4':printf("\n\t请重新输入工作：");
			  		scanf("%s",user1[i].job);break;
			  		case'5':printf("\n\t请输入新身份证号：");
			  		scanf("%s",user1[i].identify);break;
			  		case'6':printf("\n\t请输入新年龄："); 
			  		scanf("%d",&user1[i].age);break;
  				}
		 	}
		}
	} 	
	if(mark==0)
	{
	   printf("\n\t是否继续修改？(y/n):");
	   if(getch()=='y')
	   {
		change_by_name();
	    return;
	   } 	  
    } 
}
void change_by_phone_number()//按电话号码查询修改 
{
	char c,phone[15];
	int i,mark=0;
	printf("\n\t\t请输入要修改移动用户的号码："); 
	scanf("%s",phone);
	if(n==0)
	{
	    printf("\n\t\t文件中无任何用户");
		printf("\n\t\t按任意键返回主菜单");
		getchar();mark++;
		return; 
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(user1[i].phone_number,phone)==0)
		{
		    printf("\n\t\t以下是您要修改的联系人信息");
			printf("\n\t\t姓名： %s",user1[i].name); 
			printf("\n\t\t电话： %s",user1[i].phone_number); 
			printf("\n\t\t地址： %s",user1[i].address); 
			printf("\n\t\t工作： %s",user1[i].job);
			printf("\n\t\t性别： %s",user1[i].sex);
			printf("\n\t\t身份证号码： %s",user1[i].identify);
			printf("\n\t\t年龄： %d",user1[i].age);
		    printf("\n\t\t是否修改(y/n)"); 
		    if(getch()=='y')
		    {
 		        printf("\n\t------------请选择修改信息---------------");
			    printf("\n\t         1-修改姓名                   ");
			    printf("\n\t         2-修改电话                 "); 
			    printf("\n\t         3-修改地址               ");
			    printf("\n\t         4-修改工作 ");
			    printf("\n\t         5-修改身份证号码");
			    printf("\n\t         6-修改年龄"); 
			    printf("\n\t-----------------------------------------");
			    printf("\n\t请选择您所所要的服务："); 
			    scanf("%s",&c);
			    switch(c)
			    { 
			        case '1': printf("\n\t请输入新姓名： ");
			        scanf("%s",user1[i].name);break;
			        case '2':printf("\n\t请输入新电话：  ");
			        scanf("%s",user1[i].phone_number);break;
			        case '3':printf("\n\t请输入新地址: ");
			        scanf("%s",user1[i].address);break;
			        case '4':printf("\n\t请重新输入工作：");
			        scanf("%s",user1[i].job);break;
			        case '5':printf("\n\t请输入新身份证号：");
			        scanf("%s",user1[i].identify);break;
			        case'6':printf("\n\t请输入新年龄："); 
			        scanf("%d",&user1[i].age);break;
  			    }
		    }
		}
	} 
	if(mark==0)
	{
	  printf("\n\t是否继续修改？(y/n):");
	  if(getch()=='y')
	  {
	  	change_by_phone_number();
      }
	return;
    }
} 
void add_1()//添加移动用户电话号码 
{
	int i,mark=0;
	char c[100];
	const char k[2]={"\t"};
	char s[100];
	if(n==0)     //如果通讯录中没有一个记录输出以下部分
	{ 
		printf("\n\t\t对不起，文件中无任何纪录"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch(); 
		mark++;
		return; 
	}
	system("cls");//清除屏上所有显示 
	printf("\n\t\t请输入你所想要增加电话号码移动用户的姓名："); 
	scanf("%s",c);
	for(i=0;i<n;i++)
	{
		if(strcmp(user1[i].name,c)==0)
		{
			printf("\n\t\t以下是你所想要增加电话号码的移动用户的电话号码：");
			printf("%s",user1[i].phone_number);
			printf("\n\t\t是否添加电话号码？(Y/N)");
			if(getch()=='y') 
			{ 
				printf("\n\t\t请输入你所想要增加的电话号码：");
				scanf("%s",s);
				strcat(user1[i].phone_number,s);
				strcat(user1[i].phone_number,k); 
				printf("\n\t\t添加电话号码成功！");
				printf("\n\t\t是否继续添加电话号码？(y/n)");
				if(getch()=='y')
				{
					add_1();
				} 
			}
			mark++;
		}
	}
	if(mark==0)
	{
	    printf("\n\t没有该移动用户信息");
	    printf("\n\t是否继续修改？(y/n):");
	    if(getch()=='y')
	    {
	    	add_1();
		}  
	    return;
	}
}
void cancel_number()//注销移动用户电话号码 
{
	char a[100];
	char c[100];
	char s[100];
	char b[12];
	int i,j,t,mark=0;
	int num=0;
	int all;
	if(n==0)//如果通讯录中没有一个记录输出以下部分
	{ 
		printf("\n\t\t对不起，文件中无任何纪录"); 
		printf("\n\t\t按任意键返回主菜单"); 
		getch(); 
		mark++;
		return; 
	}
	system("cls");//清除屏上所有显示
	printf("\n\t\t请输入你所想要增加电话号码移动用户的姓名："); 
	scanf("%s",s);
	for(t=0;t<n;t++)
	{
		if(strcmp(user1[t].name,s)==0)
		{
			printf("\n\t\t以下是你所想要增加电话号码的移动用户的电话号码：");
			printf("%s",user1[t].phone_number);
			printf("\n\t\t是否注销电话号码？(y/n)");
			if(getch()=='y') 
			{
				printf("\n\t\t请输入您的电话号码数量：");
				scanf("%d",&all); 
				strcpy(a,user1[t].phone_number);
				printf("\n\t\t请输入您要删除的号码：");
				scanf("%s",b);
				for(i=0;i<all;i++)
				{
					for(j=0;j<11;j++)
					{
						if(b[j]==a[(num*12)+j])
						{
			    			continue;
						}
						else if(b[j]!=a[(num*12)+j])
            			{
                			num++;
                			break;
            			}
					}
					j--;
					if(j==10)
					break;
				}
    			if((all-1)!=num)
				{
					for(i=0;i<(all-num);i++)
					{
						for(j=0;j<12;j++)
						{
							a[num*12+j]=a[(num+1)*12+j];
						}
						num++; 
					}
					for(j=0;j<(all-1)*12;j++)
					{
						c[j]=a[j];
					}
					strcpy(user1[t].phone_number,c);
				}
				else
				{
					for(j=0;j<(all-1)*12;j++)
					{
						c[j]=a[j];
					}
					strcpy(user1[t].phone_number,c);
				} 
				printf("\n\t\t注销电话号码成功！");
				printf("\n\t\t是否继续注销电话号码？(y/n)");
				if(getch()=='y')
				{
					cancel_number();
				} 
			}
			mark++;
		}
	}
	if(mark==0)
	{
	    printf("\n\t没有该移动用户信息");
	    printf("\n\t是否继续修改？(y/n):");
	    if(getch()=='y')
	    {
	    	cancel_number();
		}  
	    return;
	}
} 

void sort_by_identify()//根据身份证号对用户进行排序
{
	 int i,j,*p,*q,s;
	 char temp[2];
	 system("cls");  
     printf("\n\t\t欢迎进入排序模块！\n\n"); 
	 for(i=0;i<n-1;i++)
       {
        for(j=n-1;j>i;j--)//用字符串复制函数，作用是将字符串2复制到字符数组1中去； 
           {
			 	if(strcmp(user1[j-1].identify,user1[j].identify)>0)
            	{//如果前一个字符串学号大于后一个字符穿学号，则把前后信息都交换过来； 
                  	strcpy(temp,user1[j-1].identify);//相当于temp=a;a=b;b=temp;         
                  	strcpy(user1[j-1].identify,user1[j].identify); 
                 	strcpy(user1[j].identify,temp); 
					strcpy(temp,user1[j-1].name);//相当于temp=a;a=b;b=temp;         
                  	strcpy(user1[j-1].name,user1[j].name); 
                 	strcpy(user1[j].name,temp); 
                    strcpy(temp,user1[j-1].phone_number);//相当于temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].phone_number,user1[j].phone_number); 
                    strcpy(user1[j].phone_number,temp); 
                    strcpy(temp,user1[j-1].address);//相当于temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].address,user1[j].address); 
                    strcpy(user1[j].address,temp); 
                    strcpy(temp,user1[j-1].sex);//相当于temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].sex,user1[j].sex); 
                    strcpy(user1[j].sex,temp); 
                    strcpy(temp,user1[j-1].job);//相当于temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].job,user1[j].job); 
                    strcpy(user1[j].job,temp); 
                    p=&user1[j-1].age;
                    q=&user1[j].age;
                    s=*q;
                    *q=*p;
                    *p=s;//用指针交换两个int型变量；                     
                }              
           } 
       }
       printf("\n身份证号   姓名   电话   地址   性别   年龄   工作\n");
       for(i=0;i<n;i++)
	   { 
 	        printf("%s%20s%5s%5s%5s%5d%5s\n",user1[i].identify,user1[i].name,user1[i].phone_number,user1[i].address,user1[i].sex,user1[i].age,user1[i].job); 
     		} 
			printf("\n排序完毕，按任意键继续！\n");  
     		getch();
     		return;
}



 
