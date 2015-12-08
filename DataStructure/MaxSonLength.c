// =====================================================================================
//
//       Filename:  MaxSonLength.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月10日 13时08分43秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include <stdio.h>

int Max3(a, b, c)
{
    if(a < b)
        a = b;
    if(a < c)
        a = c;

    return a;
}

int MaxSubsequenceSum_a(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for(i = 0; i < N; i++)
        for(j = i; j < N; j++)
        {
            ThisSum = 0;
            for(k = i; k <= j; k++)
            {
                ThisSum += A[k];
            }
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }

    return MaxSum;
}

int MaxSubsequenceSum_b(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for(i = 0; i < N; i++)
    {
        ThisSum = 0;
        for(j = i; j < N; j++)
        {
            ThisSum += A[j];

            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxSubsequenceSum_c(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int LeftBorderSum, RightBorderSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int center, i;

    if(Left == Right)
        if(A[Left] > 0)
            return A[Left];
        else
            return 0;

    center = (Right+Left) / 2;
    MaxLeftSum = MaxSubsequenceSum_c(A, Left, center);
    MaxRightSum = MaxSubsequenceSum_c(A, center+1, Right);

    LeftBorderSum = 0; MaxLeftBorderSum = 0;
    for(i = center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    RightBorderSum = 0; MaxRightBorderSum = 0;
    for(i = center+1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum+MaxRightBorderSum);
}

int MaxSubsequenceSum_d(const int A[], int N)
{
    int i = 0;
    int MaxSum, Sum;

    MaxSum = 0; Sum = 0;
    for(i = 0; i < N; i++)
    {
        Sum += A[i];

        if(Sum > MaxSum)
            MaxSum = Sum;
        else if(Sum < 0)
            Sum = 0;
    }

    return MaxSum;
}

int main(int argc, char *argv[])
{
    int MaxSum = 0;
    int MaxSum2 = 0;
    int MaxSum3 = 0;
    int MaxSum4 = 0;
    int a[6] = { -2, 11, -4, 13, -5, -2 };
    
    MaxSum = MaxSubsequenceSum_a(a, 6);
    MaxSum2 = MaxSubsequenceSum_b(a, 6);
    MaxSum3 = MaxSubsequenceSum_c(a, 0, 5);
    MaxSum4 = MaxSubsequenceSum_d(a, 6);
    printf("MaxSubsequenceSum_a = %d\n", MaxSum);
    printf("MaxSubsequenceSum_b = %d\n", MaxSum2);
    printf("MaxSubsequenceSum_c = %d\n", MaxSum3);
    printf("MaxSubsequenceSum_d = %d\n", MaxSum4);

    return 0;
}
