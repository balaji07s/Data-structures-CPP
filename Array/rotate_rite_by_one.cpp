/******************************************************************************

                        Rotate array towards right by one element
TC: O(n)
SC: O(1) -> no extra space
*******************************************************************************/

#include <iostream>

using namespace std;

void rotate_to_right_one (int arr[], int n)
{
    int temp = arr[n-1];
    for (int i=(n-2); i>=0; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}

int main()
{
    int arr[] = {10, 22, 12, 11, 15, 8, 20, 30, 12};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    rotate_to_right_one (arr, n);
    
    for (int x : arr)
    {
        cout << x << " ";
    }
    
    return 0;
}