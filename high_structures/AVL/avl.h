// =====================================================================================
//
//       Filename:  avl.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年03月20日 00时15分32秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#ifndef _AVL_H_
#define _AVL_H_

#include <stdio.h>
#include <malloc.h>

struct AvlNode;
typedef int ElementType;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree Insert(ElementType X, AvlTree T);


Position 
SingleRotateWithLeft(Position K2);

Position
SingleRotateWithRight(Position K2);

Position
DoubleRotateWithLeft(Position K3);

Position
DoubleRotateWithRight(Position K3);

ElementType Max(ElementType lhs, ElementType rhs);

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

int Height(Position P)
{
    if(P == NULL)
    {
        return -1;
    }
    else
    {
        return P->Height;
    }
}

AvlTree
Insert(ElementType X, AvlTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct AvlNode));
        if(T == NULL)
        {
            printf("error malloc\n");
        }
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2)
        {
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(X < T->Element)
    {
        T->Right = Insert(X, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2)
        {
            if(X > T->Right->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

ElementType Max(ElementType lhs, ElementType rhs)
{
    return lhs > rhs ? lhs : rhs;
}

Position 
SingleRotateWithLeft(Position K2)
{
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right))+1;
    K1->Height = Max(Height(K1->Left), K2->Height);

    return K1;
}

Position
SingleRotateWithRight(Position K2)
{
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = Max(Height(K2->Right), Height(K2->Left))+1;
    K1->Height = Max(Height(K1->Right), K2->Height);

    return K1;
}

Position
DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    
    return SingleRotateWithLeft(K3);
}

Position
DoubleRotateWithRight(Position K3)
{
    K3->Right = SingleRotateWithLeft(K3->Right);

    return SingleRotateWithRight(K3);
}

void PrintTree(AvlTree T)
{
    if(T != NULL)
    {
        printf("T\n");
        PrintTree(T->Left);
        PrintTree(T->Right);
        printf("X:\n", T->Element);
    }
}

#endif

