/******************************************************************************

                        ROTATE AN ARRAY BY ONE PLACE
TC: O(n)
SC: O(1) -> no extra space
*******************************************************************************/

#include <iostream>

using namespace std;

/* Optimal approach */
void rotate_by_one_left (int arr[], int n)
{
    int temp = arr[0];
    
    for (int i=1; i<n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main()
{
    int arr[] = {10, 22, 12, 11, 15, 8, 20, 30, 12};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    rotate_by_one_left (arr, n);
    
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}