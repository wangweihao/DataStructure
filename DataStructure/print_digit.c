// =====================================================================================
//
//       Filename:  print_digit.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月10日 11时00分16秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include <stdio.h>

void fun(int N)
{
    if(N >= 10)
        fun(N/10);
    printf("%d ", N%10);
}

int main()
{
    int a = 64523;
    fun(a);

    return 0;

}
