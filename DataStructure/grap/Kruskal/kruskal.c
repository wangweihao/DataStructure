// =====================================================================================
//
//       Filename:  kruskal.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月20日 18时23分06秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include "heap.h"

enum { MaxNum = 100 };

kruGraph* init_graph(kruGraph *G)
{
    int i;
    int u, v, w;

    G = (kruGraph*)malloc(sizeof(kruGraph));
    assert(G != NULL);
    printf("请输入顶点,边数:");
    scanf("%d,%d", &G->VertexNum, &G->EdgeNum);
    //printf("%d,%d\n", G->VertexNum, G->EdgeNum);
    G->edge = (edgeArray*)malloc(sizeof(edgeArray));
    assert(G->edge != NULL);
    G->SetUnion = (int*)malloc(sizeof(int) * (G->VertexNum+1));
    assert(G->SetUnion != NULL);

    //初始化集合
    for(i = 1; i <= G->VertexNum; i++)
    {
        G->SetUnion[i] = 0;
    }
    //初始化边集数组
    for(i = 0; i < G->EdgeNum; i++)
    {
        printf("请输入v1,v2,w:");
        scanf("%d,%d,%d", &u, &v, &w);
        G->edge[i]->Beg = u;
        G->edge[i]->End = v;
        G->edge[i]->weight = w;
    }

    return G;
}

void Kruskal(kruGraph *G)
{
    PriorityQueue *H;
    ElementType e;
    int i = 0, j = 0;
    int u,v;


    H = Create_heap(MaxNum);
    //通过heap来优化
    //把边集数组放进heap中
    
    //printf("G->edgenum = %d\n", G->EdgeNum);
    for(i = 0; i < G->EdgeNum; ++i)
        Insert(H, G->edge[i]);
   // printf("测试\n");
    
     
    for(i = 0; i < G->EdgeNum; i++)
    {
        e = DeleteMin(H);
        u = find(G->SetUnion, e->Beg);
        v = find(G->SetUnion, e->End);

        if(u != v)
        {
            G->SetUnion[u] = v;
            printf("(%d,%d) %d  ", e->Beg, e->End, e->weight);
        }
    }
    
}


int find(int *a, int i)
{
    while(a[i] > 0)
        i = a[i];

    return i;
}

int main()
{
    kruGraph *G;

    G = init_graph(G);
    Kruskal(G);
    printf("\n\n");

    return 0;
}
