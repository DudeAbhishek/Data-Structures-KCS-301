// 8. Write a program to search a given number by binary search.

#include <stdio.h>
#include <conio.h>

int binarySearch(int a[], int beg, int end, int val)
{
    int mid;
    if(end >= beg)
    {
        mid = (beg + end) / 2;
        if(a[mid] == val)
        {
            return mid + 1;
        }
        else if(a[mid] < val)
        {
            return binarySearch(a, mid + 1, end,  val);
        }
        else
        {
            return binarySearch(a, beg, mid - 1, val);
        }
    }
    return -1;
}

int main()
{
    int a[] = {11, 14, 25, 30, 40, 41, 52, 57, 70};
    int val;
    int n = sizeof(a)/sizeof(a[0]);

    printf("\n\n\tThe elements in the array are : ");
    for(int i=0; i<n; i++)
        printf("%d, ", a[i]);

    printf("\n\tElement to be searched : ");
    scanf("%d", &val);

    int res = binarySearch(a, 0, n - 1, val);

    if(res == -1)
        printf("\n\tElement is NOT present in the array...");
    else
        printf("\n\tElement is present at %d position of array.", res);

    printf("\n\n\n\n\n\n");
    getch();
    return 0;
}
