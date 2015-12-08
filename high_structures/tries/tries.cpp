// =====================================================================================
//
//       Filename:  tries.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年03月14日 23时15分43秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================


#include "tries.h"

int main()
{
    tries tree;
    std::string s1("apple");
    std::string s2("big");
    std::string s3("haha");
    std::cout << tree.t_Insert(s1) << std::endl;
    tree.t_Insert(s2);
    tree.t_Insert(s3);
    std::cout << tree.t_search(s1) << std::endl;
    std::cout << tree.t_Delete(s1) << std::endl;
}
