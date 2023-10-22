/******************************************************************************

                            FIND LARGEST ELEMENT IN A ARRAY
Brute force:
TC: O(n logn)
SC: O(1)
Optimal:
TC: O(n)
SC: O(1) -> no extra space used
Recursion:
TC: O(n)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

/* Brute force */
int largest_element (int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

/* Optimal */
int largest_element (int arr[], int n)
{
    int largest = arr[0];
    
    for (int i=0; i<n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

/* Recursion */
int largest_element (int arr[], int i, int largest, int n)
{
    if (i == n)
        return largest;
    if (arr[i] > largest)
        largest = arr[i];
    return largest_element (arr, i+1, largest, n);
}


int main()
{
    int arr[] = {10, 22, 12, 11, 15, 8, 20, 30, 12};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << largest_element (arr, 0, arr[0], n) << endl;

    return 0;
}

