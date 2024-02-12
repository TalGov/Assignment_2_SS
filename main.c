#include <stdio.h>
#include "my_mat.h"


int main()
{

    int matrix[SIZE][SIZE]= {0}; //Neighborhood matrix containing weights
    char choice;
    int src;
    int dest;

    while (1) //The block will be executed until D or EOF is received
    {
        scanf("%c", &choice); //input from the user

        switch (choice) //using in switch case
        {
            case 'A': //input of the matrix from the user
                inputMatrix(matrix);
                break;

            case 'B': //Checks if exists a path from i to j
                scanf("%d", &dest);
                scanf("%d", &src);
                isValidPath(matrix,src,dest);
                break;

            case 'C': //Prints the path with the lowest weight between i,j
                scanf("%d", &dest);
                scanf("%d", &src);
                pathWeight(matrix,src,dest);
                break;

            case 'D' : //exit
                return 0;

            case EOF: //end of file
                return 0;

        }
    }
}
