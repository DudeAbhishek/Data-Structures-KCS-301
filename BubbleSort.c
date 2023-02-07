// 11. Write a program to sort an unsorted array of elements by Bubble Sort.

#include <stdio.h>
#include <conio.h>

void printArr(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("\t%d,", a[i]);
}

void bubble(int a[], int n)
{
    int i,j,temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]<a[j])
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

int main()
{
    int a[] = {63,85,42,98,3,19,27};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n\n\n\tBefore sorting array elements are:\n");
    printArr(a,n);
    bubble(a,n);
    printf("\n\n\tAfter Bubble Sorting array elements are:\n");
    printArr(a,n);

    printf("\n\n\n\n");
    getch();
    return 0;
}
