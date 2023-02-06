// 10. Write a program to sort an unsorted array of elements by Selection Sort.

#include <stdio.h>
#include <conio.h>

void selection(int arr[], int n)
{
    int i, j, small;

    for( i=0; i<n-1; i++)
    {
        small = i;
        for(j=i+1; j<n; j++)
            if(arr[j]<arr[small])
                small = j;

        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

void printArr(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("\t%d,", a[i]);
    }

int main()
{
    int a[] = {33,68,52,49,72,5,11,99,3};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n\n\n\tBefore sorting array elements are :\n");
    printArr(a,n);
    selection(a,n);
    printf("\n\n\tAfter Selection Sorting Array elements are :\n");
    printArr(a,n);
    printf("\n\n\n\n\n");
    getch();
    return 0;
}
