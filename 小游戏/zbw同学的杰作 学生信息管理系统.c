#include <stdio.h>//ͷ�ļ�
#include <stdlib.h>//������õ�ϵͳ����
#include <string.h>//�����ַ�����ĺ��������ͷ�ļ� 
#include <conio.h>
//����ṹ�� 
struct USER//�����ƶ��û��ṹ�����
{ 
	char name[20];    //�����������ֵ�����
	char phone_number[100]; //��������绰���������
	char address[60]; //���������ַ������
	char sex[5];
	int age;
	char job[40];
	char identify[20];
} user1[100]; //Ĭ����100������ 
int n=0;//��¼�ƶ��û�����  
FILE *fp;//�����ļ� 
//�����õ������к���  
void main_order();//���˵�
void increase_person();//�����û�����
void readfile();//�ļ����뺯��
void writefile();//�ļ�д�뺯��
void change_information();//�޸���ϵ�˺���
void change_name();//�����޸�
void change_by_name();//�����������޸�
void change_by_phone_number();//���绰��������޸� 
void change_phone_number();//�绰�����޸�
void find();//������ϵ�˺���
void find_name();//����������
void find_phone_number();//���绰�������
void delete_p();//ɾ����ϵ�˺���
void delete_all();//ȫ��ɾ��
void delete_single();//����ɾ��
void cancel_number();//ɾ���û���ĳһ������ 
void add_1();//�����û���ĳһ������ 
void show_all();//�û���Ϣ��ʾ
void sort_by_identify();//�������֤�Ŷ��û��������� 
int main()//������main
{
    readfile();    //�����ļ�
	while(1)//ѭ������Զ���У� 
	{	
		main_order();//�������˵�����
	}
} 
void readfile()//��ȡ�ļ� 
{
	if((fp=fopen("C:\\�ƶ��û���Ϣ.txt","r"))==NULL)  //��ֻ����ʽ���ж��ļ��Ƿ�Ϊ��
	{ 
		printf("\n\t\t\t    �ƶ��û���Ϣ�ļ�������");    //�жϽ���
		if((fp=fopen("�ƶ��û���Ϣ.txt","w"))==NULL) //ֻд��ʽ�ж�
		{ 
			printf("\n\t\t����ʧ��");      //Ϊ�ս���
			exit(0);                        //�˳�
		}                                  
		else                               //��Ϊ����ִ��else
		{ 
		    printf("\n\t-----------------��ӭʹ���ƶ��û�����ϵͳ------------------");
		    printf("\n\t                    �û��ļ��ѽ���                         "); 
		    printf("\n\t                   ��������������˵�                      "); 
		    printf("\n\t-----------------------------------------------------------");
		    getch(); 
		    return;
		}
		exit(0); 
	} 
	fseek(fp,0,2); //�ļ�λ��ָ���ƶ����ļ�ĩβ 
	if(ftell(fp)>0) //�ļ���Ϊ�� 
	{ 
		rewind(fp); //�ļ�λ��ָ���ƶ����ļ���ʼλ��
		for (n=0;!feof(fp) && fread(&user1[n],sizeof(struct USER),1,fp);n++);
		{
			printf("\n\t-----------------��ӭʹ���ƶ��û�����ϵͳ----------------");
		    printf("\n\t                   �ļ�����ɹ�!                          "); 
		    printf("\n\t                 ��������������˵�                      "); 
		    printf("\n\t---------------------------------------------------------");
			getch();
			return;
		}
	}
	printf("\n\t-----------------��ӭʹ���ƶ��û�����ϵͳ----------------");
	printf("\n\t                     �ļ�����ɹ�!                        "); 
	printf("\n\t            �ƶ��û���Ϣ�ļ������κμ�¼                 "); 
	printf("\n\t                  ��������������˵�                     "); 
	printf("\n\t---------------------------------------------------------");
	getch();
	return;  
}
void main_order()//�ļ����˵� 
{
	char c; 
	system("cls"); 
	printf("\n\t\t|---------------��ӭ��ʹ���ƶ��û�����ϵͳ-------------|"); 
	printf("\n\t\t|                     1-������û�                     |"); 
	printf("\n\t\t|                     2-��ѯ����ʾ�û���Ϣ             |");
	printf("\n\t\t|                     3-ɾ���û�                       |"); 
	printf("\n\t\t|                     4-�޸��û���Ϣ                   |");
	printf("\n\t\t|                     5-ע���û��ֻ�����               |");
	printf("\n\t\t|                     6-�����û��ֻ�����               |");
	printf("\n\t\t|                     7-�����˳�                       |"); 
	printf("\n\t\t|                     8-�������֤��������û�����     |"); 
	printf("\n\t\t|                     0-�������˳�                     |"); 
	printf("\n\t\t|------------------------------------------------------|"); 
	printf("\n\t\t��ѡ��������Ҫ�ķ���"); 
	c=getch(); 
	switch (c) /*�����ϱߵ�ѡ����Ŀ*/
	{ 
	    case '1':increase_person();break;//�����û� 
	    case '2':find();break; //�����û� 
	    case '3':delete_p();break;//ɾ���û� 
	    case '4':change_information();break;//�޸��û���Ϣ 
	    case '5':cancel_number();break;//ע���û��ֻ��� 
	    case '6':add_1();break;//�����û��ֻ��� 
		case '7':writefile();break; //�����˳� 
		case '8':sort_by_identify();break; 
		case '0':exit(0); //�������˳� 
		default:main_order(); /*��û���򷵻����˵��ȴ�����*/
	} 
}
void increase_person()//����ƶ��û� 
{
	char k[2]={"\t"};
	printf("\n\t\t------------------ �������ƶ��û���Ϣ --------------------\n"); 
	printf("\n\t\t�����û�����:"); 
	scanf("%s",user1[n].name);    //��������
	printf("\n\t\t�����û��绰����:"); 
	scanf("%s",user1[n].phone_number); 
	printf("\n\t\t�����û���ͥסַ:"); 
	scanf("%s",user1[n].address); 
	printf("\n\t\t�����û��Ա�");
	scanf("%s",user1[n].sex);
	printf("\n\t\t�����û����䣺");
	scanf("%d",&user1[n].age);
	printf("\n\t\t�����û�������");
	scanf("%s",user1[n].job); 
	printf ("\n\t\t�����û����֤�ţ�");
	scanf("%s",user1[n].identify);
	strcat(user1[n].phone_number,k);
	//strcpy(user1[n].phone_number,k);
	n++;                          //ͳ�Ƹ���
	printf("\n\t\t�Ƿ��������û�?(y/n):"); //�Ƿ����������û�
	if(getch()=='y')
	{
		increase_person();
	} 
} 
void writefile()//д���ƶ��û���Ϣ�ļ� 
{
	int i; 
	if((fp=fopen("C:\\�ƶ��û���Ϣ.txt","w"))==NULL) 
	{ 
		printf("\n\t\t�ļ���ʧ��"); 
	} 
	for(i=0;i<n;i++) 
	{ 
		if(fwrite(&user1[i],sizeof(struct USER),1,fp)!=1)//�ж��Ƿ�д���ļ��ɹ� 
		{ 
			printf("\n\t\tд���ļ�����!\n"); 
		} 
	}
	fclose(fp); //�ر��ļ�
	printf("\n\t------------------------------------------------------"); //�����ʾ��Ϣ
	printf("\n\t\t�ƶ��û���Ϣ�ļ��ѱ���"); 
	printf("\n\t\t��ӭ�ٴ�ʹ�ã�лл!\n");
	printf("\n\t\t��������˳�����\n\t\t"); 
	printf("\n\t------------------------------------------------------");//������ 
	exit(0);
} 
void find()//��ѯ�ƶ��û� 
{
	char c; 
	system("cls"); //�����Ļ�ϵ�������ʾ 
	printf("\n\t\t------------------- ��ʾ�Ͳ�ѯ�ƶ��û� ------------------"); 
	printf("\n\t\t|                    1-�����ʾ����                   |");
	printf("\n\t\t|                    2-��������ѯ                     |"); 
	printf("\n\t\t|                    3-���绰��ѯ                     |"); 
	printf("\n\t\t|                    4-�������˵�                     |");
	printf("\n\t\t|------------------------------------------------------"); 
	printf("\n\t\t��ѡ������Ҫ�ķ���"); 
	c=getch(); 
	switch (c) 
	{ 
		case '1':show_all();break;   /*��ʾ���к���*/ 
		case '2':find_name();break;  /*���ð�������ѯ����*/
		case '3':find_phone_number();break;  /*���ð������ѯ����*/
		case '4':main_order();break;       /*���˵�*/
	} 
}
void show_all()//��ʾ�����ƶ��û� 
{
	int i; 
	system("cls");//�����Ļ�ϵ�������ʾ 
	if(n!=0) 
	{ 
		printf("\n\t\t----------��ӭ����ѯ�����ƶ��û���Ϣ-------------"); 
		for (i=0;i<n;i++)     /*��������ʾ*/
		{ 
			printf("\n\t\t������ %s",user1[i].name); 
			printf("\n\t\t�绰�� %s",user1[i].phone_number); 
			printf("\n\t\t��ַ�� %s",user1[i].address); 
			printf("\n\t\t������ %s",user1[i].job);
			printf("\n\t\t�Ա� %s",user1[i].sex);
			printf("\n\t\t���֤���룺 %s",user1[i].identify);
			printf("\n\t\t���䣺 %d",user1[i].age);
			printf("\n\t\t--------------------------------------------------"); 
			if(i+1<n) 
			{ 
				printf("\n\t\t-----------------------"); 
				system("pause");//���ش�����Ϣ 
			} 
		} 
		printf("\n\t\t---------------------------------------------"); 
	} 
	else//���ƶ��û�
	printf("\n\t\t�ƶ��û���Ϣ�����κμ�¼"); 
	printf("\n\t\t��������������˵���"); 
	getch();  
}
void find_phone_number() //�������ѯ 
{
	int mark=0; 
	int i; 
	char phone[15]; 
	printf("\n\t\t------------------- ���绰���� -------------------------");
	printf("\n\t\t������绰����:"); 
	scanf("%s",phone); 
	for(i=0;i<n;i++) 
	{ 
		if(strcmp(user1[i].phone_number,phone)==0)//�ԱȲ��Һ��� 
		{ 
			printf("\n\t\t------------ �����������ҵ��ƶ��û���Ϣ ------------"); 
			printf("\n\t\t ������%s",user1[i].name); 
			printf("\n\t\t �绰��%s",user1[i].phone_number); 
			printf("\n\t\t ��ַ��%s",user1[i].address); 
			printf("\n\t\t ������%s",user1[i].job);
			printf("\n\t\t �Ա�%s",user1[i].sex);
			printf("\n\t\t ���֤���룺%s",user1[i].identify);
			printf("\n\t\t ���䣺%d",user1[i].age);
			printf("\n\t\t------------------------------------------------"); 
			printf("\n\t\t��������������˵���"); 
			mark++; 
			getch();
		} 
	} 
	if(mark==0) 
	{ 
		printf("\n\t\tû���ҵ��ƶ��û�����Ϣ"); 
		printf("\n\t\t��������������˵�"); 
		getch();  
	} 
}

void find_name()//��������ѯ 
{
	int mark=0; 
	int i; 
	char name[20];
    printf("\n\t\t----------------���������� --------------------");
	printf("\n\t\t��������Ҫ���ҵ�����:"); 
	scanf("%s",name); 
	for(i=0;i<n;i++) 
	{ 
		if(strcmp(user1[i].name,name)==0) 
		{ 
			printf("\n\t\t------------ �����������ҵ��ƶ��û���Ϣ ---------------"); 
		    printf("\n\t\t ������%s",user1[i].name); 
			printf("\n\t\t �绰��%s",user1[i].phone_number); 
			printf("\n\t\t ��ַ��%s",user1[i].address); 
			printf("\n\t\t ������%s",user1[i].job);
			printf("\n\t\t �Ա�%s",user1[i].sex);
			printf("\n\t\t ���֤���룺%s",user1[i].identify);
			printf("\n\t\t ���䣺%d",user1[i].age);
			printf("\n\t\t---------------------------------------------------"); 
			mark++;
			getch();
		} 
	}
	if(mark==0) 
	{ 
		printf("\n\t\tû���ҵ��ƶ��û�����Ϣ"); 
		printf("\n\t\t��������������˵�"); 
		getch();  
	}
}
void delete_p()//ɾ���ƶ��û���Ϣ 
{
	char c; 
	if(n==0)     //����ƶ��û���Ϣ��û��һ����¼������²���
	{ 
		printf("\n\t\t�Բ����ļ������κμ�¼"); 
		printf("\n\t\t��������������˵�"); 
		getch();  
	} 
	system("cls");      //�����Ļ�����е���ʾ 
	printf("\n\t\t------------  ɾ���˵� ----------------"); 
	printf("\n\t\t|           1-ɾ������                 |");
	printf("\n\t\t|           2-ɾ������                 |"); 
	printf("\n\t\t|           3-�������˵�               |"); 
	printf("\n\t\t|--------------------------------------"); 
	printf("\n\t\t��ѡ��������Ҫ�ķ���"); 
	c=getch();     //����ĸ���choice
	switch(c)     
	{ 
		case '1':delete_all();break; 
		case '2':delete_single();break; 
		case '3':main_order();break; 
		default:main_order();break; 
	} 
}
void delete_all()//ɾ�������ƶ��û� 
{
	printf("\n\t\tȷ��ɾ��?(y/n)"); 
	if(getch()=='y') 
	{ 
		fclose(fp); 
		if((fp=fopen("�ƶ��û���Ϣ.txt","w"))==NULL)   //�ļ������
		{ 
			printf("\n\t\t���ܴ��ļ���ɾ��ʧ��"); 
			readfile(); 
		} 
		n=0; 
		printf("\n\t\t��¼��ɾ������������������˵�"); 
		getch();  
	} 
	else 
	return; 
} 
void delete_by_name()//������ɾ���ƶ��û� 
{
	int i,m,mark=0,a=0; 
	char name[20]; 
	printf("\n\t\t������Ҫɾ���ƶ��û�����:"); 
	scanf("%s",name);    //������������
	for(i=a;i<n;i++) 
	{ 
		if(strcmp(user1[i].name,name)==0) //�Ա��ַ������ҵ�Ҫɾ�����ƶ��û� 
		{ 
			printf("\n\t\t��������Ҫɾ�����ƶ��û���¼��"); 
			printf("\n\t\t--------------------------------"); 
			printf("\n\t\t������ %s",user1[i].name); 
			printf("\n\t\t�绰�� %s",user1[i].phone_number); 
			printf("\n\t\t��ַ�� %s",user1[i].address); 
			printf("\n\t\t������ %s",user1[i].job);
			printf("\n\t\t�Ա� %s",user1[i].sex);
			printf("\n\t\t���֤���룺 %s",user1[i].identify);
			printf("\n\t\t���䣺 %d",user1[i].age);
			printf("\n\t\t--------------------------------"); 
			printf("\n\t\t�Ƿ�ɾ��?(y/n)");  
			if(getch()=='y') // ʵ��ɾ������  
			{ 
				for(m=i;m<n-i-1;m++)
				{
					user1[m]=user1[m+1];    //���ƶ��û���Ϣ����ǰ��
					//n--;
				}
				n--;
				mark++; 
				printf("\n\t\tɾ���ɹ�"); 
				printf("\n\t\t�Ƿ����ɾ��?(y/n)");  
				if(getch()=='y')
				{
					delete_by_name();   //��������ɾ������
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
		printf("\n\t\tû�и��ƶ��û��ļ�¼"); 
		printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
		if(getch()=='y')
		{
			delete_by_name();
		} 
		return; 
	} 
}
void delete_by_phone_number()//���绰����ɾ����ϵ�� 
{
	int i,m,mark=0;    //��������
	char phone[20]; 
	printf("\n\t\t������Ҫɾ���ƶ��û��绰���룺"); 
	scanf("%s",phone); 
	if(n==0) 
	{ 
		printf("\n\t\t�Բ����ļ������κμ�¼"); 
		printf("\n\t\t��������������˵�"); 
		getch(); 
		return; 
	} 
	for(i=0;i<n;i++) 
	{ 
		if(strcmp(user1[i].phone_number,phone)==0) 
		{ 
			printf("\n\t\t��������Ҫɾ�����ƶ��û���¼��"); 
			printf("\n\t\t������ %s",user1[i].name); 
			printf("\n\t\t�绰�� %s",user1[i].phone_number); 
			printf("\n\t\t��ַ�� %s",user1[i].address); 
			printf("\n\t\t������ %s",user1[i].job);
			printf("\n\t\t�Ա� %s",user1[i].sex);
			printf("\n\t\t���֤���룺 %s",user1[i].identify);
			printf("\n\t\t���䣺 %d",user1[i].age);
			printf("\n\t\t�Ƿ�ɾ��?(y/n)");
			if(getch()=='y') 
			{ 
				for(m=i;m<n-i-1;m++) //�����滻ʵ��ɾ�� 
				{
					user1[m]=user1[m+1]; 
					//n--;
				}	
				n--;
				mark++; //��¼ɾ������ 
				printf("\n\t\tɾ���ɹ�"); 
				printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
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
		printf("\n\t\tû�и��ƶ��û��ļ�¼"); 
		printf("\n\t\t�Ƿ����ɾ��?(y/n)");
		if(getch()=='y')  
		return ; 
	} 
}
void delete_single()//ɾ�������û�  
{
	char c; 
	printf("\n\t----------------------------------------------------------"); 
	printf("\n\t\t   1-������ɾ��    2-���绰ɾ��"); 
	printf("\n\t\t��ѡ��������Ҫ�ķ���"); 
	printf("\n\t----------------------------------------------------------");
	c=getch();  
	switch (c) 
	{  
		case '1':delete_by_name();break;
		case '2':delete_by_phone_number();break;
	} 
}
void change_information()//�޸��ƶ��û���Ϣ
{ 
    char c;
    if(n==0)
    {
    	printf("\n\t\t�Բ����ļ������κμ�¼"); 
		printf("\n\t\t��������������˵�"); 
		getch(); 
		return; 	
    }
    system("cls"); 
	printf("\n\t\t-----------------�޸��ƶ��û��˵�-----------------------");
	printf("\n\t\t|               1-�������޸�                           |");
	printf("\n\t\t|               2-���绰�޸�                           |"); 
	printf("\n\t\t|                �����-���������˵�                   |");
	printf("\n\t\t------------------------------------------------------");
 	c=getch(); 
	switch(c) 
	{ 
		case '1':change_by_name();break; 
		case '2':change_by_phone_number();break; 
		default:main_order();break;
	} 
}
void change_by_name()//�����ֲ�ѯ�޸� 
{
	char c;
	int i,mark=0;
	char name[20];
	printf("\n\t\t������Ҫ�޸ĵ��û�������"); 
	scanf("%s",name);
	if(n==0)
	{
	   printf("\n\t\t�ļ������κ��û�");
	   printf("\n\t\t��������������˵�");
	   getch();
	   mark++;
	   return; 
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(user1[i].name,name)==0)
		{
	    	printf("\n\t\t��������Ҫ�޸ĵ��û���Ϣ");
		 	printf("\n\t\t������ %s",user1[i].name); 
		 	printf("\n\t\t�绰�� %s",user1[i].phone_number); 
		 	printf("\n\t\t��ַ�� %s",user1[i].address); 
	     	printf("\n\t\t������ %s",user1[i].job);
		 	printf("\n\t\t���֤���룺 %s",user1[i].identify);
		 	printf("\n\t\t���䣺 %d",user1[i].age);
		 	printf("\n\t\t�Ƿ��޸�(y/n)"); 
			if(getch()=='y')
		 	{
 		    	printf("\n\t------------��ѡ���޸���Ϣ---------------");
				printf("\n\t         1-�޸�����                   ");
				printf("\n\t         2-�޸ĵ绰                 "); 
				printf("\n\t         3-�޸ĵ�ַ               ");
				printf("\n\t         4-�޸Ĺ��� ");
				printf("\n\t         5-�޸����֤����");
				printf("\n\t         6-�޸�����"); 
				printf("\n\t-----------------------------------------");
				printf("\n\t��ѡ��������Ҫ�ķ���"); 
				scanf("%s",&c);
				switch(c)
				{
			  		case '1': printf("\n\t�������������� ");
			  		scanf("%s",user1[i].name);break;
			  		case'2':printf("\n\t�������µ绰��   ");
			  		scanf("%s",user1[i].phone_number);break;
			  		case'3':printf("\n\t�������µ�ַ: ");
			  		scanf("%s",user1[i].address);break;
			  		case'4':printf("\n\t���������빤����");
			  		scanf("%s",user1[i].job);break;
			  		case'5':printf("\n\t�����������֤�ţ�");
			  		scanf("%s",user1[i].identify);break;
			  		case'6':printf("\n\t�����������䣺"); 
			  		scanf("%d",&user1[i].age);break;
  				}
		 	}
		}
	} 	
	if(mark==0)
	{
	   printf("\n\t�Ƿ�����޸ģ�(y/n):");
	   if(getch()=='y')
	   {
		change_by_name();
	    return;
	   } 	  
    } 
}
void change_by_phone_number()//���绰�����ѯ�޸� 
{
	char c,phone[15];
	int i,mark=0;
	printf("\n\t\t������Ҫ�޸��ƶ��û��ĺ��룺"); 
	scanf("%s",phone);
	if(n==0)
	{
	    printf("\n\t\t�ļ������κ��û�");
		printf("\n\t\t��������������˵�");
		getchar();mark++;
		return; 
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(user1[i].phone_number,phone)==0)
		{
		    printf("\n\t\t��������Ҫ�޸ĵ���ϵ����Ϣ");
			printf("\n\t\t������ %s",user1[i].name); 
			printf("\n\t\t�绰�� %s",user1[i].phone_number); 
			printf("\n\t\t��ַ�� %s",user1[i].address); 
			printf("\n\t\t������ %s",user1[i].job);
			printf("\n\t\t�Ա� %s",user1[i].sex);
			printf("\n\t\t���֤���룺 %s",user1[i].identify);
			printf("\n\t\t���䣺 %d",user1[i].age);
		    printf("\n\t\t�Ƿ��޸�(y/n)"); 
		    if(getch()=='y')
		    {
 		        printf("\n\t------------��ѡ���޸���Ϣ---------------");
			    printf("\n\t         1-�޸�����                   ");
			    printf("\n\t         2-�޸ĵ绰                 "); 
			    printf("\n\t         3-�޸ĵ�ַ               ");
			    printf("\n\t         4-�޸Ĺ��� ");
			    printf("\n\t         5-�޸����֤����");
			    printf("\n\t         6-�޸�����"); 
			    printf("\n\t-----------------------------------------");
			    printf("\n\t��ѡ��������Ҫ�ķ���"); 
			    scanf("%s",&c);
			    switch(c)
			    { 
			        case '1': printf("\n\t�������������� ");
			        scanf("%s",user1[i].name);break;
			        case '2':printf("\n\t�������µ绰��  ");
			        scanf("%s",user1[i].phone_number);break;
			        case '3':printf("\n\t�������µ�ַ: ");
			        scanf("%s",user1[i].address);break;
			        case '4':printf("\n\t���������빤����");
			        scanf("%s",user1[i].job);break;
			        case '5':printf("\n\t�����������֤�ţ�");
			        scanf("%s",user1[i].identify);break;
			        case'6':printf("\n\t�����������䣺"); 
			        scanf("%d",&user1[i].age);break;
  			    }
		    }
		}
	} 
	if(mark==0)
	{
	  printf("\n\t�Ƿ�����޸ģ�(y/n):");
	  if(getch()=='y')
	  {
	  	change_by_phone_number();
      }
	return;
    }
} 
void add_1()//����ƶ��û��绰���� 
{
	int i,mark=0;
	char c[100];
	const char k[2]={"\t"};
	char s[100];
	if(n==0)     //���ͨѶ¼��û��һ����¼������²���
	{ 
		printf("\n\t\t�Բ����ļ������κμ�¼"); 
		printf("\n\t\t��������������˵�"); 
		getch(); 
		mark++;
		return; 
	}
	system("cls");//�������������ʾ 
	printf("\n\t\t������������Ҫ���ӵ绰�����ƶ��û���������"); 
	scanf("%s",c);
	for(i=0;i<n;i++)
	{
		if(strcmp(user1[i].name,c)==0)
		{
			printf("\n\t\t������������Ҫ���ӵ绰������ƶ��û��ĵ绰���룺");
			printf("%s",user1[i].phone_number);
			printf("\n\t\t�Ƿ���ӵ绰���룿(Y/N)");
			if(getch()=='y') 
			{ 
				printf("\n\t\t������������Ҫ���ӵĵ绰���룺");
				scanf("%s",s);
				strcat(user1[i].phone_number,s);
				strcat(user1[i].phone_number,k); 
				printf("\n\t\t��ӵ绰����ɹ���");
				printf("\n\t\t�Ƿ������ӵ绰���룿(y/n)");
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
	    printf("\n\tû�и��ƶ��û���Ϣ");
	    printf("\n\t�Ƿ�����޸ģ�(y/n):");
	    if(getch()=='y')
	    {
	    	add_1();
		}  
	    return;
	}
}
void cancel_number()//ע���ƶ��û��绰���� 
{
	char a[100];
	char c[100];
	char s[100];
	char b[12];
	int i,j,t,mark=0;
	int num=0;
	int all;
	if(n==0)//���ͨѶ¼��û��һ����¼������²���
	{ 
		printf("\n\t\t�Բ����ļ������κμ�¼"); 
		printf("\n\t\t��������������˵�"); 
		getch(); 
		mark++;
		return; 
	}
	system("cls");//�������������ʾ
	printf("\n\t\t������������Ҫ���ӵ绰�����ƶ��û���������"); 
	scanf("%s",s);
	for(t=0;t<n;t++)
	{
		if(strcmp(user1[t].name,s)==0)
		{
			printf("\n\t\t������������Ҫ���ӵ绰������ƶ��û��ĵ绰���룺");
			printf("%s",user1[t].phone_number);
			printf("\n\t\t�Ƿ�ע���绰���룿(y/n)");
			if(getch()=='y') 
			{
				printf("\n\t\t���������ĵ绰����������");
				scanf("%d",&all); 
				strcpy(a,user1[t].phone_number);
				printf("\n\t\t��������Ҫɾ���ĺ��룺");
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
				printf("\n\t\tע���绰����ɹ���");
				printf("\n\t\t�Ƿ����ע���绰���룿(y/n)");
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
	    printf("\n\tû�и��ƶ��û���Ϣ");
	    printf("\n\t�Ƿ�����޸ģ�(y/n):");
	    if(getch()=='y')
	    {
	    	cancel_number();
		}  
	    return;
	}
} 

void sort_by_identify()//�������֤�Ŷ��û���������
{
	 int i,j,*p,*q,s;
	 char temp[2];
	 system("cls");  
     printf("\n\t\t��ӭ��������ģ�飡\n\n"); 
	 for(i=0;i<n-1;i++)
       {
        for(j=n-1;j>i;j--)//���ַ������ƺ����������ǽ��ַ���2���Ƶ��ַ�����1��ȥ�� 
           {
			 	if(strcmp(user1[j-1].identify,user1[j].identify)>0)
            	{//���ǰһ���ַ���ѧ�Ŵ��ں�һ���ַ���ѧ�ţ����ǰ����Ϣ������������ 
                  	strcpy(temp,user1[j-1].identify);//�൱��temp=a;a=b;b=temp;         
                  	strcpy(user1[j-1].identify,user1[j].identify); 
                 	strcpy(user1[j].identify,temp); 
					strcpy(temp,user1[j-1].name);//�൱��temp=a;a=b;b=temp;         
                  	strcpy(user1[j-1].name,user1[j].name); 
                 	strcpy(user1[j].name,temp); 
                    strcpy(temp,user1[j-1].phone_number);//�൱��temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].phone_number,user1[j].phone_number); 
                    strcpy(user1[j].phone_number,temp); 
                    strcpy(temp,user1[j-1].address);//�൱��temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].address,user1[j].address); 
                    strcpy(user1[j].address,temp); 
                    strcpy(temp,user1[j-1].sex);//�൱��temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].sex,user1[j].sex); 
                    strcpy(user1[j].sex,temp); 
                    strcpy(temp,user1[j-1].job);//�൱��temp=a;a=b;b=temp;         
                    strcpy(user1[j-1].job,user1[j].job); 
                    strcpy(user1[j].job,temp); 
                    p=&user1[j-1].age;
                    q=&user1[j].age;
                    s=*q;
                    *q=*p;
                    *p=s;//��ָ�뽻������int�ͱ�����                     
                }              
           } 
       }
       printf("\n���֤��   ����   �绰   ��ַ   �Ա�   ����   ����\n");
       for(i=0;i<n;i++)
	   { 
 	        printf("%s%20s%5s%5s%5s%5d%5s\n",user1[i].identify,user1[i].name,user1[i].phone_number,user1[i].address,user1[i].sex,user1[i].age,user1[i].job); 
     		} 
			printf("\n������ϣ��������������\n");  
     		getch();
     		return;
}



 
