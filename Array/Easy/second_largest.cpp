/******************************************************************************

                        SECOND LARGEST ELEMENT
Brute force:
TC: O(2n)
SC: O(1) -> no extra space

Optimal:
TC: O(n)
SC: O(1) -> no extra space

Recursion:
TC: O(n)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/* Brute force */
int second_largest (int arr[], int n)
{
    int largest = arr[0];
    int second_lgst = INT_MIN;
    for (int i=0; i<n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    for (int i=0; i<n; i++)
    {
        if ((arr[i] > second_lgst) && (arr[i] < largest))
        {
            second_lgst = arr[i];
        }
    }
    return second_lgst;
}

/* Optimal */
int second_largest (int arr[], int n)
{
    int largest = arr[0],
        second_lgst = INT_MIN;
    
    for (int i=0; i<n; i++)
    {
        if (arr[i] > largest)
        {
            second_lgst = largest;
            largest = arr[i];
        }
        if ((arr[i] > second_lgst) && (arr[i] < largest))
        {
            second_lgst = arr[i];
        }
    }
    return second_lgst;
}

/* Recursion */
int second_largest (int arr[], int i, int largest, int second_lgst, int n)
{
    if (i >= n)
        return second_lgst;
    if (arr[i] > largest)
    {
        second_lgst = largest;
        largest = arr[i];
    }
    if ((arr[i] > second_lgst) && (arr[i] < largest))
    {
        second_lgst = arr[i];
    }
    return second_largest (arr, i+1, largest, second_lgst, n);
}

int main()
{
    int arr[] = {10, 22, 12, 11, 15, 8, 20, 30, 12, 25};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << second_largest (arr, 0, arr[0], INT_MIN, n) << endl;

    return 0;
}
