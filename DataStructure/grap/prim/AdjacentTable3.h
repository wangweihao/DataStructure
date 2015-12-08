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
#include <malloc.h>//从0开始

enum { verMax = 100 };

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
    int indegree;
    EdgeNode *firstEdge;      //边表头指针
}Adjlist[verMax+1], VertexNode; //Adglist 是 struct Vertex [verMax]类型的

typedef struct AdjGraph
{
    int EdgeNum, VertexNum;
    Adjlist adjlist;
}AdjGraph;


int Create_graph(AdjGraph *G)
{
    int i, j, k, w;
    EdgeNode *e;
    int MinWeight = 10000;
    int MinIndex;

    printf("请输入顶点，边数:");
    scanf("%d,%d", &G->VertexNum, &G->EdgeNum);
    printf("请输入顶点:");
    for(i = 1; i <= G->VertexNum; i++)
    {
        scanf("%d", &G->adjlist[i].data);
        G->adjlist[i].firstEdge = NULL;
        G->adjlist[i].indegree = 0;
   }

    for(k = 1; k <= G->EdgeNum; k++)
    {
        printf("请输入边的两端节点和权v1, v2, w:");
        scanf("%d,%d,%d", &i, &j, &w);
        
        if(w < MinWeight)
        {
            MinWeight = w;
            MinIndex = i;
        }
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        assert(e != NULL);
  
        e->adjvex = j;
        e->weight = w;
        e->next = G->adjlist[i].firstEdge;
        G->adjlist[i].firstEdge = e;
        (G->adjlist[j].indegree)++;

        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        assert(e != NULL);
        e->adjvex = i;
        e->weight = w;
        e->next = G->adjlist[j].firstEdge;
        G->adjlist[j].firstEdge = e;

    }

    return MinIndex;
}

Print_graph(AdjGraph *G)
{
    int i;
    EdgeNode *e;

    for(i = 1; i <= G->VertexNum; ++i)
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
}
    
