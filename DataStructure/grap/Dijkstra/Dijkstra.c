// =====================================================================================
//
//       Filename:  Dijkstra.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月18日 16时45分39秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

/*
 * Dijkstra算法
 * 借助于堆实现
 */

#include "heap2.h"

enum { infinity = 10000, MaxQueue = 100 };

/*
typedef struct VertexInfo
{
    int index;
    int mark;
    int way_length;
    int preNode;
}VertexInfo[verMax];
*/

void Print_Dijkstra(VertexType v, VertexInfo T)
{
    printf("Print_Dijkstra\n");
    if(T[v].preNode != -1)
    {
        //printf("执行递归\n");
        Print_Dijkstra(T[v].preNode, T);
        printf(" to ");
    }
    printf("%d", v);
}

void Dijkstra(AdjGraph *G)
{
    int i;
    VertexType v, w;
    VertexInfo T;
    PriorityQueue *H;
    ElementType e;
    EdgeNode *p;
    int final;

    //初始化辅助表
    //从1开始迎合堆
    for(i = 1; i <= G->VertexNum; ++i)
    {
        T[i].index = i;
        T[i].mark = 0;
        T[i].way_length = infinity;
        T[i].preNode = -1;
    }

    H = Create_heap(MaxQueue);
    printf("---\n");
    printf("输入起始点:");
    scanf("%d", &v);
    T[v].way_length = 0;
    Insert(H, &T[v]);
    //printf("H->Size = %d\n", H->Size);
    //printf("H->Size = %d\n", H->Size);
    //printf("e->%d",e->index);
  
    while(isEmpty(H))
   {
        e = DeleteMin(H);
        T[e->index].mark = 1;
        p = G->adjlist[e->index].firstEdge;

        while(p != NULL)
        {
            //T[p->adjvex]->way_length = p->weight;
            if(!T[p->adjvex].mark)
            {
                if(T[e->index].way_length + p->weight < T[p->adjvex].way_length)
                {
                    T[p->adjvex].way_length = T[e->index].way_length + p->weight;
                    printf("更新weight = %d\n", p->weight);
                
                T[p->adjvex].preNode = e->index;
                }
                //T[p->adjvex].preNode = e->index;
                Insert(H, &T[p->adjvex]);
            }

            p = p->next;
        }
    }


    printf("请输入终点:");
    scanf("%d", &final);
    Print_Dijkstra(final, T);
    printf("\n");
    printf("起点%d 到终点 %d 的最短路径距离是%d\n",v, final, T[final].way_length);
    printf("\n");
    for(i = 1; i <= G->VertexNum; ++i)
    {
        printf("index.%d,mark.%d,way_length.%d, preNode.%d\n", T[i].index, T[i].mark, T[i].way_length, T[i].preNode);
    }

    
}

int main()
{
    AdjGraph *G;

    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    assert(G != NULL);
    Create_graph(G);
    Print_graph(G);
    Dijkstra(G);

    return 0;
}
