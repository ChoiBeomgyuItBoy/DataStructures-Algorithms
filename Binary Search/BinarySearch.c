//  ----------- Binary Search implementation in C -----------

#include<stdio.h>

#define sizeOfArray 100

int binarySearch(int array[], int size, int targetValue)
{
    int low = 0; // Reference to the beginning index of the array
    int high = size - 1;  // Reference to the last index of the array

    while(low <= high) // Repeat all steps untill the target is found
    {
        int middle = low + (high - low) / 2; // Reference to the middle index of the array
        int value = array[middle]; 

        if(value < targetValue) // If the value in the middle is less than the target, discard all the left side from the middle
        {                       
            low = middle + 1;
        }
        else if(value > targetValue) // If the value in the middle is greater than the target, discard all the right side from the middle
        {
            high = middle - 1;
        }
        else  // Found the target 
        {
            return middle;
        }
    }

    return -1;
}

int main()
{
    int array[sizeOfArray];

    for(int i = 0; i < sizeOfArray; i++) // Filling array with numbers from 1 to 100
    {
        array[i] = i + 1;
    }

    int targetValue = 23;

    int index = binarySearch(array, sizeOfArray, targetValue); // Calling binary search

    if(index == -1)
    {
        printf("%d not found\n", targetValue);
    }
    else
    {
        printf("%d found at index %d\n", targetValue, index);  // Output : 23 found at index 22
    }

    return 0;
}