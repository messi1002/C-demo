#include <stdio.h>

int main()
{
	// 定义结构体数组。 
	struct stu {
		int id; 
		char* name; 
		int age;
	} we[2];
	
	we[0].id = 1;
	we[0].name = "wjy";
	we[0].age = 19;
	we[1].id = 2;
	we[1].name = "zbw";
	we[1].age = 20;	
	
	printf("%d\n", we[0].id);
	printf("%s\n", we[0].name);
	printf("%d\n", we[0].age);
	printf("%d\n", we[1].id);
	printf("%s\n", we[1].name);
	printf("%d\n", we[1].age);
	
	// 定义结构体数组指针p。 
	struct stu* p = &we;
	int len = sizeof(we) / sizeof(struct stu); 
	int i;
	
	for (i = 0; i < len; i++)
	{
		printf("%d\n", (p+i)->id);
		printf("%s\n", (p+i)->name);
		printf("%d\n", (p+i)->age);
	}
	 
	return 0;	
} 
