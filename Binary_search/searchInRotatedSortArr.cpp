/******************************************************************************

                    Search element in a rotated sorted array (Unique elements)
TC: O(log n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


/* Optimal solution */
int searchInARotatedSortArr (vector<int> &arr, int key)
{
        int l=0, h=arr.size()-1;
        if (arr.size() == 0)
            return -1;
        while (l <= h)
        {
            int m = l + (h - l)/2;
            if (arr[m] == key)
                return m;
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
                }
                else
                {
                    h = m - 1;
                }
            }
        }
        return -1;
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int key;
    cin >> key;
    cout << searchInARotatedSortArr (arr, key) << endl;

    return 0;
}