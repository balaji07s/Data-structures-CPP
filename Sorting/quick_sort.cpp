/*
                                            QUICK SORT
Time complexity: O(n log n)
Space complexity: O(n)
*/

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition (arr, low, high);
        quickSort (arr, low, pivot-1);
        quickSort (arr, pivot+1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    int j = low-1;
    for (; i<=high-1; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[high], arr[j+1]);
    
    return j+1;
}

int main ()
{
    int arr[] = {4, 1, 3, 9, 7};
    int size = 5;

    quickSort(arr, 0, 4);
    return 0;
}