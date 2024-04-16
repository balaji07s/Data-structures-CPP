/*
                                            MERGE SORT
Time complexity: O(n log n)
Space complexity: O(n)
*/
    
void merge(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m+1;
    int k = 0;
    int temp[((r - m) + (m - l + 1))] = {};
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int k=l; k<=r; k++)
    {
        arr[k] = temp[k-l];
    }
}
public:
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}