// =====================================================================================
//
//       Filename:  Queue.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月19日 20时32分54秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include <stdio.h>
#include <malloc.h>

struct queue_s;
typedef struct queue_s queue_t;
struct queue_s
{
    queue_t *next;
    queue_t *prev;
};

#define in_queue(h,x)            \
    (x)->next = (h);             \
    (x)->prev = (h)->prev->next; \
    (h)->prev->next = (x);       \
    (h)->prev = (x)

#define out_queue(h)             \
    (h)->next->next->prev = (h); \
    (h)->next = (h)->next->next

#define init_queue(h)            \
    h->next = NULL;              \
    h->prev = NULL  

#define empty_queue(h) h->next == NULL ? 1 : 0
    
