#include <stdio.h>
#include <stdlib.h> // for malloc() and free()

void quickSort(int *data, int low, int high);
int partition(int *data, int low, int high);
void writeData(int *data, int count);

int main()
{
    int count = 1000000;
    int *data = (int *)malloc(count * sizeof(int)); // Dynamically allocate memory
    if (data == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening input file\n");
        free(data); // Free allocated memory if file opening fails
        return 1;
    }

    // Read data from the file into the array
    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    printf("Sorting....\n");
    quickSort(data, 0, count - 1); // Call QuickSort
    writeData(data, count);        // Write sorted data to the file

    free(data); // Free allocated memory
    return 0;
}

// Quick Sort function
void quickSort(int *data, int low, int high)
{
    if (low < high)
    {
        // Find the partition index
        int pivotIndex = partition(data, low, high);

        // Recursively sort elements before and after partition
        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }
}

// Partition function to divide array and find the pivot position
int partition(int *data, int low, int high)
{
    int pivot = data[high]; // Choosing the last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            // Swap data[i] and data[j]
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    // Swap data[i + 1] with pivot (data[high])
    int temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;

    return i + 1; // Return the partition index
}

// Function to write sorted data to a file
void writeData(int *data, int count)
{
    FILE *fp = fopen("result.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening result file\n");
        return;
    }

    // Write the sorted data to the file
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d\t", data[i]);
    }

    fclose(fp); // Close the file
    printf("Sorted successfully\n");
}
