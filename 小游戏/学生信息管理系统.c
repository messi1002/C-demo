/*��Ŀ����
һ.	��Ŀ���ݣ�
��д����ʵ�ּ򵥵�ѧ����Ϣ����ϵͳ��
Ҫ��
1.ѧ����Ϣ������ѧ�ţ������ͳɼ�
2.ϵͳ�Բ˵���ʽ�����������ض�ָ���ʵ�ֲ�ͬ����
3.ϵͳӦʵ�����¹��ܣ�
��1��ѧ����Ϣ��ȡ���ܣ�ѧ����Ϣ��txt�ļ����棩 
��2��ѧ����Ϣ�������
��3��ͨ��ѧ�Ż���������ѧ����Ϣ
��4��ѧ����Ϣ��ɾ�����޸ġ�
��. ����˼·��
1.�����ò˵��ĸ�ʽ,д���˵�����ÿ�����ܷ��ű���.������switch����������˵���ϣ�
ʹ��Ŀ�е�Ҫ�����ò�ͬ�ĺ���ʵ�֣� 
2.ѧ����Ϣ��txt�ļ����棬��Ҫ���ļ���֪ʶ����Ҫ��ѧ�ļ��� 
3.*�ر�ע�⣬��������ӵ�ѧ����ѧ�Ž������򣬸�����ô���ַ�����������أ� 
*/

#include <stdio.h>//��������⣻
#include<stdlib.h>//��׼��ͷ�ļ� ����system������������ 
#include<string.h>//�ַ���������ͷ�ļ��� 
#define N 20//���ѧ������ �� 
#define M 10//������ѧ������ַ����� 

struct record//�ýṹ��ͳ����Ϣ�� 
{
     char name[M+1]; //������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
     char stuID[M+1];//ѧ�ţ� 
     int mark;//�ɼ���  
}stu[N];
//����ȫ�ֱ�������������Щ�����е��ã�
//��ȫ����Ҫ���õĺ�������һ�𣬱����Ķ������ܣ� 
     int p=1,m,n;//����ȫ�ֱ�����       
     //��������������һЩ�Զ��幦�ܵĺ����� 
     void menu();//�Բ˵���ʽ������
     void statement(); 
     void read();//��ȡ�ļ��� 
     void seek();//����ѧ����Ϣ�� 
     void add(); //����ѧ����Ϣ��
     void rank(); 
     void modify();//�޸�ѧ����Ϣ�� 
     void delete(); //ɾ��ѧ����Ϣ�� 
     void display();//��ʾȫ����Ϣ��
	 void save(); //����������Ϣ�� 
int main()//�������е��ò˵��� 
{
     while(p)
     menu();//�˵���ʼ������ 
     system("pause");//syetem()���ǵ��ôӳ����е���ϵͳ���
     //��pause�����Ǵӳ����е���"pause"���
     return 0;
}
     
     void statement()            
     {
       printf("1.��ӭ�鿴ϵͳ˵����\n");
       printf("2.�밴�ղ˵����ܼ���˵����.\n");
       printf("3.лл���ʹ�ã�\n");    
     }
     
     void read()
     {
       char *p="student.txt";     
       FILE *fp;//FILE�Ǳ������ͣ������ļ���*fp,ָ��ָ��FILE���͵Ķ��� 
       int i=0;   
       if((fp=fopen("D:\\student.txt","r"))==NULL)
       {
       // fopen������׼�������򿪴����ļ�student.txt�����ڶ����ͷ�ָ�룬ָ��FILE���Ͷ���
       //fscanf:���ڴ��ļ��������ݣ�scanf�����ڴӼ��̶������ݣ�     
       printf("Open file is error!Strike any key to exit!",p);
       //ϵͳû���ҵ��ļ��������밴������������ȴ��û���һ������Ȼ�󷵻أ� 
       system("pause");//ϵͳ��ֹ�� 
       exit(0);
       }
       while (fscanf(fp,"%s%s%d",stu[i].name,stu[i].stuID,&stu[i].mark)==3)
       {
            i++;
       }
       fclose(fp);
       n=i;//¼����n���ˣ�n��ȫ�ֱ�������ȫ�������ã� 
       printf("¼����ϣ�\n");
     } 
     
     void seek()
     {
       int i,item,flag;
       char s1[M+1];
       printf("\n---------------1.��ѧ�Ų�ѯ---------------\n");
       printf("\n---------------2.��������ѯ---------------\n");
       printf("\n---------------3.�˳����˵�---------------\n");
       printf("��ѡ���Ӳ˵���ţ�\n\n");   
       scanf("%d",&item);
       flag=0;
       switch(item)
       {
         case 1:
            printf("������Ҫ��ѯ��ѧ��ѧ��\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
            if(strcmp(stu[i].stuID,s1)==0)
            {
            flag=1;
            printf("ѧ��ѧ��    ѧ������     �ɼ�\n");
            printf("-----------------------------\n\n");
            printf("%s%s%d",stu[i].stuID,stu[i].name,stu[i].mark);
            } 
            if(flag==0) 
            printf("��ѧ�Ų�����\n\n");
          break; 
          case 2:
          printf("������Ҫ��ѯ��ѧ������\n");
          scanf("%s",s1);
          for(i=0;i<n;i++)
             if(strcmp(stu[i].name,s1)==0)
             {
             flag=1;
             printf("ѧ��ѧ��    ѧ������     �ɼ�\n");
             printf("-----------------------------\n\n");
             printf("%s%s%d",stu[i].stuID,stu[i].name,stu[i].mark);
             } 
             if(flag==0) 
             printf("������������\n\n");
          break;
          case 3:return;     
          default:printf("����1-3֮��ѡ��\n\n"); 
       }
     } 
     
     void add()
     {
       int i=n,j,flag;
       printf("\n����������ѧ������\n");
       scanf("%d",&m);
       do
       {
          flag=1;
          while(flag)
             {
                flag=0;
                printf("\n�������%d��ѧ��ѧ�ţ�\n",i+1);
                scanf("%s",&stu[i].stuID);
                for(j=0;j<i;j++)
                   if(strcmp(stu[i]. stuID,stu[j].stuID)==0)
                   {
                      printf("\n���и�ѧ�ţ����������룡\n");
                      flag=1;
                      break;//�����ظ�ֱ�������˲�ѭ���� 
                   }
              } 
         printf("\n�������%d��ѧ����������\n",i+1);
         scanf("%s",stu[i].name);
         printf("\n�������%d��ѧ���ĳɼ���\n",i+1);  
         scanf("%d",&stu[i].mark);             
       if (flag==0)
          {
           i=i;
           i++;        
           }
       }   
       while (i<n+m);
       n=n+m;//ȫ�ֱ���n��ѧ��������m ��ѧ����Ϣ�� 
       printf("¼����ϣ�\n");
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
           for(j=n-1;j>i;j--)//���ַ������ƺ����������ǽ��ַ���2���Ƶ��ַ�����1��ȥ�� 
               if(strcmp(stu[j-1].stuID,stu[j].stuID)>0)
               {//���ǰһ���ַ���ѧ�Ŵ��ں�һ���ַ���ѧ�ţ����ǰ����Ϣ������������ 
                  strcpy(temp,stu[j-1].stuID);//�൱��temp=a;a=b;b=temp;         
                  strcpy(stu[j-1].stuID,stu[j].stuID); 
                  strcpy(stu[j].stuID,temp); 
                  strcpy(temp,stu[j-1].name);           
                  strcpy(stu[j-1].name,stu[j].name); 
                  strcpy(stu[j].name,temp);//mark��������int,�������ַ������齻��������ָ�룻 
                  p=&stu[j-1].mark;
                  q=&stu[j].mark;
                  s=*q;
                  *q=*p;
                  *p=s;//��ָ�뽻������int�ͱ�����                     
               }              
       } 
	   save();     
     }
      
     void modify()
     {
       int i,item,j;
       char s1[M+1],s2[M+1];
       printf("\n������Ҫ�޸ĵ�ѧ��ѧ��\n");
       scanf("%s",s1);//�����޸�ѧ�ţ� 
       for(i=0;i<n;i++)    
       if(strcmp(stu[i].stuID,s1)==0)
       j=i;
       printf("\n-------------------\n");
       printf("\n     1.�޸�����    \n"); 
       printf("\n    2.�޸ĳɼ�     \n");  
       printf("\n    3.�˳����˵�   \n"); 
       printf("\n-------------------\n"); 
       while(1)
       {
           printf("��ѡ���Ӳ˵���ţ�\n");       
           scanf("%d",&item);
           switch(item)
           {
           case 1:
                printf("�������µ�����\n");
                scanf("%s",s2);
                strcpy(stu[j].name,s2);
           break; 
           case 2:
                printf("�������µĳɼ�\n");
                scanf("%d",&stu[j].mark);//���������Σ��������ַ���������ʾ  
           break;
           case 3:
		   return;     
           default:printf("\n����1-3֮��ѡ��\n"); 
           }    
       } 
     }
     
     void delete()
     {
       int i,j,flag=0;
       char s1[N+1];
       printf("\n������Ҫɾ����ѧ��ѧ��\n");
       scanf("%s",s1);
       for(i=0;i<n;i++)    
       if(strcmp(stu[i].stuID,s1)==0)
       //ͻȻ����Ҫ��ѧ�����ַ�����ʽ��ʾ����
       //��Ȼ��ô���ַ����Ƚ��б�����ѧ���Ƿ��ظ����ߴ��ڣ� 
       {
           flag=1;//����÷�����Ҫ��ѧ����ԭ�� 
           for(j=i;j<n-1;j++); 
           stu[j]=stu[j+1];                         
       }   
       if(flag==0)
       printf("\n��ѧ�Ų����ڣ�\n");
       if(flag==1)
       {
           printf("\nɾ���ɹ���");
           n--;//ȫ�ֱ�����ѧ����Ϣ�����٣�       
       } 
     }   
       
     void display()
     {
       read();
       int i;
       printf("\n����ѧ������Ϣ���£�\n");
       printf("\nѧ��       ����     �ɼ�   \n");
       printf("\n-------------------------------\n");
       for(i=0;i<n;i++)//for()��ʾȫ����Ϣ��   
       {
          printf("%s%12s%12d",stu[i].stuID,stu[i].name,stu[i].mark);
          printf("\n\n");
       }    
     }
     
     void menu()
     {
       int num;
       printf("\n\n\n\n                         **********    ѧ������ϵͳ   *********\n");
       printf("                                 --------------------------------------\n");
       printf("\n                               1.-------    ϵͳ˵��������    -------\n"); 
       printf("\n                               2.-------     ����ѧ����Ϣ     -------\n"); 
       printf("\n                               3.-------     ����ѧ����Ϣ     -------\n"); 
       printf("\n                               4.-------     �޸�ѧ����Ϣ     -------\n"); 
       printf("\n                               5.-------     ɾ��ѧ����Ϣ     -------\n"); 
       printf("\n                               6.-------     ��ʾȫ����Ϣ     -------\n");
       printf("\n                               --------------------------------------\n");
       printf("��ѡ���ܱ�ţ�\n");
       scanf("%d",&num);
       switch(num)
       {
             case 1:statement();break;
             case 2:seek();break;
             case 3:add();break;
             case 4:modify();break;
             case 5:delete();break;
             case 6:display();break; 
       default:printf("\n��������0-6֮��ѡ��\n");                    
       } 
     } 


