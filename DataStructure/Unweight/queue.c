// =====================================================================================
//
//       Filename:  queue.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月20日 10时30分50秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include "queue.h"

int main(int argc, char *argv[])
{
    queue_t *h;
    int i;

    h = create_queue();
    init_queue(h);
    empty_queue(h);
    for(i = 0; i < 10; i++)
    {
        in_queue(h, i);
    }
    for(i = 0; i < 10; i++)
    {
        out_queue(h);
    }

    return 0;
}
