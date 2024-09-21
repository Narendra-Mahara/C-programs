#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("student.txt", "w"); // Open the file for writing
    // If the file does not exist, it will be created. If the file exists, it will be truncated to zero length.

    if (fp == NULL)
    {
        printf("File not found\n"); // If the file is not found, print an error message
        return 1;
    }

    // fputc('c', fp); // Write a character to the file

    // fputs("Hello, World!\n", fp); // Write a string to the file

    // Write some data to the file
    fprintf(fp, "This is student record\nSN\t Name\t Grade\n1\t Ram\t A\n2\t Shyam\t B\n3\t Hari\t C\n4\t Gita\t A\n5\t Sita\t B\n"); // Write a formatted string to the file

    fclose(fp); // Close the file
    printf("Data are written successfully!\n");
    return 0;
}