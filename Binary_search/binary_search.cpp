/******************************************************************************
 * 
 *                      Binary search
 * TC: O(log n)
 * SC: O(1)
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int binary_search (vector<int> arr, int key)
{
    int l, m, h;
    l = 0;
    h = arr.size()-1;
    while (l <= h)
    {
        m = (l + h)/2;
        if (arr[m] == key)
        {
            return m;
        }
        else if (arr[m] > key)
        {
            h = m-1;
        }
        else if (arr[m] < key)
        {
            l = m+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {20, 20, 20, 25, 25, 25, 30, 50, 55, 55, 60};
    int key;
    cin >> key;
    cout << binary_search (arr, key) << endl;
    return 0;
}