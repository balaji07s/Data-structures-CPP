/******************************************************************************

                        Count sort
TC: O(n)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int find_max (vector<int> &arr)
{
    int max;
    for (int x : arr)
    {
        if (x > max)
        {
            max = x;
        }
    }
    return max;
}

void count_sort (vector<int> &arr)
{
    int maxNum = find_max(arr);
    vector<int> result(maxNum+1, 0);
    
    for (int i=0; i<arr.size(); i++)
    {
        result[arr[i]]++;
    }
    
    for (int i=0; i<result.size(); i++)
    {
        while (result[i] > 0)
        {
            cout << i << " ";
            result[i]--;
        }
    }
}

int main()
{
    vector<int> arr = {20, 14, 2, 6, 3, 10, 8, 2, 1};
    count_sort (arr);

    return 0;
}