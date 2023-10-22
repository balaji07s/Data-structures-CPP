/******************************************************************************

                            REMOVE DUPLICATES IN A SORTED ARRAY
brute force:
TC: O(n)
SC: O(n)
Optimal:
TC: O(n)
SC: O(1) -> no extra space
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Brute force */
vector<int> remove_dups (int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int j =0;
    for (int i=1; i<n; i++)
    {
        if (temp[j] != arr[i])
        {
            temp.push_back(arr[i]);
            j++;
        }
    }
    return temp;
}

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
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> res = remove_dups (arr, n);

    for (auto x: res)
    {
        cout << x << " ";
    }
    return 0;
}