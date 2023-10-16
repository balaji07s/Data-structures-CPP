/******************************************************************************

                              Rotate array left by k elements
Brute force:
TC: O(n+d)
SC: O(d) -> extra space
Optimal:
TC: O(n)
SC: O(1) -> no extra space
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

/* Brute force */
void rotate_by_k (int arr[], int n, int k)
{
    k = k%n;
    int temp[k] = {};
    int i = 0;
    for (; i<k; i++)
    {
        temp[i] = arr[i];
    }
    
    for (; i<n; i++)
    {
        arr[i-k] = arr[i];
    }
    
    for (int j=0; j<k; j++)
    {
        arr[i-k] = temp[j];
        i++;
    }
}

/* Optimal approach */
void rotate_by_k (int arr[], int n, int k)
{   
    k = k % n;
    int i = 0, j;
    for (; i< (k/2); i++)
    {
        swap(arr[i], arr[k-i-1]);
    }
    j = n-1;
    i = k;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++; j--;
    }
    for (i=0; i<(n/2); i++)
    {
        swap(arr[i], arr[n-i-1]);
    }
}


int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    rotate_by_k (arr, n, k);


    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}