// 15. Write a program to sort an unsorted array of elements by HEAP SORT.

#include<stdio.h>
#include<conio.h>

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int arr[] = {99,61,78,81,93,7,11,29};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("\n\n\n\tBefore sorting array elements are : \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("\n\n\tAfter Heap Sorting array elements are : \n");
    printArray(arr, n);

    printf("\n\n\n\n");

    getch();

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    // Find the largest root, left & right child
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // if left child is larger than root
    if(left< n && arr[left] > arr[largest])
        largest = left;
    // if right child is larger than root
    if(right < n && arr[right] > arr[largest])
        largest = right;

// Swap and continue heapifying root in not lagest
    // if root is not largest
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main Function to do HEAP SORT
void heapSort(int arr[], int n)
{
    int i;
    // build max heap
    for(i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    // Heap Sort
    for(i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

// for printing the array
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("\t%d,", arr[i]);

}
