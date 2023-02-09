// 13. Write a program to sort an unsorted array of elements by Merge Sort.

#include <stdio.h>
#include<stdlib.h>

// Merges two subarrays of arr[].
// First subarray ia arr[l..m]
// Second subarray is arr[m+l..r]

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    //Copy data to temp arrays L[] & R[]
    for(i=0; i<n1; i++)
        L[i] = arr[l + i];
    for(j=0; j<n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    // Initial index of first subarray
    i = 0;
    //Initial index of second subarray
    j = 0;

    // Initial index of Merged array
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is for right index
// of subarray of arr to be sorted

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        // Same as (l + r) / 2, but avoids overflow fo large l and h
        int m = l + (r - 1) / 2;

        // Sort first and second halfs
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to print Array
void printArray(int A[], int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%d, ",A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is :");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted Array : ");
    printArray(arr, arr_size);

    return 0;
}
