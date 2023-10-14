/******************************************************************************

                                QUICK SORT

*******************************************************************************/

#include <iostream>

using namespace std;

int partition (int l, int h, int arr[])
{
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j)
    {
        while ((i <= h) && (arr[i] <= pivot))
        {
            i++;
        }
        while ((j >= i) && (arr[j] > pivot))
        {
            j--;
        }
        if (i<j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

void quick_sort (int l, int h, int arr[])
{
    if (l < h)
    {
        int pIndex = partition(l, h, arr);
        quick_sort(l, pIndex-1, arr);
        quick_sort(pIndex+1, h, arr);
    }
}

int main()
{
    int arr[] = {20, 5, -1, 20, 11, 12, 15, 9, 2, -20};
    int n = sizeof(arr)/sizeof(int);
    
    quick_sort (0, n-1, arr);
    
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}