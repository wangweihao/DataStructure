// =====================================================================================
//
//       Filename:  avl.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年03月20日 00时22分54秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include "avl.h"

int main()
{
    AvlTree T;
    Insert(6, T);
    Insert(2, T);
    Insert(1, T);
    Insert(4, T);
    Insert(8, T);
    PrintTree(T);
    printf("T->Element:\n", T->Element);
}

