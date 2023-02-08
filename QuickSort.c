// 12. Write a program to sort an unsorted array by Quick Sort.

#include <stdio.h>
#include <conio.h>

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = (start - 1);
    for(int j=start; j<=end; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            int t =a[i];
            a[i] = a[j];
            a[j] =t;
        }
    }

    int t = a[i+1];
    a[i+1]=a[end];
    a[end] = t;
    return (i+1);
}

void printArr(int a[], int n)
{
    for( int i=0; i<n; i++)
        printf("\t%d,", a[i]);

}

void quick(int a[], int start, int end)
{
    if(start<end)
    {
        int p = partition(a,start,end);
        quick(a,start,p-1);
        quick(a,p+1,end);
    }
}


int main()
{
    int a[] = {41,8,62,48,35,72,92,7};
    int n =sizeof(a)/sizeof(a[0]);
    printf("\n\n\tBefore sorting array elements are: \n");
    printArr(a,n);
    quick(a,0,n-1);
    printf("\n\n\tAfter Quick Sorting array elements are: \n");
    printArr(a,n);
    printf("\n\n\n\n");
    getch();
    return 0;
}
