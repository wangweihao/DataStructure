// =====================================================================================
//
//       Filename:  EK.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月21日 19时43分56秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================
#include <stdio.h>
#include <memory.h>
#include "queue.h"

#define Infinity 10000;
#define N 201

int cap[N][N];       //容量
int real_cap[N][N];  //实际流量
int preNode[N];      //记录增广路径
int res[N];          //记录残存网络流量，容量减去流量.   有n个节点，一次残余网络流最多有n-1个

int EK(int s, int t)
{
    int i,j;
    queue_t *q;
    int max_flow = 0;
    int v;//保存出队的要处理的节点

    q = create_queue();
    init_queue(q);



    while(1)
    {
        memset(res, 0, sizeof(res));
        res[s] = Infinity;
        preNode[s] = -1;//起点为-1,最后需要遍历增广路径
        in_queue(q, s);

        while(empty_queue(q))
        {
            //用BFS求增广路径
            v = out_queue(q);
            for(i = 1; i <= t; i++)//对每个节点起始的邻接边查看
            {
                //if((!res[i])&&(real_cap[v][i] < cap[v][i]))//没有处理的且最短的
                //res[i] 也算是一个标记类似BFS 
                if(!res[i] && real_cap[v][i] < cap[v][i])
                {
                    in_queue(q, i);
                    preNode[i] = v;//保存路径
                    //每次都是那个小赋值给res[i],所以res[i]最后保存的就是增广路径的边的最小的流量
                    if(cap[v][i] - real_cap[v][i] > res[v])
                    {
                        res[i] = res[v];
                    }
                    else
                    {
                        res[i] = cap[v][i] - real_cap[v][i];
                    }
                }
            }
        }
        //如果终点的残余容量是0，那么不存在增广路径，不可能在有边流从而到达通过终点
        if(res[t] == 0) //无增广路径， 退出结束
            break;

        int k = t;
        while(preNode[k] != -1)//遍历路径,同时用残余容量修改刚刚探索的增广路径
        {
            real_cap[preNode[k]][k] += res[t];
            real_cap[k][preNode[k]] -= res[t];
            k = preNode[k];
        }
        max_flow += res[t];
        printf("max_flow %d   res[%d] = %d\n", max_flow, t, res[t]);
    }
/*
    for(i = 1; i < 10; i++)
    {
        max_flow += real_cap[t][i];
        printf("real_cap %d\n", real_cap[t][i]);
    }
*/
    return max_flow;
}

int main()
{
    int vertexNum, edgeNum;
    int i, j;
    int u, v, w;
    int start, final;

    printf("请输入顶点,边数:");
    scanf("%d,%d", &vertexNum, &edgeNum);

    //两个矩阵都初始化为0
    memset(cap, 0, sizeof(cap)); 
    memset(real_cap, 0, sizeof(real_cap));

    for(i = 1; i <= edgeNum; i++)
    {
        printf("请输入v1,v2,w:");
        scanf("%d,%d,%d", &u, &v, &w);
        cap[u][v] = w;
    }

    printf("请输入起点,终点:");
    scanf("%d,%d" ,&start, &final);
    printf("最大流是:%d\n", EK(start, final));


    return 0;
}
