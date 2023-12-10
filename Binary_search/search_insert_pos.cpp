/******************************************************************************
 * 
 *                      Lower bound
 * linear search
 * TC: O(n)
 * SC: O(1)
 * lower bound
 * TC: O(log n)
 * SC: O(1)
 * binary search
 * TC: O(log n)
 * SC: O(1)
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* Using binary search */
int searchInsert(vector<int>& arr, int key) {
    int l, m, h;
    l = 0;
    h = arr.size()-1;
    while (l <= h)
    {
        m = l + (h - l)/2;
        if (arr[m] == key)
        {
            return m;
        }
        if (arr[m] > key)
        {
            h = m-1;
        }
        else if (arr[m] < key)
        {
            l = m+1;
        }
    } 
    if (arr[m] < key)
        return m+1;
    return m;
}

/* Using linear search */
int search_insert_pos (vector<int> arr, int key)
{
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        else if (arr[i] > key)
        {
            return i;
        }
    }
    return arr.size();
}


/* Using lower bound */
int search_insert_pos (vector<int> arr, int key)
{
    int l, m, h;
    l = 0;
    h = arr.size()-1;
    long long ans = arr.size();
    while (l <= h)
    {
        m = (l + h)/2;
        if (arr[m] >= key)
        {
            h = m-1;
            ans = m;
        }
        else if (arr[m] < key)
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
    cout << lower_bound (arr, key) << endl;
    return 0;
}