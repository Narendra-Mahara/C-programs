#include <stdio.h>
int main()
{

    int row = 2;
    int column = 3;
    int a[row][column]; // matrix is a two dimensional array

    // Input from user
    printf("Enter the elements of matrix\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Printing the elements
    printf("The elements of matrix are\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {

            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}