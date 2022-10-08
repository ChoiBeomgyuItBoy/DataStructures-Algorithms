//  ----------- Linear Search implementation in C -----------

#include<stdio.h>

int linearSearch(int array[], int size, int targetValue)
{
    for(int i = 0; i < size; i++) // Iterates through all the array 
    {
        if(array[i] == targetValue) // Checks if the current value of the array is equal to the target
        {
            return i;  // Returns the index 
        }
    }

    return -1;  // If the target wasn't found, returns -1
}

int main()
{
    int array[] = { 2, 3, 1, 8, 9, 10, 20, 4, 45, 23 };
    int size = sizeof(array) / sizeof(int);
    int targetValue = 23;

    int index = linearSearch(array, size, targetValue);

    if(index == -1)
    {
        printf("Target %d not found\n", targetValue);  
    }
    else
    {
        printf("Found target %d at index %d\n", targetValue, index);    // Output : Found target 23 at index 9
    }

    return 0;
}
