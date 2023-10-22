/******************************************************************************

                            IS ARRAY SORTED
TC: O(n)
SC: O(1) -> no extra space
*******************************************************************************/

#include <iostream>

using namespace std;

/* Optimal */
bool isArraySorted (int arr[], int n)
{
    for (int i=1; i<n; i++)
    {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {10, 20, 30 ,40, 50, 60, 90};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << isArraySorted(arr, n) << endl;

    return 0;
}