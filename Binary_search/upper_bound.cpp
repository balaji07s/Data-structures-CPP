/******************************************************************************
 * 
 *                      Upper bound
 * linear search
 * TC: O(n)
 * SC: O(1)
 * binary search
 * TC: O(log n)
 * SC: O(1)
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Using linear search */
int upper_bound (vector<int> arr, int key)
{
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] > key)
        {
            return i;
        }
    }
    return arr.size();
}

/* Using binary search */
int upper_bound (vector<int> arr, int key)
{
    int l, m, h;
    l = 0;
    h = arr.size()-1;
    long long ans = arr.size();
    while (l <= h)
    {
        m = (l + h)/2;
        if (arr[m] > key)
        {
            h = m-1;
            ans = m; 
        }
        else if (arr[m] <= key)
        {
            l = m+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {20, 20, 20, 25, 25, 25, 30, 50, 55, 55, 60};
    int key;
    cin >> key;
    cout << upper_bound (arr, key) << endl;
    return 0;
}