#include <stdio.h>
#include "my_mat.h"

#define INT_MAX 2147483647 //The maximum value of integer


void inputMatrix(int matrix[][SIZE])
{
    //Receives the matrix values (the weights) from the user

    for(int i = 0 ; i < SIZE ; i++)
    {
        for(int j = 0 ; j < SIZE; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}

void isValidPath(int matrix[][SIZE],int src,int dest)
{
    int val;

    //If there is an arc between the vertices and it's not the same vertex, we will return true without checking
    if(matrix[dest][src] != 0 && src != dest)
    {
        printf("True");
    }
    else
    {
        val= shortestPath(matrix,src,dest); //val = the lowest weight between 2 vertices
        if(val != INT_MAX &&  src != dest)
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
    int valWeight;
    valWeight= shortestPath(matrix,src,dest); //valWeight = the lowest weight between 2 vertices

    if(valWeight == INT_MAX || src == dest) //There is no path between the vertices or it's the same vertex
    {
        printf("-1");
    }
    else
    {
        printf("%d",valWeight); //When there is a path, the lowest weighted value is returned
    }
}

int minDistance(int distances[], int shortestPath[])
{
    int min = INT_MAX;
    int minIndex;

    // Loop of all vertices
    for (int i = 0; i < SIZE; i++)
    {
        // Check if the vertex v is not yet included in the shortest path
        // and if the distance to vertex v is less than or equal to the current min
        if (shortestPath[i] == 0 && distances[i] <= min)
        {
            min = distances[i]; //Update the minimum distance value
            minIndex = i; //and the index of the vertex with min distance
        }
    }
    return minIndex; //Return the index of the vertex with the minimum distance
}

int shortestPath(int matrix[][SIZE],int src,int dest)
{
    int SumDist[SIZE];
    int shortestPath[SIZE];

    //Initialize all elements of SumDist[] to INT_MAX and shortestPath[] to 0
    for (int i = 0; i < SIZE; i++)
    {
        SumDist[i] = INT_MAX;
        shortestPath[i] = 0;
    }
    //Set the distance of the source vertex to 0
    SumDist[src] = 0;

    for (int c = 0; c < SIZE - 1; c++)
    {
        int min_index = minDistance(SumDist, shortestPath); //Using a function to find the min index with the min distance
        shortestPath[min_index] = 1; //Mark the found vertex

        for (int v = 0; v < SIZE; v++)
        {
            // Check if the vertex v is not yet included in the shortest path
            // and there is an edge from min_index to v
            if (!shortestPath[v] && matrix[min_index][v] && SumDist[min_index] != INT_MAX && SumDist[min_index] + matrix[min_index][v] < SumDist[v])
            {
                // Update the distance to vertex v
                SumDist[v] = SumDist[min_index] + matrix[min_index][v];
            }
        }
    }

    //Return the shortest distance to the dest vertex
    return SumDist[dest];
}

