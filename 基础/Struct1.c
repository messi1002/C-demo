#include <stdio.h>

int main()
{
	// ����ṹ��stu�� 
	struct stu {
		int id; 
		char* name; 
		int age;
	};
	
	// ����ṹ�����arr1�� 
	struct stu wjy;
	
	wjy.id = 1;
	wjy.name = "wjy";
	wjy.age = 19;
	
	printf("%d\n", wjy.id);
	printf("%s\n", wjy.name);
	printf("%d\n", wjy.age);
	
	// ����ṹ��ָ��p�� 
	struct stu* p = &wjy;
	 
	printf("%d\n", p->id);
	printf("%s\n", p->name);
	printf("%d\n", p->age);
	printf("%p\n", p); 
	printf("%p\n", (*p));
	printf("%s\n", (*p).name);
	printf("%d\n", (*p).age);
	
	return 0;	
} 
