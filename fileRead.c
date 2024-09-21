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
    char hello[100];
    fscanf(fp, "%s", hello);    // read the first word of the file
    printf("%s\n", hello); // Print the first word of the file
    while (fscanf(fp,"%s", hello) != EOF)    
    {
        printf("%s\n", hello); // Print each word
    }
    
    fclose(fp);
    return 0;
}