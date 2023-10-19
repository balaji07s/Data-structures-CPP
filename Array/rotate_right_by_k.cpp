/******************************************************************************

                        Rotate array right by k elements
Brute force:
TC: O(2n)
SC: O(n)
Optimal:
TC: O(2n)
SC: O(1) -> no extra space
Algorithm:
step 1: Reverse from 0th index to n-k-1
step 2: Reverse from (n-k)th index to n
step 3: Reverse from 0th index to n
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

/* Brute force */
// void rotate_to_right_k (int arr[], int n, int k)
// {
//     int temp[n];
//     k = k%n;
    
//     for (int i=0; i<k; i++)
//     {
//         temp[i] = arr[n-k+i];
//     }
    
//     for (int i=0; i<(n-k); i++)
//     {
//         temp[k+i] = arr[i];
//     }
    
//     for (int i=0; i<n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }

/* Optimal */
void rotate_to_right_k (int arr[], int n, int k)
{
    int j, i;
    k = k % n;
    i=0;
    j=n-k-1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++; j--;
    }
    i=n-k;
    j = n-1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++; j--;
    }
    i = 0;
    j = n-1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++; j--;
    }

}

int main()
{
    int arr[] = {10, 22, 12, 11, 15, 8, 20, 30, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    rotate_to_right_k (arr, n, k);
    
    for (int x : arr)
    {
        cout << x << " ";
    }
    
    return 0;
}