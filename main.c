#include <stdio.h>
#include "my_mat.h"


int main()
{
    int matrix[SIZE][SIZE]= {0};
    char choice;
    int src;
    int dest;

    while (1)
    {
        scanf("%c", &choice);

        switch (choice)
        {
            case 'A':
                inputMatrix(matrix);
                for(int i = 0 ; i < SIZE ; i++)
                {
                    for(int j = 0 ; j < SIZE; j++)
                    {
                        printf("%d", matrix[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 'B':
                scanf("%d", &dest);
                scanf("%d", &src);
                isValidPath(matrix,src,dest);
                break;

            case 'C':
                scanf("%d", &dest);
                scanf("%d", &src);
                pathWeight(matrix,src,dest);
                break;

            case 'D' : ////EOF
                return 0;


        }
    }
}
