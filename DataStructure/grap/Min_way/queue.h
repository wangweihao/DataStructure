// =====================================================================================
//
//       Filename:  queue.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月20日 10时05分34秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct queue_s;
typedef struct queue_s queue_t;
struct queue_s
{
    int x;
    queue_t *next;
};

queue_t* create_queue(void);
void init_queue(queue_t *h);
void in_queue(queue_t *h, int element);
int out_queue(queue_t *h);
int empty_queue(queue_t *h);

queue_t* create_queue(void)
{
    queue_t *h;
    h = (queue_t*)malloc(sizeof(queue_t));
    if(h == NULL)
    {
        printf("h error\n");
        exit(-1);
    }

    return h;
}

void init_queue(queue_t *h)
{
    h->x = -1;
    h->next = NULL;
}

void in_queue(queue_t *h, int element)
{
    queue_t *temp;
    queue_t *p;

    temp = (queue_t*)malloc(sizeof(queue_t));
    temp->next = NULL;
    if(temp == NULL)
    {
        printf("temp error\n");
        exit(-1);
    }
    temp->x = element;
    //printf("%d入队\n", element);
    for(p = h; p->next != NULL; p = p->next);
    p->next = temp;
}

int out_queue(queue_t *h)
{
    queue_t *p;
    int temp;

    printf("出队%d\n", h->next->x);
    temp = h->next->x;
    p = h->next;
    h->next = p->next;
    free(p);

    return temp;
}

int empty_queue(queue_t* h)
{
    if(h->next == NULL)
    {
        //printf("队列为空\n");
        return 0;
    }
    else
    {
        //printf("队列非空\n");
        return 1;
    }
}
