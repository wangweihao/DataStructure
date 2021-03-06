// =====================================================================================
//
//       Filename:  adjacent_table.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月30日 23时37分45秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

/*
 * 邻接表结构
 * 创建时用到头插法
 */


#include <stdio.h>
#include <assert.h>
#include <malloc.h>

enum { verMax = 10 };

typedef int VertexType;
typedef int EdgeType;

typedef struct EdgeNode       //边表节点
{
    int adjvex;               //节点
    EdgeType weight;          //权
    struct EdgeNode* next;    
}EdgeNode;

typedef struct VertexNode     //顶点表节点
{
    VertexType data;
    EdgeNode *firstEdge;      //边表头指针
}Adjlist[verMax], VertexNode; //Adglist 是 struct Vertex [verMax]类型的

typedef struct AdjGraph
{
    int EdgeNum, VertexNum;
    Adjlist adjlist;
}AdjGraph;


void Create_graph(AdjGraph *G)
{
    int i, j, k, w;
    EdgeNode *e;

    printf("请输入顶点，边数:");
    scanf("%d,%d", &G->VertexNum, &G->EdgeNum);
    printf("请输入顶点:");
    for(i = 1; i <= G->VertexNum; i++)
    {
        scanf("%d", &G->adjlist[i].data);
        G->adjlist[i].firstEdge = NULL;
    }

    for(k = 1; k <= G->EdgeNum; k++)
    {
        printf("请输入边的两端节点和权v1, v2, w:");
        scanf("%d,%d,%d", &i, &j, &w);
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        assert(e != NULL);
        e->adjvex = j;
        e->next = G->adjlist[i].firstEdge;
        G->adjlist[i].firstEdge = e;
/*  
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        assert(e != NULL);
        e->adjvex = i;
        e->next = G->adjlist[j].firstEdge;
        G->adjlist[j].firstEdge = e;
*/
    }
}

int main()
{
    
    AdjGraph *G;
    int i = 0, j = 0;

    EdgeNode *e;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    assert(G != NULL);
    Create_graph(G);
    printf("\n");
    for(i = 1; i <= G->VertexNum; i++)
    {
        printf("|%d|->", G->adjlist[i].data);
        e = G->adjlist[i].firstEdge;
        while(e != NULL)
        {
            printf("%d->", e->adjvex);
            e = e->next;
        }
        printf("NULL\n");
    }

    return 0;
}
