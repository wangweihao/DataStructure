// =====================================================================================
//
//       Filename:  Bellman_Ford.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月19日 13时37分27秒
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

//enum { infinity = 10000, MaxNum = 100 };

#define infinity 10000
#define MaxNum 100

typedef int EdgeType;
typedef int VertexType;

typedef struct SideArray
{
    EdgeType v;//起始点
    EdgeType u;//终点
    int weight;
}SideArray;

typedef struct BellGraph
{
    int VertexNum, EdgeNum;
    SideArray *edge;
    int *distant;
    int *preNode;
}BellGraph;

int Bell_Ford(BellGraph *G)
{
    int i,j,k,w;
    EdgeType start, final;
    int flag = 0;
    
    G = (BellGraph*)malloc(sizeof(BellGraph));
    assert(G != NULL);
    printf("请输入顶点,边数:");
    scanf("%d,%d", &G->VertexNum, &G->EdgeNum);
    //G->VertexNum = 4;
    //G->EdgeNum = 5;
    G->edge = (SideArray*)malloc(sizeof(SideArray) * (G->EdgeNum+1));
    assert(G->edge != NULL);
    G->distant = (int*)malloc(sizeof(int) * (G->VertexNum+1));
    assert(G->distant != NULL);
    G->preNode = (int*)malloc(sizeof(int) * (G->VertexNum+1));
    assert(G->preNode != NULL);

    for(i = 1; i <= G->VertexNum; ++i)
    {
        G->distant[i] = 10000;
        G->preNode[i] = 0;
    }
    G->preNode[0] = -1;
    for(i = 1; i <= G->EdgeNum; ++i)
    {
        G->edge[i].v = 0;
        G->edge[i].u = 0;
        G->edge[i].weight = -1;
    }

    for(k = 1; k <= G->EdgeNum; ++k)
    {
        printf("请输入v1,v2,w:");
        scanf("%d,%d,%d", &i, &j, &w);
        G->edge[k].v = i;
        G->edge[k].u = j;
        G->edge[k].weight = w;
    }
  /*  G->edge[1].v = 1;
    G->edge[1].u = 2;
    G->edge[1].weight = 1;
    G->edge[2].v = 1;
    G->edge[2].u = 3;
    G->edge[2].weight = 1;
    G->edge[3].v = 1;
    G->edge[3].u = 4;
    G->edge[3].weight = 1;
    G->edge[4].v = 2;
    G->edge[4].u = 4;
    G->edge[4].weight = 1;
    G->edge[5].v = 3;
    G->edge[5].u = 4;
    G->edge[5].weight = 1;
*/

    printf("请输入起点，终点");
    scanf("%d,%d", &start, &final);
    //start = 1, final = 4;
    for (i = 1; i <= G->VertexNum; ++i)
    {
        G->distant[i] = infinity;
        G->preNode[i] = 0;
    }
    G->distant[start] = 0;

    for(i =1; i <= G->VertexNum-1; i++)//对所有的边进行松弛计算
    {
        for(j = 1; j <= G->EdgeNum; j++)
        {
            printf("%d, %d\n",G->edge[j].u, G->distant[G->edge[j].u]);
            if(G->distant[G->edge[j].u] > G->distant[G->edge[j].v] + G->edge[j].weight)
            {
                printf("发生松弛\n");
                printf("%d的先前节点变为%d\n", G->edge[j].u, G->edge[j].v);
                printf("%d,%d,%d\n", G->edge[j].v, G->edge[j].u, G->edge[j].weight);
                G->distant[G->edge[j].u] = G->distant[G->edge[j].v] + G->edge[j].weight;
                G->preNode[G->edge[j].u] = G->edge[j].v;
            }
        }
    }
    printf("%d the distance = %d\n", final, G->distant[final]);

    for(i = 1; i <= G->EdgeNum; i++)
    {
        if(G->distant[G->edge[i].u] > G->distant[G->edge[i].v] + G->edge[i].weight)
        {
            flag = 1;
            printf("该图有负圈环\n");
            break;
        }
    }


    printf("%d\n",G->VertexNum);
    for(i = 1; i <= G->VertexNum; ++i)
        printf("%d到%d距离是%d\n", start, i, G->distant[i]);
    G->preNode[final] = -1;
    int s = start;
    for(i = 1; i <= G->VertexNum; i++)
        printf("preNode[%d] = %d  ",i, G->preNode[i]);
    printf("\n\n");
    while(G->preNode[s] != -1)
    {
        printf("%d to ",G->preNode[s]);
        s = G->preNode[s];
    }

    return flag;
}

int main()
{
    BellGraph *G;
    Bell_Ford(G);

    return 0;
}
