#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    // fgetc(); -------------------------> returns EOF when EOF is reached
    char ch;
    // ch = fgetc(fp); // read the first character of the file
    // printf("The first character of the file is: %c\n", ch);

    // while ((ch = fgetc(fp)) != EOF) // read all the characters of the file until EOF
    // {
    //     printf("%c", ch);
    // }

    // fgets(); ------------------------->  returns NULL when EOF is reached
    // char str[100]; // str to store each line
    // while (fgets(str, 100, fp) != NULL)
    // {
    //     printf("%s", str); // Print each line
    // }

    // fscanf(); -------------------------> returns EOF when EOF is reached
    char header[100]; // Buffer to store header lines
    int sn;
    char name[50];
    char grade;

    // Skip the first two lines (header)
    fgets(header, sizeof(header), fp); // output: This is student record i.e one line
    printf("%s", header);
    fgets(header, sizeof(header), fp); // output: SN Name Grade i.e one line
    printf("%s", header);

    // Read and print each record
    while (fscanf(fp, "%d %s %c", &sn, name, &grade) != EOF)
    {
        printf("%d\t%s\t%c\n", sn, name, grade);
    }

    fclose(fp);
    return 0;
}