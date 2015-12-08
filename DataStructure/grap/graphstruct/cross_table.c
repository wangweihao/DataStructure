// =====================================================================================
//
//       Filename:  cross_table.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月17日 12时40分04秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

/*
 * 十字链表， 结合邻接表和逆邻接表的一种数据结构
 * 时间复杂度和邻接表相同
 * 因此在有向图中， 它是很好的数据结构
 */

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

enum { verMax = 10 };

typedef int VertexType;
typedef int EdgeType;//权

//边表节点结构
typedef struct EdgeNode
{
    int adjvex;
    int again_adjvex;
    struct EdgeNode* again_next;
    struct EdgeNode* next;
    EdgeType weight;
}EdgeNode;

//顶点表
typedef struct VertexNode
{
    VertexType data;
    EdgeNode* firstin;   //逆邻接表边表的下一个节点
    EdgeNode* firstout;         //邻接表边表的下一个节点
}CrossList[verMax+1], VertexNode;

typedef struct CrossGraph
{
    int EdgeNum, VertexNum;
    CrossList crosslist;
}CrossGraph;

void Create_graph(CrossGraph *G)
{
    int i, j, k, w;
    EdgeNode *e;
    EdgeNode *q;

    printf("请输入顶点，边数:");
    scanf("%d,%d", &G->VertexNum, &G->EdgeNum);
    printf("请输入顶点:");
    for(k = 1; k <= G->VertexNum; ++k)//初始化顶点表
    {
        scanf("%d", &G->crosslist[k].data);
        G->crosslist[k].firstin = NULL;
        G->crosslist[k].firstout = NULL;
    }

    for(k = 1; k <= G->EdgeNum; ++k)
    {
        printf("请输入边的两端节点和权v1, v2, w:");
        scanf("%d,%d,%d", &i, &j, &w);
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        assert(e != NULL);
        e->next = NULL;
        e->again_next = NULL;
        
        
        e->again_adjvex = i;//逆邻接表边表节点
        e->adjvex = j;      //邻接表
        
        e->next = G->crosslist[i].firstout;
        G->crosslist[i].firstout = e;
//比邻接表多了一个入度的表示        
        e->again_next = G->crosslist[j].firstin;
        G->crosslist[j].firstin = e;

    }
}

int main()
{
    CrossGraph *G;
    int i = 0, j = 0;

    EdgeNode *e;
    G = (CrossGraph *)malloc(sizeof(CrossGraph));
    assert(G != NULL);
    Create_graph(G);
    printf("邻接表\n");
    for(i = 1; i <= G->VertexNum; ++i)
    {
        printf("|%d|->", G->crosslist[i].data);
        e = G->crosslist[i].firstout;
        while(e != NULL)
        {
            printf("%d->", e->adjvex);
            e = e->next;
        }
        printf("NULL\n");
    }
    printf("逆邻接表\n");
    for(i = 1; i <= G->VertexNum; ++i)
    {
        printf("|%d|<-", G->crosslist[i].data);
        e = G->crosslist[i].firstin;
        while(e != NULL)
        {
            printf("%d<-", e->again_adjvex);
            //标记  ,  注意逆邻接表的标量， 分清next 和 again_next!
            e = e->again_next;
        }
        printf("NULL\n");
    }

    return 0;

}
