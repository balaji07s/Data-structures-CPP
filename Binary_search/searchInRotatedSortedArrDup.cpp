/******************************************************************************

                    Search element in a rotated sorted array (duplicates)
TC: O(log n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int searchInRotatedSortedArr (vector<int> &arr, int key)
{
    int l=0, h=arr.size()-1;
    if (arr.size() == 0)
        return -1;
    while (l <= h)
    {
        int m = l + (h - l)/2;
        if (arr[m] == key)
            return true;
        if (arr[l] == arr[m] && arr[m] == arr[h])
        {
            l = l+1;
            h = h-1;
            continue;
        }
        if (arr[l] <= arr[m])
        {
            if (arr[l] <= key && key <= arr[m])
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            if (arr[m] <= key && key <= arr[h])
            {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
    }
    return false;
}


int main ()
{
    vector<int> arr = {3, 1, 2, 3, 3, 3, 3, 3};
    int key;
    cin >> key;
    cout << searchInRotatedSortedArr(arr, key) << endl;
    
    return 0;
}