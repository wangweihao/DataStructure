// =====================================================================================
//
//       Filename:  Topsort.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月19日 00时51分06秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include "queue.h"
#include "AdjacentTable2.h"

int main()
{
    queue_t *q;
    AdjGraph *G;
    int counter = 0;
    int i;
    VertexType v, w;
    VertexType TopNum[verMax];
    EdgeNode *e;

    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    assert(G);
    q = create_queue();
    init_queue(q);
    Create_graph(G);
    Print_graph(G);

    for(i = 1; i <= G->VertexNum; ++i)
        if(G->adjlist[i].indegree == 0)
            in_queue(q, i);
    for(i = 1; i <= G->VertexNum; ++i)
        printf("v[%d].indegree = %d\n", i, G->adjlist[i].indegree);

    while(empty_queue(q))
    {
        v = out_queue(q);
        //每次处理一个，后来比较是否处理的数量对。
        TopNum[v] = ++counter;
        e = G->adjlist[v].firstEdge;
        while(e != NULL)
        {
            if(--G->adjlist[e->adjvex].indegree == 0)
                in_queue(q, e->adjvex);
            e = e->next;
        }
    }

    if(counter != G->VertexNum)
    {
        printf("此图有环\n");
    }
    
    printf("排序后的顺序:");
    for(i = 1; i <= G->VertexNum; ++i)
        printf(" %d ->", TopNum[i]);
    printf("\n");

    return 0;

}
