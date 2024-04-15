#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify (int arr[], int i, int size)
{
    while (i < size)
    {
        int lc = 2 * i + 1;
        int rc = lc + 1;
        int maxIndex = i;
        if (lc < size && arr[lc] > arr[maxIndex])
            maxIndex = lc;
        if (rc < size && arr[rc] > arr[maxIndex])
            maxIndex = rc;
        if (maxIndex != i)
        {
            swap (&arr[maxIndex], &arr[i]);
            i = maxIndex;
        }
        else
        {
            break;
        }
    }
}

void print (int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf ("%d ", arr[i]);
    }
    printf ("\r\n");
}

int insertMinHeap (int arr[], int size, int x)
{
    if (size == 0)
    {
        arr[size] = x;
        return size+1;
    }
    int i = size;
    arr[size] = x;
    while (arr[i] < arr[(i - 1)/2])
    {
        int parent = (i-1)/2;
        swap(&arr[i], &arr[parent]);
        i = parent;
    }
    return size+1;
}

int extractMinHeap (int arr[], int size)
{
    if (size <= 0)
    {
        printf ("Heap is empty\r\n");
        return 0;
    }
    
    size--;
    int i = 0;
    swap(&arr[i], &arr[size]);
    
    while (i < size)
    {
        int lc = 2 * i + 1;
        int rc = lc + 1;
        int maxIndex = i;
        if (lc < size && arr[lc] < arr[maxIndex])
            maxIndex = lc;
        if (rc < size && arr[rc] < arr[maxIndex])
            maxIndex = rc;
        if (maxIndex != i)
        {
            swap(&arr[maxIndex], &arr[i]);
            i = maxIndex;
        }
        else
        {
            break;
        }
    }
    printf ("Removed element: %d\r\n", arr[size]);
    return size;
}

int insertMaxHeap (int arr[], int size, int x)
{
    if (size == 0)
    {
        arr[size] = x;
        return size+1;
    }
    
    int i = size;
    arr[size] = x;
    while (arr[(i-1)/2] < arr[i])
    {
        int parent = (i-1)/2;
        swap(&arr[i], &arr[parent]);
        i = parent;
    }
    return size+1;
}

int extractMaxHeap (int arr[], int size)
{
    if (size <= 0)
    {
        printf ("Heap is empty\r\n");
        return 0;
    }
    
    size--;
    int i = 0;
    swap(&arr[i], &arr[size]);
    while (i < size)
    {
        int lc = 2 * i + 1;
        int rc = lc + 1;
        int maxIndex = i;
        if (lc < size && arr[maxIndex] < arr[lc])
            maxIndex = lc;
        if (rc < size && arr[maxIndex] < arr[rc])
            maxIndex = rc;
        if (maxIndex != i)
        {
            swap(&arr[maxIndex], &arr[i]);
            i = maxIndex;
        }
        else
        {
            break;
        }
    }
    printf ("Removed element is: %d\r\n", arr[size]);
    return size;
}

int main()
{

#define HEAPIFY
#ifdef MAX_HEAP
    int arr[20] = {};
    int size = 0;
    size = insertMaxHeap(arr, size, 10);
    size = insertMaxHeap(arr, size, 20);
    size = insertMaxHeap(arr, size, 30);
    size = insertMaxHeap(arr, size, 40);
    size = insertMaxHeap(arr, size, 50);
    size = insertMaxHeap(arr, size, 60);
    size = insertMaxHeap(arr, size, 70);
    size = insertMaxHeap(arr, size, 80);
    size = insertMaxHeap(arr, size, 90);
    size = insertMaxHeap(arr, size, 100);
    
    printf ("Size %d\r\n", size);
    
    print(arr, size);
    
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
    size = extractMaxHeap(arr, size);
#endif

#ifdef MIN_HEAP
    size = insertMinHeap (arr, size, 100);
    size = insertMinHeap (arr, size, 90);
    size = insertMinHeap (arr, size, 80);
    size = insertMinHeap (arr, size, 70);
    size = insertMinHeap (arr, size, 60);
    size = insertMinHeap (arr, size, 50);
    size = insertMinHeap (arr, size, 40);
    size = insertMinHeap (arr, size, 30);
    size = insertMinHeap (arr, size, 20);
    size = insertMinHeap (arr, size, 10);
    
    printf ("Size %d\r\n", size);
    print(arr, size);
    
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);
    size = extractMinHeap (arr, size);

#endif

#ifdef HEAPIFY
    int arr[9] = {2, 8, 1, 6, 4, 3, 7, 5, 10};
    int size = 9;
    for (int i=(size/2 - 1); i >= 0; i--)
        heapify (arr, i, size);
    print(arr, size);
#endif

    return 0;
}