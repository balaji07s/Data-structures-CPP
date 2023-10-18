/******************************************************************************

                                Linear search
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>

using namespace std;

int linear_search (int arr[], int n, int s)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i] == s)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s;
    cin >> s;
    cout << "Element found at index: "<< linear_search (arr, n, s) << endl;

    return 0;
}
