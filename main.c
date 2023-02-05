// 9. Write a program to sort an unsorted array of elements by using Insertion sort.

#include <stdio.h>
#include<conio.h>

void insert(int a[], int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        temp = a[i];
        j = i - 1;
        while(j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

void printArr(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("\t%d,", a[i]);
}

int main()
{
    int a[] = {59,62,73,81,22,19,2,87};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n\n\tBefore sorting array elements are: \n");
    printArr(a,n);

    insert(a,n);
    printf("\n\n\tAfter Insertion Sorting array elements are: \n");
    printArr(a,n);

    printf("\n\n\n\n\n");
    getch();

    return 0;
}



















