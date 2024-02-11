#include <stdio.h>
#include "my_mat.h"

#define INT_MAX 2147483647


void inputMatrix(int matrix[][SIZE])
{
    for(int i = 0 ; i < SIZE ; i++)
    {
        for(int j = 0 ; j < SIZE; j++)
        {
            scanf("%d",&matrix[i][j]);
          /*  if(i == j)
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
        if(val != INT_MAX)
        {
            printf("True");
        }
        else
        {
            printf("False");
        }
    }
}

void pathWeight(int matrix[][SIZE],int src,int dest)
{
    int weight;
    weight= shortestPath(matrix,src,dest);

    if(weight == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d",weight);
    }
}

int minDistance(int dist[], int sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < SIZE; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int shortestPath(int matrix[][SIZE],int src,int dest)
{
    int SumDist[SIZE];
    int sptSet[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        SumDist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    SumDist[src] = 0;

    for (int count = 0; count < SIZE - 1; count++)
    {

        int u = minDistance(SumDist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < SIZE; v++)
        {
            if (!sptSet[v] && matrix[u][v] && SumDist[u] != INT_MAX && SumDist[u] + matrix[u][v] < SumDist[v])
            {
                SumDist[v] = SumDist[u] + matrix[u][v];
            }
        }

    }
    return SumDist[dest];
}

