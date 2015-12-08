// =====================================================================================
//
//       Filename:  heap.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月18日 17时00分42秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================


#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define Max 100

typedef struct edgeArray
{
    int Beg;
    int End;
    int weight;
}edgeArray[Max];

typedef struct kruGraph
{
    int VertexNum, EdgeNum;
    edgeArray *edge;
    int *SetUnion;
}kruGraph;


typedef struct edgeArray* ElementType;

typedef struct HeapStruct
{
    int Capacity;//容量
    int Size;    //某一时刻元素的大小
    ElementType* element;
}PriorityQueue;

PriorityQueue* Create_heap(int MaxElement);  //创建堆
void Insert(PriorityQueue *H, ElementType x);//插入
ElementType DeleteMin(PriorityQueue *H);     //小顶堆删除最小元，就是堆顶
int isEmpty(PriorityQueue *H);               //判断堆是否为空

int isEmpty(PriorityQueue *H)
{
    return H->Size;
}

PriorityQueue* Create_heap(int MaxNum)
{
    PriorityQueue *H;

    H = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    assert(H != NULL);
    H->Capacity = MaxNum;
    H->Size = 0;//此时的元素个数为0
    H->element = (ElementType*)malloc(sizeof(ElementType)*(MaxNum+1));//下标从1开始好算
    assert(H->element != NULL);

    H->element[0] = (ElementType)malloc(sizeof(struct edgeArray));
    //assert(H->element[0]);
    H->element[0]->weight = -32700;//小顶堆，假设[0]元素被设定为最小值,否则插入时要添加条件

    printf("create success\n");
    return H;
}

/*
 * 删除堆顶元素， 保存最后一个元素 H->Size-- 元素个数-1
 * 堆顶则留有空穴
 * 查找合适的位置放置lastelement
 */

ElementType DeleteMin(PriorityQueue *H)
{
    ElementType Minelement, Lastelement;
    int i, Child;

    Minelement = H->element[1];
    Lastelement = H->element[H->Size--];

    for(i = 1; i*2 <= H->Size; i = Child)
    {
        Child = i * 2;
        //判断是左儿子还是右儿子上移
        if(Child != H->Size && H->element[Child+1]->weight < H->element[Child]->weight)
            Child++;

        //如果出现大于Lastelement的元素,那么移位保留空洞并退出。
        if(Lastelement->weight > H->element[Child]->weight)
            H->element[i] = H->element[Child];
        else
            break;

    }
    //放置到保留的空洞里面
    H->element[i] = Lastelement;
  //  printf("删除%d\n", Minelement->weight);
    return Minelement;
}

//建立一个空穴，一直往上冒。
void Insert(PriorityQueue *H, struct edgeArray* x)
{
    ElementType temp;
    int i;

    //printf("插入\n");

    //插入的值先插入到最后， 然后在一直向上比较，移动
    H->element[++H->Size] = x;
    for(i = H->Size; H->element[i]->weight < H->element[i/2]->weight; i /= 2)
    {
        temp = H->element[i];
        H->element[i] = H->element[i/2];
        H->element[i/2] = temp;
    }
    
    /*方法2
    for(i = ++H->Size; H->element[i/2] > x; i /= 2)
        H->element[i] = H->element[i/2];
    H->element[i] = x;//要插入的值赋值给空穴
    */
}



#endif
