/******************************************************************************

                            REMOVE DUPLICATES IN A SORTED ARRAY
TC: O(n)
SC: O(1) -> no extra space
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;


/* Optimal */
void remove_dups (int arr[], int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        while (arr[j] == arr[j-1])
        {
            j++;
        }
        if ((j < n) && (arr[j] != arr[j-1]))
        {
            arr[i+1] = arr[j];
            i++;
        }
        j++;
    }
}

int main()
{
    int arr[] = {2, 7, 7, 7, 8, 8, 9, 9, 10, 10};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    remove_dups (arr, n);

    for (int x=0; x<n; x++)
    {
        cout << arr[x] << " ";
    }

    return 0;
}