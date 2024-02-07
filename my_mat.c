#include "../../../../../my_mat.h"
#include <stdio.h>
#include <limits.h>

void inputMatrix(int matrix[][SIZE])
{
    for(int i = 0 ; i < SIZE ; i++)
    {
        for(int j = 0 ; j < SIZE; j++)
        {
            scanf("%d",&matrix[i][j]);
          /*  if(i == j) /// ???
            {
                matrix[i][j] = 0;
                continue;
            }*/
        }
    }
}

void isValidPath(int matrix[][SIZE],int src,int dest)
{
    int val;

    if(matrix[dest][src] != 0)
    {
        printf("True");
    }
    else
    {
        val= shortestPath(matrix,src,dest);
        if(val != 0)
        {
            printf("True");
        }
        else
        {
            printf("False");
        }
    }
}

int shortestPath(int matrix[][SIZE],int src,int dest)
{
    int SumDist[SIZE]= {INT_MAX};
    int _start= src;

    SumDist[src] = 0;

    /////////////////TO_DO

    printf("%d", SumDist[dest]);
    return SumDist[dest];
}





