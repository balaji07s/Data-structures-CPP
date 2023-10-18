/******************************************************************************

                            MOVE ZEROS TO THE END
Optimal approach:
TC: O(n)
SC: O(1)

Brute force:
TC: O(n+k)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* brute force */
vector<int> move_zeros_to_end (int arr[], int n)
{
    vector<int> temp_arr(n, 0);
    int counter = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] != 0)
        {
            temp_arr[counter] = arr[i];
            counter++;
        }
    }
    while(counter < n)
    {
        temp_arr[counter] = 0;
        counter++;
    }
    return temp_arr;
}

/* Optimal approach */
void move_zeros_to_end (int arr[], int n)
{
    int j = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return;
}

int main()
{
    int arr[] = {5, 0, 11, 2, 0, 0, 3, 22, 0, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> res;
    move_zeros_to_end(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}