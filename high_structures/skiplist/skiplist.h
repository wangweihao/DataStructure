// =====================================================================================
//
//       Filename:  skiplist.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年03月18日 21时40分45秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include <iostream>

struct SkipNode
{
    int element;
    struct SkipNode *right;
    struct SkipNode *down;
};

class SkipList
{
    
};

#endif
