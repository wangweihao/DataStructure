// =====================================================================================
//
//       Filename:  heap.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月18日 17时57分09秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include "heap.h"

int main()
{
    PriorityQueue *H;
    int i = 0;

    H = Create_heap(100);
    Insert(H, 10);
    Insert(H, 3);
    Insert(H, 2);
    Insert(H, 7);
    Insert(H, 4);
    for(i = 1; i < 6; ++i)
        printf("%d\n", H->element[i]);
    DeleteMin(H);
    for(i = 1; i < 5; ++i)
        printf("%d\n", H->element[i]);
    DeleteMin(H);
    for(i = 1; i < 4; ++i)
        printf("%d\n", H->element[i]);
    DeleteMin(H);
    DeleteMin(H);
    DeleteMin(H);
    printf("1,%d2,%d\n", H->element[1], H->element[2]);
    printf("H->size%d\n",H->Size);
    return 0;
}
