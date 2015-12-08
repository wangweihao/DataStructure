// =====================================================================================
//
//       Filename:  Min_way.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月18日 12时40分43秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

/*
 * 深度优先搜索
 * 无权图的最短路径
 * 借助于队列
 */

#include "AdjacentTable.h"
#include "queue.h"

enum { infinity = 10000 };

//一个表来存储各个节点的信息
typedef struct VertexInfo
{
    int mark; //是否被访问过
    int way_length;  //起始端点到此点的距离,松弛
    int preNode;     //记录上一个节点，输出最短路径
}VertexInfo[verMax+1];

/*
 * 为了简便
 * 假设图所有顶点关键字是数字，从0开始
 * 数组下标也从0 开始
 */


void Print_Minway(VertexType v, VertexInfo T)
{
    //结束条件是回到start起点
    if(T[v].preNode != -1)
    {
        Print_Minway(T[v].preNode, T);
        printf(" to");
    }
    printf("%d", v);
}


void min_way(AdjGraph *G)
{
    int i;
    VertexType start;
    VertexType v, w;
    queue_t *q;
    VertexInfo vertex_table;
    EdgeNode *e;
    VertexType final;

    //初始化表
    for(i = 1; i <= G->VertexNum; ++i)
    {
        vertex_table[i].mark = 0;
        vertex_table[i].way_length = infinity;
        vertex_table[i].preNode = -1;
    }
    q = create_queue();
    init_queue(q);
    
    printf("请输入起始的坐标:");
    scanf("%d", &start);
    in_queue(q, start);
    vertex_table[start].way_length = 0; //起始点设置为0

    while(empty_queue(q))
    {
        v = out_queue(q);
        vertex_table[v].mark = 1;

        //遍历边表。
        e = G->adjlist[v].firstEdge;
        while(e != NULL)
        {
            //if不成立说明已经遍历过, waylength已经是最短
            if(vertex_table[e->adjvex].way_length == infinity)
            {
                //边表节点的距离是上一个+1
                //记录上一个节点
                //入队
                vertex_table[e->adjvex].way_length = vertex_table[v].way_length+1;
                vertex_table[e->adjvex].preNode = v;
                in_queue(q, e->adjvex);
            }
            e = e->next;
        }
    }
    printf("请输入终点坐标:");
    scanf("%d", &final);
    Print_Minway(final, vertex_table);
    printf("\n");
}

int main()
{
    AdjGraph *G;

    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    assert(G != NULL);
    Create_graph(G);
    Print_graph(G);
    min_way(G);
}
