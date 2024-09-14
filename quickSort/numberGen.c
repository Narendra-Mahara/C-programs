#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 1000000;
    int data;
    FILE *fp;
    fp = fopen("input.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Write random data to the file
    for (int i = 0; i < count; i++)
    {
        data = rand();
        fprintf(fp, "%d\t", data);
    }
    fclose(fp);
    printf("Data are written in the file successfully..\n");

    return 0;
}
