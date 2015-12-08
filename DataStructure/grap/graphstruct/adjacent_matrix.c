// =====================================================================================
//
//       Filename:  adjacent_matrix.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年10月30日 20时04分16秒
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

//const int Maxvex = 100;
enum{ Maxvex = 100 };
const int infinity = 10000;

typedef struct graph
{
    int vexs[Maxvex+1];//顶点数
    int arc[Maxvex+1][Maxvex+1];//邻接矩阵
    int EdgeNum, VexsNum;//边数，顶点数
}Mgraph;

void create_graph(Mgraph *G)
{
    int i,j,k,w;
    printf("请输入顶点数,边数:");
    scanf("%d,%d", &G->VexsNum, &G->EdgeNum);

    //输入顶点
    for(i = 1; i <= G->VexsNum; i++)
        scanf("%d", &G->vexs[i]);
    //初始化邻接矩阵
    for(i = 1; i <= G->VexsNum; i++)
    {
        for(j = 1; j <= G->VexsNum; j++)
        {
            G->arc[i][j] = infinity;
        }
    }

    //录入边
    printf("EdgeNum:%d\n", G->EdgeNum);
    for(k = 1; k <= G->EdgeNum; k++)
    {
        printf("输入边的i, j, 权值:");
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];//无向图arc[i][j]和 arc[j][i]是同一条边
    }
}

int main()
{
    Mgraph *G;

    G = (Mgraph*)malloc(sizeof(Mgraph));
    assert(G != NULL);//if G != NULL false error
    create_graph(G);
}
