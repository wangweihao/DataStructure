// =====================================================================================
//
//       Filename:  prim.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月20日 12时55分47秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include "heap3.h"

enum { infinity = 10000, MaxQueue = 100 };



void Prim(AdjGraph *G)
{
    int i;
    VertexInfo T;
    VertexType start,v;
    ElementType e;
    EdgeNode *p;
    PriorityQueue *H;

    for(i = 1; i <= G->VertexNum; ++i)
    {
        T[i].isinheap = 0;
        T[i].index = i;
        T[i].mark = 0;
        T[i].way_length = infinity;
        T[i].preNode = -1;
    }

    H = Create_heap(MaxQueue);
    printf("---\n");
    
    printf("请输入起点:");
    scanf("%d",&start);
    T[start].way_length = 0;
    Insert(H, &T[start]);
    T[start].isinheap = 1;

    while(isEmpty(H))
    {
        e = DeleteMin(H);
        T[e->index].mark = 1;
        T[e->index].isinheap = 1;
        p = G->adjlist[e->index].firstEdge;

        while(p != NULL)
        {
            //如果不在堆里，入堆
            if(T[p->adjvex].isinheap == 0)
            {
                Insert(H, &T[p->adjvex]);
                T[p->adjvex].isinheap = 1;
            }

            if(!T[p->adjvex].mark)
            {
                if(T[p->adjvex].way_length > p->weight)
                {
                    T[p->adjvex].way_length = p->weight;
                    printf("weight = %d\n", p->weight);
                    T[p->adjvex].preNode = e->index;
                }
            }

            p = p->next;
        }

    }

    printf("\n\n");
    for(i = 1; i <= G->VertexNum; ++i)
    {
        printf("v[%d]| mark:%d  way_length:%d  preNode:%d\n", i, T[i].mark, T[i].way_length, T[i].preNode);
    }

}

int main()
{
    AdjGraph *G;

    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    assert(G != NULL);
    Create_graph(G);
    Print_graph(G);
    Prim(G);

    return 0;
}
