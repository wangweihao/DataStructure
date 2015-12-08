// =====================================================================================
//
//       Filename:  adjmullist.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月17日 20时52分24秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

enum { verMax = 10 };

typedef int VertexType;
typedef int EdgeType;

//边节点信息
typedef struct EdgeNode
{
    int mark;     //标记是否访问过
    int ivex;     
    int jvex;
    struct EdgeNode* ilink;
    struct EdgeNode* jlink;
    int weight;
}EdgeNode;

//顶点信息
typedef struct VertexNode
{
    VertexType vertex;
    EdgeNode* firstEdge;
}Adjmulist[verMax+1], VertexNode;

//图结构
typedef struct 
{
    int VertexNum, EdgeNum;
    Adjmulist adjmulist;
}adjmulistGraph;

void Print_Graph(adjmulistGraph *G)
{
    int i;
    EdgeNode* p;

    for(i = 1; i <= G->VertexNum; ++i)
    {
        p = G->adjmulist[i].firstEdge;
        while(p != NULL)
        {
            if(p->ivex == i)    //判断相等才能知道连接上的是ivex还是jvex;
            {
                printf("%d--%d\n", G->adjmulist[p->ivex].vertex, G->adjmulist[p->jvex].vertex);
                p = p->ilink;
            }
            else//jvex
            {
                printf("%d--%d\n", G->adjmulist[p->jvex].vertex, G->adjmulist[p->ivex].vertex);
                p = p->jlink;
            }
        }
    }
}

void Create_Graph(adjmulistGraph *G)
{
    int criculate;
    int vertex[2];       //需要测试一条边的两个点
    EdgeNode *p, *newedge;
    int i;
    int w;

    printf("请输入顶点，边数:");
    scanf("%d,%d", &G->VertexNum, &G->EdgeNum);
    printf("请输入顶点:");
    for(i = 1; i <= G->VertexNum; ++i)
    {
        scanf("%d", &G->adjmulist[i].vertex);
    }
    criculate = G->EdgeNum;
    while(criculate--)
    {
        printf("请输入v1,v2");
        scanf("%d,%d,%d", &vertex[0], &vertex[1], &w);
        newedge = (EdgeNode*)malloc(sizeof(EdgeNode));
        assert(newedge != NULL);
        newedge->ivex = vertex[0];
        newedge->jvex = vertex[1];
        newedge->weight = w;
        //组成一条边的两个点都要处理
        for(i = 0; i < 2; i++)            
        {
            p = G->adjmulist[vertex[i]].firstEdge;
            if(p == NULL)
            {
                G->adjmulist[vertex[i]].firstEdge = newedge;
            }
            else
            {
                while((p->ilink != NULL && p->ivex == vertex[i]) || (p->jlink != NULL && p->jvex == vertex[i]))//找到末尾
                {
                    if(vertex[i] == p->ivex)
                        p = p->ilink;
                    else// ==jvex
                        p = p->jlink;
                }
                if(p->ivex == vertex[i])
                    p->ilink = newedge;
                else
                    p->jlink = newedge;
            }
        }

    }
}

int main()
{
    adjmulistGraph *G;
    G = (adjmulistGraph*)malloc(sizeof(adjmulistGraph));
    assert(G != NULL);
    Create_Graph(G);
    printf("\n\n");
    Print_Graph(G);

    return 0;
}
