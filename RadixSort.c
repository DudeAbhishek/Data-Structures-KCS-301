// 14. Write a program to sort an  unsorted array of elements by Radix Sort.

#include <stdio.h>
#include<conio.h>

int get_max(int a[], int n)
{
    int max = a[0];
    for(int i=1; i<n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}

void radix_sort(int a[], int n)
{
    int bucket[10][10], bucket_count[10];
    int i, j, k, r, NOP =0, divisor = 1, largest, pass;
    largest = get_max(a, n);

    while(largest > 0)
    {
        NOP++;
        largest /= 10;
    }

    for(pass = 0; pass<NOP; pass++)
    {
        for(i=0; i<10; i++)
            bucket_count[i] = 0;

        for(i=0; i<n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_count[r]] = a[i];
            bucket_count[r] += 1;
        }

        i = 0;
        for(k=0; k<10; k++)
        {
            for(j=0; j<bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }

        divisor *= 10;
        printf("\n\tAfter pass %d : ", pass +1);
        for(i=0; i<n; i++)
            printf("%d, ", a[i]);
    }
}

int main()
{
    int n, i;
    printf("\n\n\n\tEnter the no. of elements to be sorted : ");
    scanf("%d", & n);

    int a[n];
    printf("\tEnter elements : ");
    for(i=0; i<n; i++)
        scanf("%d", & a[i]);

    radix_sort(a, n);

    printf("\n\tSorted Array : ");
    for(i=0; i<n; i++)
        printf("%d, ", a[i]);

    printf("\n\n\n\n");

    return 0;
}
