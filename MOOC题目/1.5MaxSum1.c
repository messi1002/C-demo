/*
1-5 最大子列和问题 （20 分）

“最大子列和”则被定义为所有连续子列元素的和中最大者。
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
现要求你编写程序，计算给定整数序列的最大子列和。

输入格式:
输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

输出格式:
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:
6
-2 11 -4 13 -5 -2

输出样例:
20
*/

#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int a[n];
  int length = sizeof(a) / sizeof(a[0]);
  int i, j;
  int maxSum = 0;
	
  // 读入数据。 	  
  for (i = 0; i < length; i++)
  {
    scanf("%d", &a[i]);
  }
  
  // 最基础的两层循环,按照正常逻辑,会计算所有可能的子列和(重复的工作)。 
  for (i = 0; i < length; i++)
  {
  	int thisSum = 0;
    
    for (j = i; j < length; j++)
    {
      thisSum = thisSum + a[j]; 

	  // maxSum的作用很重要,它起了一个暂时保存的功能,暂时保存了已算子列和的最大值。 
      if (maxSum < thisSum)
      {
        maxSum = thisSum;
      }
    }
  }

  printf("%d\n", maxSum);
  
  return 0;
}
